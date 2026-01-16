/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 17:12:38 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>

// Function: Constructor - Initialize PhoneBook instance
PhoneBook::PhoneBook(void)
{
	this->activeContactCount = 0;     // Note: Start with no contacts
	this->currentContactIndex = 1;    // Note: Start at beginning of array
	std::cout << "[Constructor] PhoneBook: Welcome to the PhoneBook!" << std::endl;
}

// Function: Destructor - Clean up PhoneBook instance
PhoneBook::~PhoneBook(void)
{
	std::cout << "[Destructor] PhoneBook: Good Bye!" << std::endl;
}

int  PhoneBook::execute(void)
{
	std::string str;    // Note: Stores user input command

	// Function: Display welcome message and available commands
	std::cout << "===== PHONE BOOK =====" << std::endl;
	std::cout << "Commands: " << ADD << "," << SEARCH << "," << EXIT << "." << std::endl;

	// Function: Main program loop
	while (1)
	{
		std::cout << "Enter Command: ";
		std::getline(std::cin, str);
		
		// Note: Handle EOF and execute commands
		if (ft_resetCinOnEof(str) == "/0")
			continue;
		else if (str == ADD)
			addContact();
		else if (str == SEARCH)
			searchAndDisplayContacts();
		else if (str == EXIT)
			return (EXIT_SUCCESS);
		else
			std::cout << "Command not found. Use " << ADD << ", " << SEARCH << " or " << EXIT << "." << std::endl;
	}
	
	// Note: This code is reached only on input error
	std::cout << "Input error occurred. Exiting." << std::endl;
	return (EXIT_FAILURE);

}

// Function: Add a new contact or update existing one
void PhoneBook::addContact(void)
{
	// if (this->currentContactIndex == 0)
	// {
	// 	contact[0].setHeader();
	// 	this->currentContactIndex = 1;  // Note: Index 0 is reserved for column headers, start adding contacts from index 1
	// }

	contact[this->currentContactIndex].setContactInfo();

	if (this->activeContactCount < NUM_OF_CONTACTS)
	{
		this->activeContactCount += 1;
		std::cout << this->activeContactCount << " contacts in PhoneBook" << std::endl;
		std::cout << "PhoneBook: Contact[" << contact[currentContactIndex].getFieldValue(0) 
				 << "] added successfully" << std::endl;
	}
	else
	{
		std::cout << "PhoneBook: Contact[" << contact[currentContactIndex].getFieldValue(0) 
				 << "] replaced successfully" << std::endl;
	}

	this->currentContactIndex++;

	// Note: Reset to index 1 when exceeding NUM_OF_CONTACTS (skip index 0 as it's reserved for headers)
	if (this->currentContactIndex > NUM_OF_CONTACTS)
	{
		this->currentContactIndex = 1;
	}
}

// Function: Main search interface with table display and detail view
void PhoneBook::searchAndDisplayContacts(void)
{
	if (!activeContactCount)
	{
		std::cout << "PhoneBook: No contacts yet." << std::endl;
		return;
	}
	printContactsHeader();
	printContactsTable();
	displayContactDetails();
}

// Function: Display detailed information for a selected contact
void PhoneBook::displayContactDetails(void)
{
	// Member: Variables for input handling
	std::string id_want_to_see;
	int id;

	while (1)
	{
		// Note: Get and validate user input
		std::cout << "PhoneBook: Enter the index of the contact you want to see: ";
		std::getline(std::cin, id_want_to_see);
		if (ft_resetCinOnEof(id_want_to_see) == "/0")
			continue;

		if (ft_isNumber(id_want_to_see) == false)
		{
			std::cout << "PhoneBook: NUM ERROR: Please enter a valid number." << std::endl;
			continue;
		}

		// Note: Validate index range
		id = atoi(id_want_to_see.c_str());

		if (id < 1 || NUM_OF_CONTACTS < id || activeContactCount < id)
		{
			std::cout << "PhoneBook: RANGE ERROR Please enter a valid range of numbers, [1 - " 
					 << activeContactCount << "]" << std::endl;
			continue;
		}
		else
			break;  // Note: Valid ID entered, exit loop
	}

	// Function: Display contact details
	for (int field = 0; field < NUM_OF_FIELDS; field++)
	{
		std::cout << std::setfill (' ') << std::setw (20);
		std::cout << contact[0].getFieldValue(field) << ": " 
				 << contact[id].getFieldValue(field) << std::endl;
	}
}

// Function: Print the header row with field names
void PhoneBook::printContactsHeader(void)
{
	printRuledLine();
	printOneRow(0);    
	printRuledLine();
}

// Function: Display all contacts in tabular format
void PhoneBook::printContactsTable(void)
{
	for (int i = 1; i <= activeContactCount; i++)
		printOneRow(i);    
	printRuledLine();
}

// Function: Print a horizontal line for visual separation
void PhoneBook::printRuledLine(void)
{
	for (int field = Contact::ID; field <= (Contact::NickName + 1) * (10 + 1); field++)
		std::cout << "-";
	std::cout << std::endl;
}

// Function: Print a single row of the contacts table
void PhoneBook::printOneRow(int row)
{
	std::cout << "|";
	for (int field = Contact::ID; field <= Contact::NickName; field++)
	{
		std::cout.width(10);
		std::cout << trimString(contact[row].getFieldValue(field)) << "|";
	}
	std::cout << std::endl;
}

// Function: Truncate string to fit display width
std::string PhoneBook::trimString(std::string str)
{
	return (str.length() <= 10 ? str : str.substr(0, 9) + ".");
}
