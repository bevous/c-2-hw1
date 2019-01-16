#include "pch.h"
#include "services.h"
#include <fstream>
#include <iostream>
services::services()
{
}

void services::readFile()
{
	std::string buffer;
	std::ifstream inFile;
	inFile.open("data.csv");

	while (std::getline(inFile, buffer)) {

	}

	inFile.close();

}


services::~services()
{
}
