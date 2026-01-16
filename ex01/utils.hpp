/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 16:17:11 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>

// Function: Handle EOF and reset input stream
std::string ft_resetCinOnEof(std::string str);
// Function: Check if a string represents a valid number
bool ft_isNumber(const std::string& id_want_to_see);

#endif