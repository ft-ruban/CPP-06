/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:18:02 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/25 09:58:24 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/charUtils.hpp"
#include <stdlib.h>//tomv.hpp

static void case_size_one(std::string representation){
        if(std::isprint(representation.at(0)) && !isdigit(representation.at(0)))
            std::cout<<"char: '"<<representation[0]<<"'"<<std::endl;
        else
            std::cout<<"char: Non displayable"<<std::endl;
        return;
}

static void parsing_part(std::string representation){
    bool test = false;

    if((!isdigit(representation.at(0)) && representation.at(0) != '+') ||
             (!isdigit(representation[representation.size() - 1]) && representation[representation.size() - 1] != 'f')){
        std::cout<<"char: impossible"<<std::endl;
        return;
    }
    for(std::size_t i = 1; i < representation.size() - 1; i++){
        if(representation[i] == '.'){
            if(representation[i + 1] != '0' || test == true){
                std::cout<<"char: impossible"<<std::endl;
                return;
            }
            else
                test = true;
        }
        else if(!isdigit(representation[i]) || (test == true && representation[i] != '0')){
            std::cout<<"char: impossible"<<std::endl;
            return;
        }
    }
    if(representation[representation.size() - 1] == 'f' && test != true){
        std::cout<<"char: impossible"<<std::endl;
        return;
    }
}

static void display_part(std::string representation){
    int i = std::atoi(representation.c_str()); //trycatch
    if(i < 0 || i > 255)
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(i))
        std::cout<<"char: '"<<static_cast<char>(i)<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    return;
}

void handleChar(std::string representation){
    if(representation.size()== 1)
        return(case_size_one(representation));
    else{
        parsing_part(representation);
        return(display_part(representation));
    }
}