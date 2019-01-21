// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <set>
#include "services.h"
#include <iomanip>


/**
* Summary
* contains all of the logic for the main.
*
*/
void do_the_thing()
{
	const std::string file = "Data.csv";//change this to change the file loaded in
	services sales;
	if (services::validate_exists(file) && services::validate_format(file)) {
		sales.read_file(file);

		sales.make_list_of_types();
		sales.make_files();

		auto type_list = sales.get_type_list();

		for (auto type : type_list)
		{
			std::cout << std::fixed << std::setprecision(2) << std::endl;

			std::cout << type << ": " << sales.total_count(type) << std::endl;
			std::cout << "Average: " << sales.average(type) << std::endl;
			std::cout << "Minimum: " << sales.min(type) << std::endl;
			std::cout << "Maximum: " << sales.max(type) << std::endl;
			std::cout << "Range: " << sales.range(type) << std::endl;
			std::cout << std::endl;
		}

	}
	else
	{
		std::cout << "file is invalid" << std::endl;
	}
}


int main()
{
	do_the_thing();
	system("pause");
}