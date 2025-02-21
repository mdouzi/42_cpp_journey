/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:48 by mdouzi            #+#    #+#             */
/*   Updated: 2024/01/21 03:31:44 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base { public: virtual ~Base() {}};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {
    Base* res;

    switch (std::rand() % 3) {
        case 0:
            res = new A();
            break;
        case 1:
            res = new B();
            break;
        case 2:
            res = new C();
            break;
        default:
            res = new A();
    }
    return res;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
	try
	{
       // std::cout << "identify ref called" << std::endl;
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Erorr :" << e.what() << std::endl;
	}
}

int main(void) {
    Base* obj = generate();
    Base* obj1 = generate();

    std::cout << "POINTER EX" << std::endl;
    identify(obj);
    identify(obj1);

    std::cout << "REFRENCE EX" << std::endl;
    identify(*obj);
    identify(*obj1);

    delete obj;
    delete obj1;
    return 0;
}

