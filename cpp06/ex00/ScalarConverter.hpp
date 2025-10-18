#pragma once
#include <iostream>

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter
{
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter();
    ~ScalarConverter();

    enum LiteralType { CHAR, INT, FLOAT, DOUBLE, SPECIAL, INVALID };

    static LiteralType detectType(const std::string &literal);
    static void printConversions(const std::string &literal, LiteralType type);
};