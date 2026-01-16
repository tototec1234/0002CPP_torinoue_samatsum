/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 17:04:20 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

// Member: Static counter for all Contact instances
int Contact::contactCount = 0;

// Member: Column headers for contact fields
const std::string Contact::column_header[] = {
	"Index",
	"First Name",
	"Last Name", 
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

// Function: Default constructor - initializes a new Contact instance
Contact::Contact(void) : contactId(0)
{
	contactId +=  contactCount++;  // Note: Increment after assignment
	std::cout << "[Constructor] Contact: Set contact[" << contactId << "] at address[" << this << "]" << std::endl;
	if (contactId == 0) // Note: If this is Contact[0], set headers
		setHeader();
}

// Function: Destructor - cleans up Contact instance
Contact::~Contact(void)
{
	std::cout << "[Destructor] Contact: Deleted contact[" << contactId << "] at address[" << this << "]" << std::endl;
}

// Function: Returns the value of a specific field
std::string Contact::getFieldValue(int fieldIndex)
{
	return fieldValues[fieldIndex];
}

// Function: Sets all field values for this contact through user input
void Contact::setContactInfo(void)
{
	
	std::stringstream ss;
	ss << contactId;
	fieldValues[0] = ss.str();  // Note: Set ID as first field
	
	for (int field = FirstName; field < NUM_OF_FIELDS; field++)
	{
		std::string input;
		while (1)
		{
			// Note: Input validation loop
			std::cout << column_header[field] << ": ";
			std::getline(std::cin, input);
			if (ft_resetCinOnEof(input) == "/0")
				continue;
			if (input.empty())
			{
				std::cout << "Contact: can't have empty fields" << std::endl;
				continue;
			}
			
			// Note: Check for non-printable characters
			bool hasNonPrintable = false;
			for (size_t j = 0; j < input.length(); j++) 
			{
				char c = input[j];
				if (!std::isprint(c) && c != ' ') 
				{
					hasNonPrintable = true;
					break;
				}
			}
			if (hasNonPrintable) 
			{
				std::cout << "Contact: can't have non-printable characters." << std::endl;
				continue;
			}
			break;  // Note: Exit loop when input is valid
		}
		updateFieldValue(field, input);
		std::cout << "Contact: Set[" << contactId << "] " << column_header[field] 
				  << " = " << input << std::endl;
	}
}

// Function: Sets all fields to their corresponding column headers
void Contact::setHeader(void)
{
	for (int field = ID; field < NUM_OF_FIELDS; field++)
	{
		fieldValues[field] = column_header[field];  // Note: Copy header values to fieldValues
		std::cout << "Contact: Constructor is running - Set header[" << field << "] = " << column_header[field] << std::endl;
	}
		
}

// Function: Updates the value of a specific field
void Contact::updateFieldValue(int fieldIndex, std::string setvalue)
{
	fieldValues[fieldIndex] = setvalue;
}
