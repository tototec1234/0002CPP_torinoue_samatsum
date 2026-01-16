/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 17:12:38 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdlib>
# include <stdlib.h>
# include "Contact.hpp"


#ifndef NUM_OF_CONTACTS
# define NUM_OF_CONTACTS 8  // Note: Maximum number of contacts that can be stored

// #define DEBUG 1

// Description: Command definitions for PhoneBook operations
#ifndef DEBUG
# define ADD    "ADD"     // Note: Add new contact command
# define SEARCH "SEARCH"     // Note: Search contacts command
# define EXIT   "EXIT"     // Note: Exit program command
# endif

# ifdef DEBUG
# define ADD    "A"     // Note: Add new contact command
# define SEARCH "S"     // Note: Search contacts command
# define EXIT   "E"     // Note: Exit program command
# endif

#endif

// Description: Class managing a collection of contacts with search and display capabilities
class PhoneBook
{
	public:
		// Function: Constructor and Destructor
		PhoneBook(void);
		~PhoneBook(void);

		// Function: Public interface methods
		// Description: Execute the phone book application
		int execute(void);


	private:
		// Member: Core data
		Contact contact[NUM_OF_CONTACTS + 1]; 	// Array of contact records
		int activeContactCount; 				// Number of active contacts
		int currentContactIndex;				// Current position for adding contacts

		// Function: Display helper methods
		void addContact(void);					// Add or update a contact
		void searchAndDisplayContacts(void);	// Search and display contact details
		void displayContactDetails(void);		// Show detailed view of one contact
		void printContactsHeader(void);			// Print column headers
		void printContactsTable(void);			// Print all contacts in table format
		void printRuledLine(void);				// Print horizontal separator line
		void printOneRow(int row);				// Print one row of the contacts table
		std::string trimString(std::string str);// Function: Truncate string to fit display width
};

#endif