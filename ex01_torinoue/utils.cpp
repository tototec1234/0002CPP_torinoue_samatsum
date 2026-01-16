/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 17:17:46 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cstdio>

// Function: Handle EOF and reset input stream
std::string ft_resetCinOnEof(std::string str)
{
	if (std::cin.eof())
	{
		// Note: Reset input stream state
		std::cin.clear();          // Clear EOF flag
		std::clearerr(stdin);      // Clear C standard library stream error

		// Note: Inform user of EOF detection
		std::cout << std::endl;
		std::cout << "EOF detected" << std::endl;
		std::cout << "Input canceled. Please try again." << std::endl;
		return ("/0");
	}
	return (str);
}
bool ft_isNumber(const std::string& str)
{
	bool isNumber = true;
		for (size_t j = 0; j < str.length(); j++)
		{
			char c = str[j];
			if (!std::isdigit(c))
			{
				isNumber = false;
				break;
			}
		}
	return isNumber;
}
		
