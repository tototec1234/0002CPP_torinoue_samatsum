/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:59:25 by torinoue          #+#    #+#             */
/*   Updated: 2025/06/28 17:16:46 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdio>
# include <sstream>

#ifndef NUM_OF_FIELDS
# define NUM_OF_FIELDS 6  // Note: Total number of fields per contact
#endif

// Description: Class representing a single contact entry in the phone book
class Contact
{
	public:
		// Description: Enumeration for field indices in contact records
		enum Field {
			ID = 0,								// Note: Always first field
			FirstName = 1,						// Note: Required contact information
			LastName = 2,						// Note: Required contact information
			NickName = 3,						// Note: Required contact information
			PhoneNumber = 4,					// Note: Required contact information
			DarkestSecret = NUM_OF_FIELDS - 1	// Note: Always last field
		};
		// Function: Constructor and Destructor
		Contact(void);
		~Contact(void);
		
		std::string getFieldValue(int fieldIndex);		// Function: Field access methods
		void setContactInfo(void);						// Function: Field modification methods

		
	private:
		void setHeader(void);										// Function: Helper method to set column headers
		void updateFieldValue(int fieldIndex, std::string setvalue);// Function: Helper methods for field management

		
		// Static data for all contacts.
		static int contactCount;								// Total number of contacts created.
		static const std::string column_header[NUM_OF_FIELDS];	// Column headers for contact fields

		// Member: Instance specific data
		int contactId;											// Unique ID for this contact
		std::string fieldValues[NUM_OF_FIELDS];					// Values for each field
};

#endif

/*
YThe Google C++ Style Guide is a good reference.
https://ttsuki.github.io/styleguide/cppguide.ja.html
*/