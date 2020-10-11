#include <string>

class Date{
 private:
    int year, month, day;

 public:
    int ConvertToJulian(const Date &date) {
        // some intermediate coefficients (as Wikipedia says)
        int a, y, m, JulianDayNum;
        a = floor((14 - date.month) / 12);
        y = date.year + 4800 - a;
        m = date.month + 12 * a - 3;
        JulianDayNum = date.day + floor((153 * m + 2) / 5) + 365 * y
                       + floor(y / 4) - floor(y / 100)
                       + floor(y / 400) - 32045;
        return JulianDayNum;
    }

    Date(int year, int month, int day) {
        Date::day = day;
        Date::month = month;
        Date::year = year;
    }

    bool IsLeap() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    Date DaysLater(int days) {
        int Julian = ConvertToJulian(*this) + days;
        int f, e, g, h, day_grig, month_grig, year_grig;
        f = Julian + 1401 + (((4 * Julian + 274277) / 146097) * 3) / 4 - 38;
        e = 4 * f + 3;
        g = (e % 1461) / 4;
        h = 5 * g + 2;

        day_grig = (h % 153) / 5 + 1;
        month_grig = (h / 153 + 2) % 12 + 1;
        year_grig = e / 1461 - 4716 + (14 - month_grig) / 12;

        return {year_grig, month_grig, day_grig};
    }

    std::string ToString() {
        std::string day_str, month_str, year_str;

        if (day > 10) {
            day_str = std::to_string(day);
        } else {
            day_str = "0" + std::to_string(day);
        }

        if (month >= 10) {
            month_str = std::to_string(month);
        } else {
            month_str = "0" + std::to_string(month);
        }
        if (year < 10) {
            year_str = "000" + std::to_string(year);
        } else if (year < 100) {
            year_str = "00" + std::to_string(year);
        } else if (year < 1000) {
            year_str = "0" + std::to_string(year);
        } else {
            year_str = std::to_string(year);
        }

        return day_str + "." + month_str + "." + year_str;
    }
    int DaysLeft(const Date& date) {
        int NOW, THEN, Amount;
        NOW = ConvertToJulian(*this);
        THEN = ConvertToJulian(date);
        Amount = THEN - NOW;
        return Amount;
    }
};