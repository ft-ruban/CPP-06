/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:03:31 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/25 11:13:40 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void printAllImpossible(){
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;
    std::cout<<"float: impossible"<<std::endl;
    std::cout<<"double: impossible"<<std::endl;
}

// 1) if the string is empty then print all impossible and exit
void ScalarConverter::convert(std::string representation){
    if (representation.empty())
        return(printAllImpossible());
    handleChar(representation);

   // if(representation)
   //then int
   //then float literals (0.0f, -4.2f, 4.2f)
   //then double literals (0.0, -4.2, 4.2)
}

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return(*this);
}

ScalarConverter::~ScalarConverter(){
}