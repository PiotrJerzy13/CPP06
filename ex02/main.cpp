/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:40:19 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 19:40:30 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
    Base* instance = generate();

    std::cout << "Identifying using pointer: ";
    identify(instance);

    std::cout << "Identifying using reference: ";
    identify(*instance);

    delete instance;
    return 0;
}
