class PrimeNumberGenerator {
    int first_prime;

 public:
    explicit PrimeNumberGenerator(int start) {
        this->first_prime = start;
    }

    int GetNextPrime() {
        if (!isPrime(first_prime)) {
            next_prime = first_prime;
            first_prime++;
            return (next_prime);
        } else {
            first_prime++;
            GetNextPrime();
        }
        return next_prime;
    }

 private:
    int next_prime = 0;

    static bool isPrime(int number) {
        if (number > 1) {
            for (int i = 2; i < number;) {
                if (number % i == 0)
                    return true;
                else
                    i++;
            }
        } else {
            return true;
        }
        return false;
    }
};