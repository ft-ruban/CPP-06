/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 09:37:13 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 10:22:00 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t return_value = reinterpret_cast<uintptr_t>(ptr);
    return(return_value);
}

Data* Serializer::deserialize(uintptr_t raw){
    Data* return_value = reinterpret_cast<Data*>(raw);
    return(return_value);
}

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer &other){
    (void) other;
}

Serializer &Serializer::operator=(const Serializer &other){
    (void) other;
    return(*this);
}

Serializer::~Serializer(){
}
