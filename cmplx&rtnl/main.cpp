#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ComplexNums.h"

// rational nums

rationalNumClass<int> rt1 (6, 8);
rationalNumClass<int> rt2 (-3, -7);
rationalNumClass<int> rt3 (7, 8);
rationalNumClass<int> rt4 (9, 16);
rationalNumClass<int> rt5 (8, 3);
rationalNumClass<int> rt6 (10, 101);
rationalNumClass<int> rt7 (88, 91);

// +/+=
rationalNumClass<int>plus = rt1.operator+(rt2);
rationalNumClass<int>plusequal = rt3.operator+=(rt3);

// -/-=/ NUM = - NUM
rationalNumClass<int>minus = rt1.operator-(rt2);
rationalNumClass<int>minusequal = rt4.operator-=(rt4);
rationalNumClass<int>opposite = rt5.operator-();

// */*=
rationalNumClass<int>multy = rt1.operator*(rt2);
rationalNumClass<int>multyequal = rt6.operator*=(rt6);
// / и /=
rationalNumClass<int>divide = rt1.operator/(rt2);
rationalNumClass<int>divideequal = rt7.operator/=(rt7);

//complex nums
complexNumClass<int>cmp1 (1);
complexNumClass<int>cmp2 (5);
complexNumClass<int>cmp3();
complexNumClass<int>cmp4 (-1);


complexNumClass<int>cmpPlusEqual = cmp1.operator+=(cmp1);
complexNumClass<int>cmpPlus = cmp1.operator+(cmp2);

complexNumClass<int>cmpMinusEqual = cmp1.operator-=(cmp1);
complexNumClass<int>cmpMinus = cmp1.operator-(cmp2);
complexNumClass<int>cmpOpposite = cmp1.operator-();

complexNumClass<int>Mylty = cmp4.operator*(cmp4);
complexNumClass<int>MyltyEqual = cmp1.operator*=(cmp1);

complexNumClass<int>Division = cmp1.operator/(cmp2);
complexNumClass<int>DivisionEqual = cmp1.operator/=(cmp2);

complexNumClass<int>Pows = cmp1.Pow(2);
complexNumClass<int>Abs = cmp1.Abs();
complexNumClass<int>Args = cmp1.Arg();

//TEST-CASES FOR RATIONALS

//kinda normal operations

TEST_CASE("Num&Den", "[rationalNums]") {
  REQUIRE(rt1.getterNum() == 3);
  REQUIRE(rt2.getterNum() == 3);
  REQUIRE(rt1.getterDen() == 4);
  REQUIRE(rt2.getterDen() == 7);
}

TEST_CASE("Plus (+=/+)", "[rationals]"){
  REQUIRE(plus.getterNum() == 33);
  REQUIRE(plus.getterDen() == 28);
  REQUIRE(plusequal.getterNum() == 7);
  REQUIRE(plusequal.getterDen() == 4);
};

TEST_CASE("Minus (-=/-/-a)", "[rationals]"){
  REQUIRE(minus.getterNum() == 9);
  REQUIRE(minus.getterDen() == 28);
  REQUIRE(minusequal.getterNum() == 0);
  REQUIRE(minusequal.getterDen() == 1);
  REQUIRE(opposite.getterNum() == -8);
  REQUIRE(opposite.getterDen() == 3);
};

TEST_CASE("Multy (*/*=)", "[rational]"){
  REQUIRE(multy.getterNum() == 9);
  REQUIRE(multy.getterDen() == 28);
  REQUIRE(multyequal.getterNum() == 100);
  REQUIRE(multyequal.getterDen() == 10201);
};

TEST_CASE("Divide (/ /=)", "[rational]"){
  REQUIRE(divide.getterNum() == 7);
  REQUIRE(divide.getterDen() == 4);
  REQUIRE(divideequal.getterNum() == 1);
  REQUIRE(divideequal.getterDen() == 1);
}
TEST_CASE("Equality", "[rational]"){
  REQUIRE(rt1.operator=(rt1) == rationalNumClass<int>(3, 4));
};

// boolean operators

TEST_CASE("Boolean", "[rational]"){
  REQUIRE(rt2.operator==(rt1) == false);
  REQUIRE(rt1.operator>(rt2) == true);
  REQUIRE(rt2.operator<(rt1) == true);
  REQUIRE(rt1.operator!=(rt2) == true);
  REQUIRE(rt1.operator>=(rt1) == true);
  REQUIRE(rt2.operator<=(rt2) == true);
};

//other stuff

TEST_CASE("Other", "[rational]"){
  REQUIRE(rt1.toDouble() == 0.75);
  REQUIRE(std::cout << rt1);
}

//TEST-CASES FOR COMPLEX

TEST_CASE("Setter&Getter", "[complex]"){
  cmp1.setterReal(rt1);
  cmp2.setterReal(rt4);
  cmp1.setterImage(rt4);
  cmp2.setterImage(rt1);
  REQUIRE(cmp1.getterReal() == rt1);
  REQUIRE(cmp2.getterReal() == rt4);
  REQUIRE(cmp1.getterImage() == rt4);
  REQUIRE(cmp2.getterImage() == rt1);
}

TEST_CASE("Plus (+/+=)", "[complex]"){
  REQUIRE(cmpPlusEqual.getterReal() == rationalNumClass<int> (2,1));
  REQUIRE(cmpPlus.getterReal() == rationalNumClass<int>(7,1));
}

TEST_CASE("Minus (-=/-/-b)", "[complex]"){
  REQUIRE(cmpMinusEqual.getterReal() == 0);
  REQUIRE(cmpMinus.getterReal() == rationalNumClass<int>(-5,1));
  REQUIRE(cmpOpposite.getterReal() == rationalNumClass<int>(0, 1));
};

TEST_CASE("Multyr (*=/*)", "[complex]"){
  REQUIRE(Mylty.getterReal() == rationalNumClass<int> (1,1));
  REQUIRE(MyltyEqual.getterReal() == rationalNumClass<int> (0,1));
};

TEST_CASE("Divider (/= /)", "[complex]"){
  REQUIRE(Division.getterReal() == rationalNumClass<int> (0,1));
  REQUIRE(DivisionEqual.getterReal() == rationalNumClass<int> (0,1));
}

TEST_CASE("Equal", "[complex]"){
  REQUIRE(cmp2.operator=(cmp2) == cmp2);
};

// boolean operations

TEST_CASE("Bool", "[complex]"){
  REQUIRE(cmp1.operator==(cmp1) == true);
  REQUIRE(cmp2.operator!=(cmp2) == false);
};

//other stuff
TEST_CASE("Others", "[complex]"){
  REQUIRE(Pows.getterReal() == rationalNumClass<int>(0,1));
  REQUIRE(Abs.getterReal() == rationalNumClass<int>(0,1));
  REQUIRE(Args.getterReal() == rationalNumClass<int>(0,1));
  std::cout << cmp2;
};