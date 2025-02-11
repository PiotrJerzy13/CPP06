/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:27:17 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 19:28:36 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data
{
	int id;
	std::string name;
};

class Serializer
{
public:
	Serializer() = delete;
	~Serializer() = delete;

	[[nodiscard]] static uintptr_t serialize(Data* ptr);
	[[nodiscard]] static Data* deserialize(uintptr_t raw);
};

#endif
