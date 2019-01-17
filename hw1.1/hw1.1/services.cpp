
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "services.h"


services::services()
{
}

/**
* Summary
* Opens and reads the specicfied file. Then saves the data to memory.
*
* @param file_name The file to read
*/

void services::readFile(std::string file_name = "Data.csv")
{
	std::string buffer;
	std::string buffer2;
	std::ifstream inFile;
	inFile.open(file_name);
	int collum = 0;
	std::string name = "";
	std::string type = "";
	double price = 0.0;
	std::string date;
	const char delim = ',';

	while (std::getline(inFile, buffer)) {
		std::istringstream s(buffer);
		while (std::getline(s, buffer2, delim)) {
			switch (collum) {
			case 0: {
				name = buffer2;
				break;
			}
			case 1: {
				type = buffer2;
				break;
			}
			case 2: {
				price = std::stod(buffer2);
				break;
			}
			case 3: {
				date = buffer2;
				break;
			}
			default: {
				//DONOTHING
				break;
			}
			}
			collum++;
			//std::cout << "reading file " << buffer << std::endl;
		}
		collum = 0;// USE 0 TO RESET
		sales.push_back(service(name, type, price, date));
	}

	inFile.close();

	std::sort(sales.begin(), sales.end());
}

double services::min()
{
	return 0.0;
}

double services::max()
{
	return 0.0;
}

double services::range()
{
	return 0.0;
}

double services::average()
{
	return 0.0;
}

std::string services::makeFiles()
{
	return std::string();
}

