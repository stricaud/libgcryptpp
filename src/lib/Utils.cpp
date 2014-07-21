#include <iostream>
#include <sstream>
#include <iomanip>

#include <gcrypt++/Utils.hpp>

std::string Gcrypp::Utils::string_to_hex(std::string str, bool uppercase)
{
	std::ostringstream result;


	for (size_t i=0; i < str.length(); i++)
	{
	  result << std::setw(2) << std::setfill('0') << std::hex;
	  if (uppercase) {
	    result << std::uppercase;
	  }
	  result << (int)(unsigned char)str[i]; // <-- Ahah, what a cast! :)
	} 

	result << "";
	return result.str();
}
