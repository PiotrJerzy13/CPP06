/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:48 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/11 19:28:45 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data myData = {42, "Test Data"};

	std::cout << "Original Data address: " << &myData << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << ptr << std::endl;

	if (ptr == &myData)
	{
		std::cout << "Deserialization successful!\n";
		std::cout << "Data: { id: " << ptr->id << ", name: " << ptr->name << " }\n";
	}
	else
	{
		std::cout << "Deserialization failed!\n";
	}

	return 0;
}
