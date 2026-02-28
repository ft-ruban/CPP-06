/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:36:34 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 15:04:50 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../includes/Base.hpp"


int main(void){
    srand(time(0));
    Base* a;
    Base* b;
    
    a = Base::generate();
    Base::identify(a);
    Base::identify(*a);

    std::cout<<std::endl<<std::endl;
    b = Base::generate();
    Base::identify(b);
    Base::identify(*b);

    delete(b);
    delete(a);

    return(0);
}