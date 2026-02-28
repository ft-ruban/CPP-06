/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:03:31 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 09:06:26 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


static void printAllImpossible(){
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;
    std::cout<<"float: impossible"<<std::endl;
    std::cout<<"double: impossible"<<std::endl;
}

static void char_convertor(char to_convert){
    if(std::isprint(to_convert))
        std::cout<<"char: '"<<to_convert<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    std::cout<<"int: "<<static_cast<int>(to_convert)<<std::endl;
    std::cout<<"float: "<<static_cast<float>(to_convert)<<".0f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(to_convert)<<".0"<<std::endl;
}

static void int_convertor(int to_convert){
    if(to_convert < 0 || to_convert > 127)
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(static_cast<char>(to_convert)))
        std::cout<<"char: '"<<static_cast<char>(to_convert)<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    std::cout<<"int: "<<to_convert<<std::endl;
    std::cout<<"float: "<<static_cast<float>(to_convert)<<".0f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(to_convert)<<".0"<<std::endl;
}

static void float_double_convertor(float to_convert){
    if(std::isnan(to_convert)){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }
    //CHAR PART
    if(to_convert < 0 || to_convert > 127)
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(static_cast<char>(to_convert)))
        std::cout<<"char: '"<<static_cast<char>(to_convert)<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;

    //INT PART
    if(to_convert > std::numeric_limits<int>::max()||
        to_convert<std::numeric_limits<int>::min())
            std::cout<<"int: impossible\n";
    else
        std::cout<<"int: "<<static_cast<int>(to_convert)<<std::endl;

    //FLOAT PART
    std::cout<<"float: "<<to_convert;
    if(to_convert == static_cast<int>(to_convert))
        std::cout<<".0";
    std::cout<<"f"<<std::endl;

    //DOUBLE PART
    std::cout<<"double: "<<static_cast<double>(to_convert);
    if(static_cast<double>(to_convert) == static_cast<int>(to_convert))
        std::cout<<".0";
    std::cout<<std::endl;
}

static void infinite_convertor(std::string& representation){
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;

    if(representation[0] == '+'){
        std::cout<<"float: inff"<<std::endl;
        std::cout<<"double: inf"<<std::endl;
    }
    else if(representation[0] == '-'){
        std::cout<<"float: -inff"<<std::endl;
        std::cout<<"double: -inf"<<std::endl;
    }
    else{
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
    }
}

void ScalarConverter::convert(std::string& representation){
    if (representation.empty()) // TODO rajouter des cas d'erreur generaux tel que x.f ou x.? ou xf
        return(printAllImpossible());
    switch (case_checker(representation)){
        case CHAR_CASE:
            char_convertor(representation[0]);
            break;
        case INT_CASE:
            int_convertor(std::atoi(representation.c_str()));
            break;
        case FLOAT_CASE:
            float_double_convertor(atof(representation.c_str()));
            break;
        case DOUBLE_CASE:
            float_double_convertor(atof(representation.c_str()));
            break;
        case INF_CASE:
            infinite_convertor(representation);
            break;
        case INVALID_CASE:
            printAllImpossible();
            break;
    }
    
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