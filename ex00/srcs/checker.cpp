/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:26:02 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 09:08:14 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.hpp"



static bool char_checker(std::string &representation){
    if(representation[1] || std::isdigit(representation[0]))
        return(0);
    else
        return(1);
}

static bool int_checker(std::string &representation){
    char *endptr;
    long overflow_checker = std::strtol(representation.c_str(), &endptr, 10);
    if(*endptr != '\0')
        return(0);
    if((overflow_checker == LONG_MAX || overflow_checker == LONG_MIN) && errno == ERANGE)
        return (0);
    if((overflow_checker > INT_MAX || overflow_checker < INT_MIN))
        return(0);
    return(1);
}

static bool float_checker(std::string representation){
    bool minus_pos_sign = false;
    bool dot_detected = false;

    if(representation[0] == '.')
        return(0);
    if(representation[0] == '+' || representation[0] == '-'){
        minus_pos_sign = true;
    }
    for(std::size_t i = minus_pos_sign; i < representation.size() - 1;i++){
        if(representation[i] == '.'){
            if(dot_detected == true)
                return(0);
            dot_detected = true;
        }
        else if(!std::isdigit(representation[i]))
            return(0);
    }
    if(representation[representation.size() - 1] != 'f' || !std::isdigit(representation[representation.size() - 2]) || !dot_detected){
        return(0);
    }
    return(1);
}

static bool double_checker(std::string& representation){
    bool minus_pos_sign = false;
    bool dot_detected = false;

    if(representation[0] == '.')
        return(0);
    if(representation[0] == '+' || representation[0] == '-'){
        minus_pos_sign = true;
    }
    for(std::size_t i = minus_pos_sign; i < representation.size();i++){
        if(representation[i] == '.'){
            if(dot_detected == true)
                return(0);
            dot_detected = true;
        }
        else if(!std::isdigit(representation[i]))
            return(0);
    }
    if(!dot_detected)
        return(0);
    return(1);
}

std::size_t case_checker(std::string& representation){
    
    if (!representation.compare("-inff") || !representation.compare("+inff")  
    || !representation.compare("nanf") || !representation.compare("-inf") 
    || !representation.compare("+inf")  || !representation.compare("nan"))
        return(INF_CASE);
    else if (char_checker(representation))
        return(CHAR_CASE);
    else if(int_checker(representation))
        return(INT_CASE);
    else if (float_checker(representation))
        return(FLOAT_CASE);
    else if (double_checker(representation))
        return(DOUBLE_CASE);
    else
        return(INVALID_CASE);
}