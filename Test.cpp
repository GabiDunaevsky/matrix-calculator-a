#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "doctest.h"
#include "Matrix.hpp"


using namespace std;
using namespace zich;

std:: vector<double> arr1 = {2,5,8,4,3,7,85,3};

TEST_CASE("checking size correctnes"){
    CHECK_THROWS(Matrix(arr1,3,5));
    CHECK_THROWS(Matrix(arr1,5,3));
    CHECK_THROWS(Matrix(arr1,-1,3));
    CHECK_THROWS(Matrix(arr1,3,-1));
    CHECK_THROWS(Matrix(arr1,-3,-1));
    CHECK_THROWS(Matrix(arr1,-2,-4));
};
std:: vector<double> arr2 = {2,5,13,45};
TEST_CASE("checking multipl correctnes"){
    Matrix m1 = Matrix(arr1,2,4);
    Matrix m2= Matrix(arr2,2,2);
    CHECK_THROWS(m1*m2);
};
TEST_CASE("checking good matrix"){
    Matrix m = Matrix(arr2,2,2);
    Matrix m1 = Matrix(arr1,2,4);
    std::stringstream test;
    test << m;
    CHECK(test.str() == "[2 5]\n[13 45]");
    test.str(std::string());
    test <<(-m);
    CHECK(test.str() == "[-2 -5]\n[-13 -45]");
    test.str(std::string());
    test << m1;
    CHECK(test.str() == "[2 5 8 4]\n[3 7 85 3]");
    test.str(std::string());
}
std:: vector<double> arr3 = {1,0,0,1};
TEST_CASE("checking some operators"){
    Matrix m = Matrix(arr2,2,2);
    Matrix i = Matrix(arr3,2,2);
    Matrix mul = m*i;
    Matrix addi = m+i;
    Matrix subm = m-i;
    Matrix smult = 2*m;
    std::stringstream test;
    test << mul;
    CHECK(test.str() == "[2 5]\n[13 45]");
    test.str(std::string());
    test << addi;
    CHECK(test.str() == "[3 5]\n[13 46]");
    test.str(std::string());
    test << subm;
    CHECK(test.str() == "[1 5]\n[13 44]");
    test.str(std::string());
    test << smult;
    CHECK(test.str() == "[4 10]\n[26 90]");
    test.str(std::string());
    m++;
    test << m;
    CHECK(test.str() == "[3 6]\n[14 46]");
    test.str(std::string());
    m--;
    test << m;
    CHECK(test.str() == "[2 5]\n[13 45]");
    test.str(std::string());
    CHECK_FALSE(!(mul > i));
    CHECK_FALSE(mul > i);
    Matrix m3 = Matrix(arr1,2,4);
    CHECK_THROWS(bool result = m > m3);
    CHECK_THROWS(bool result = m3 > m);
}







    