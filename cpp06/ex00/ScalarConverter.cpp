#include "ScalarConverter.hpp"

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
    literal == "nanf" || literal == "+inff" || literal == "-inff")
    return SPECIAL;

    if (literal.length() == 1 && !isdigit(literal[0]))
        return CHAR;

    bool hasDot = false;
    bool hasF = false;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (literal[i] == '.')
            hasDot = true;
        else if (literal[i] == 'f' && i == literal.length() - 1)
            hasF = true;
        else if (!isdigit(literal[i]) && !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            return INVALID;
    }

    if (hasDot && hasF)
        return FLOAT;
    else if (hasDot)
        return DOUBLE;
    else
        return INT;
}

void ScalarConverter::printConversions(const std::string &literal, LiteralType type)
{
    double dvalue = 0;

    try {
        switch (type)
        {
        case CHAR:
            dvalue = static_cast<double>(literal[0]);
            break;
        case INT:
            dvalue = static_cast<double>(std::stoi(literal));
            break;
        case FLOAT:
            dvalue = static_cast<double>(std::stof(literal));
            break;
        case DOUBLE:
            dvalue = std::stod(literal);
            break;
        case SPECIAL:
            if (literal.find('f') != std::string::npos)
                dvalue = std::stof(literal);
            else
                dvalue = std::stod(literal);
            break;
        default:
            std::cout << "Invalid literal" << std::endl;
            break;
        }
    } catch (...) {
        std::cout << "Conversion impossible" << std::endl;
        return;
    }

    // char 
    std::cout << "char: ";
    if (std::isnan(dvalue) || std::isinf(dvalue) || dvalue < 0 || dvalue > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(dvalue)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(dvalue) << "'" << std::endl;

    // int
    std::cout << "int: ";
    if (std::isnan(dvalue) || std::isinf(dvalue) || dvalue > INT_MAX || dvalue < INT_MIN)
         std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(dvalue) << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(dvalue) << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << dvalue << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);
    if (type == INVALID)
    {
        std::cout << "Invalid literal" << std::endl;
        return;
    }
    printConversions(literal, type);
}