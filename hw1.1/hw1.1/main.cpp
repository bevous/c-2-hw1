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

	for(auto total : types)
	{
		std::cout << total << ": " << sales.total_count(total) << std::endl;
	}

	std::cout << "Average: " << sales.average() << std::endl;
	std::cout << "Minimum: " << sales.min() << std::endl;
	std::cout << "Maximum: " << sales.max() << std::endl;
	std::cout << "Range: " << sales.range() << std::endl;

	system("pause");
}