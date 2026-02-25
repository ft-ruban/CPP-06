/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:18:02 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/25 10:32:44 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/charUtils.hpp"

static void case_size_one(const std::string& representation){
        if(std::isprint(representation.at(0)) && !isdigit(representation.at(0)))
            std::cout<<"char: '"<<representation[0]<<"'"<<std::endl;
        else
            std::cout<<"char: Non displayable"<<std::endl;
        return;
}

static bool parsing_part(const std::string& representation){
    bool test = false;

    if((!isdigit(representation.at(0)) && representation.at(0) != '+') ||
             (!isdigit(representation[representation.size() - 1]) && representation[representation.size() - 1] != 'f')){
        std::cout<<"char: impossible"<<std::endl;
        return(IMPOSSIBLE);
    }
    for(std::size_t i = 1; i < representation.size() - 1; i++){
        if(representation[i] == '.'){
            if(i + 1 >= representation.size() - 1 || representation[i + 1] != '0' || test){
                std::cout<<"char: impossible"<<std::endl;
                return(IMPOSSIBLE);
            }
            else
                test = true;
        }
        else if(!isdigit(representation[i]) || (test == true && representation[i] != '0')){
            std::cout<<"char: impossible"<<std::endl;
            return(IMPOSSIBLE);
        }
    }
    if(representation[representation.size() - 1] == 'f' && test != true){
        std::cout<<"char: impossible"<<std::endl;
        return(IMPOSSIBLE);
    }
    return(POSSIBLE);
}

static void display_part(const std::string& representation){
    int i = std::atoi(representation.c_str());
    if(i < 0 || i > 127)
        std::cout<<"char: impossible"<<std::endl;
    else if(std::isprint(i))
        std::cout<<"char: '"<<static_cast<char>(i)<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    return;
}

void handleChar(const std::string& representation){
    if(representation.size()== 1)
        case_size_one(representation);
    else{
        if(parsing_part(representation) == POSSIBLE)
            display_part(representation);
    }
    return;
}