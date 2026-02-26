/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:58:26 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/25 15:47:17 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intUtils.hpp"
#include <limits.h>

static bool check_zero_case(std::string& representation){
    size_t i = 0;

    if(representation[0] == '-' || representation[0] == '+')
        i = 1;
    if(representation[i] == '0'){
            while(representation[i] == '0'){
                i++;
                if(representation[i] == '.'){
                    i++;
                    std::cout<<representation[i]<<std::endl;
                    while(representation[i] == '0')
                        i++;
                    if((representation[i] && representation[i] != 'f') 
                        || (representation[i] == 'f' && representation[i+1])){
                        std::cout<<"int: impossible"<<std::endl;
                        return(FINISHED);
                    }
                    if(representation[i] == 'f')
                        i++;
                }
            }
            std::cout<<"size = " << representation.size() << " i = "<<i<<std::endl;
            if(i == representation.size()){
                std::cout<<"int: 0"<<std::endl;
                return(FINISHED);
            } 
        }
        return(UNFINISHED);
}

static bool check_negative_one(std::string& representation){
    size_t i = 3;

    if(representation[0] == '-' && representation[1] == '1'){
        if(representation[2] == '.' && representation[3]){
            while(representation[i] && representation[i] == '0'){
                i++;
            }
            if((representation[i] && representation[i] != 'f')
                || (representation[i] == 'f' && representation[i+1])){
                std::cout<<"int: impossible"<<std::endl;
                return(FINISHED);
            }
            std::cout<<"int: -1"<<std::endl;
            return(FINISHED);
        }
        if(!representation[2]){
            std::cout<<"int: -1"<<std::endl;
            return(FINISHED);
        }
    }
    return(UNFINISHED);
}

void handleInt(std::string& representation){
    if(check_zero_case(representation) == FINISHED){
        std::cout<<"TODL FINISHED"<<std::endl;
        return;
    }
    if(check_negative_one(representation) == FINISHED){
        std::cout<<"TODL NEGATIVE FINISHED"<<std::endl;
        return;   
    }
    int test = std::atoi(representation.c_str());
    if(test == 0 || test == -1)
        std::cout<<"int: impossible"<<std::endl;
    else
        std::cout<<"int: "<<test<<std::endl;
}