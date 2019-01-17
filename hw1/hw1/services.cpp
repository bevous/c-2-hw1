
#include <fstream>
#include <iostream>
#include <sstream>

#include "services.h"


services::services()
{
}

void services::readFile()
{
	std::string buffer;
	std::string buffer2;
	std::ifstream inFile;
	inFile.open("data.csv");
	int collum = 0;
	std::string name = "";
	std::string type = "";
	double price = 0.0;
	std::string date;
	const char delim= ',';

	while (std::getline(inFile, buffer)) {
		std::istringstream s(buffer);
		while (std::getline(s, buffer2, delim)) {
			switch (collum) {
			case(0): {
				name = buffer2;
			}
			case(1): {
				type=buffer2
			}
			case(2): {

			}
			case(3): {

			}
			default: {

			}
			}
		}
	}

	inFile.close();

}


services::~services()
{
}
