/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:34:06 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/24 06:58:14 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ScalarConverter.hpp"
//TODO faire une batterie de tests

int main(int argc, char *argv[]){
    if(argc != 2)
        return(1);
    std::string argument_converted = argv[1];
    ScalarConverter::convert(argument_converted);
    return(0);
}