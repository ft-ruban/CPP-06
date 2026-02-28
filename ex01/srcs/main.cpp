/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:33:38 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 10:34:47 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"

int main(void){
    Data d;
    Data* ptr = &d;

// Serialize ptr
    uintptr_t raw = Serializer::serialize(ptr);

// deserialize
    Data* ptr2 = Serializer::deserialize(raw);

// show content ptr raw ptr2
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;
    
    return(0);
}