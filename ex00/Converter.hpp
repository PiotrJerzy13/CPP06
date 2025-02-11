/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:07 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 18:15:45 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <optional>
#include <cctype>
#include <array>

class Converter
{
public:
    static void converter(const std::string &literal);

private:
    [[nodiscard]] static std::optional<char> parseChar(const std::string &literal);
    [[nodiscard]] static std::optional<int> parseInt(const std::string &literal);
    [[nodiscard]] static std::optional<float> parseFloat(const std::string &literal);
    [[nodiscard]] static std::optional<double> parseDouble(const std::string &literal);

    static void printChar(std::optional<char> c);
    static void printInt(std::optional<int> i);
    static void printFloat(std::optional<float> f);
    static void printDouble(std::optional<double> d);
};

#endif

