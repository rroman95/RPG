#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>

#define MISSINGFILE 404

class JSON
{
public:
	JSON() {};
	JSON(std::ifstream&);
	JSON(std::string&);
	JSON(const char*);
	std::map<std::string, std::string> charData;
	void jsonparser(std::ifstream&);
	void printcharData()
	{
		std::map<std::string, std::string>::iterator it;
		for (it = charData.begin(); it != charData.end(); it++)
		{
			std::cout << it->first  // string (key)
				<< ':'
				<< it->second   // string's value 
				<< std::endl;
		}
	}

};