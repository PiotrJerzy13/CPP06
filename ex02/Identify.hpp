/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:37:41 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 19:39:23 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <random>

class Base
{
public:
    virtual ~Base() = default;
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

[[nodiscard]] Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
