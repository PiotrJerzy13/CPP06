/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:12 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 18:07:46 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

[[nodiscard]] std::optional<char> Converter ::parseChar(const std::string &literal)
{
    return (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'') 
        ? std::optional<char>(literal[1]) 
        : std::nullopt;
}

[[nodiscard]] std::optional<int> Converter ::parseInt(const std::string &literal)
{
    if (literal.empty() || (literal.size() > 1 && literal[0] == '-' && !std::isdigit(literal[1])))
        return std::nullopt;
    
    std::stringstream ss(literal);
    int value;
    ss >> value;
    return (ss.eof() && !ss.fail()) ? std::optional<int>(value) : std::nullopt;
}

[[nodiscard]] std::optional<float> Converter ::parseFloat(const std::string &literal)
{
    constexpr std::array<const char*, 3> specialFloats = {"-inff", "+inff", "nanf"};
    
    if (std::find(specialFloats.begin(), specialFloats.end(), literal) != specialFloats.end())
        return std::optional<float>(std::stof(literal));

    if (literal.back() != 'f')
        return std::nullopt;
    
    std::stringstream ss(literal);
    float value;
    ss >> value;

    return (ss.eof() && !ss.fail()) ? std::optional<float>(value) : std::nullopt;
}

[[nodiscard]] std::optional<double> Converter::parseDouble(const std::string &literal)
{
    constexpr std::array<const char*, 3> specialDoubles = {"-inf", "+inf", "nan"};
    
    if (std::find(specialDoubles.begin(), specialDoubles.end(), literal) != specialDoubles.end())
        return std::optional<double>(std::stod(literal));

    std::stringstream ss(literal);
    double value;
    ss >> value;
    return (ss.eof() && !ss.fail()) ? std::optional<double>(value) : std::nullopt;
}

void Converter::converter(const std::string &literal)
{
    auto c = parseChar(literal);
    auto i = parseInt(literal);
    auto f = parseFloat(literal);
    auto d = parseDouble(literal);

    if (c)
	{
        printChar(c);
        printInt(static_cast<int>(*c));
        printFloat(static_cast<float>(*c));
        printDouble(static_cast<double>(*c));
        return;
    }

    if (i)
	{
        printChar(static_cast<char>(*i));
        printInt(*i);
        printFloat(static_cast<float>(*i));
        printDouble(static_cast<double>(*i));
        return;
    }

    if (f)
	{
        printChar(static_cast<char>(*f));
        printInt(static_cast<int>(*f));
        printFloat(*f);
        printDouble(static_cast<double>(*f));
        return;
    }

    if (d)
	{
        printChar(static_cast<char>(*d));
        printInt(static_cast<int>(*d));
        printFloat(static_cast<float>(*d));
        printDouble(*d);
        return;
    }

    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

void Converter::printChar(std::optional<char> c)
{
    if (c && std::isprint(*c))
        std::cout << "char: '" << *c << "'\n";
    else
        std::cout << "char: Non displayable\n";
}

void Converter::printInt(std::optional<int> i)
{
    if (i)
        std::cout << "int: " << *i << "\n";
    else
        std::cout << "int: impossible\n";
}

void Converter::printFloat(std::optional<float> f)
{
    if (f)
        std::cout << std::fixed << std::setprecision(1) << "float: " << *f << "f\n";
    else
        std::cout << "float: impossible\n";
}

void Converter::printDouble(std::optional<double> d)
{
    if (d)
        std::cout << std::fixed << std::setprecision(1) << "double: " << *d << "\n";
    else
        std::cout << "double: impossible\n";
}
