/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:34:06 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 09:13:59 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScalarConverter.hpp"

// //char: 'a'
//         'z'
//         '127'

// int    '0'
//        '42'
//        '-42'
//        '2147483647'
//        '2147483648'
//        '-2147483648'
//        '-2147483649'

// float   '0.0f'
//         '42.42f'
//         '-42.42f'
//         'nanf'
//         '+inff/-inff'

// double ^ without f

// other 'a string'

int main(int argc, char *argv[]){
    if(argc != 2)
        return(1);
    std::string argument_converted_to_string = argv[1];
    ScalarConverter::convert(argument_converted_to_string);
    return(0);
}