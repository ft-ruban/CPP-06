/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:40:00 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 09:06:31 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <limits>
#include <cmath>
#include "checker.hpp"

#define CHAR_CASE 0
#define INT_CASE 1
#define FLOAT_CASE 2
#define DOUBLE_CASE 3
#define INF_CASE 4
#define INVALID_CASE 5


class ScalarConverter {
    public:
        static void convert(std::string& representation);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
};

#endif