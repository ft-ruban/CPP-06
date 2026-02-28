/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:10:21 by ldevoude          #+#    #+#             */
/*   Updated: 2026/02/28 15:02:25 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* Base::generate(void){
    switch(rand() % 3){
        case 0:
            std::cout<<"RETURN VALUE A"<<std::endl;
            return (new A());
        case 1:
            std::cout<<"RETURN VALUE B"<<std::endl;
            return (new B());
        case 2:
            std::cout<<"RETURN VALUE C"<<std::endl;
            return (new C());
    }
    return(NULL);
}

void Base::identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}



void Base::identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e) {
       // std::cout<<"test A too see if it catch : "<<e.what()<<std::endl;
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e) {
       // std::cout<<"test B too see if it catch : "<<e.what()<<std::endl;
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e) {}
}

Base::~Base(){
    
}