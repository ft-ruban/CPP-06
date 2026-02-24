/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:03:31 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/24 08:57:21 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void printAllImpossible(){
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;
    std::cout<<"float: impossible"<<std::endl;
    std::cout<<"double: impossible"<<std::endl;
}

    //deal with CHAR 'c' 'a'
    //TODO check if displayable or not and /or is impossible
static void handleChar(std::string representation, std::size_t representation_size){
    char c = representation[0];
    char last_char_representation = representation[representation_size-1];
    bool test = false;

    if(representation_size == 1){
        if(isdigit(c))
            c -= 48;
        if(std::isprint(c))
            std::cout<<"char: "<<representation[0]<<std::endl;
        else
            std::cout<<"char: Non displayable"<<std::endl;
        }
    else{
        std::cout<<last_char_representation<<std::endl; //todl
        if((!isdigit(c) && c != '+') || (!isdigit(last_char_representation) && last_char_representation != 'f')){
            std::cout<<"char: impossible"<<std::endl;
            return;
        }
        for(std::size_t i = 1; i < representation_size - 1; i++){
            std::cout<<i<<std::endl;//todl
            if(representation[i] == '.'){
                if(test == true){
                    std::cout<<"char: impossible"<<std::endl;
                    return;
                }
                else
                    test = true;
            }
            else if(!isdigit(representation[i])){
                std::cout<<"char: impossible"<<std::endl;
                return;
            }
        }
        if(test = true)
    }
}

// 1) if the string is empty then print all impossible and exit
void ScalarConverter::convert(std::string representation){
    if (representation.empty())
        return(printAllImpossible());
    handleChar(representation, representation.size());

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