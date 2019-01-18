// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <set>
#include "service.h"
#include "services.h"

int main()
{
	const std::string file = "data.csv";//change this to change the file loaded in
	services sales;
	sales.read_file(file);

	sales.make_list_of_types();
	std::set<std::string> types = sales.get_type_list();

	for(auto type : types)
	{
		std::cout << type << ": " << sales.total_count(type) << std::endl;

		std::cout << "Average: " << sales.average(type) << std::endl;
		std::cout << "Minimum: " << sales.min(type) << std::endl;
		std::cout << "Maximum: " << sales.max(type) << std::endl;
		std::cout << "Range: " << sales.range(type) << std::endl;
		std::cout << std::endl;
	}

	

	system("pause");
}