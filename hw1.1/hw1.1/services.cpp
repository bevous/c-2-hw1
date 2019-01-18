
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
* Opens and reads the specified file. Then saves the data to memory.
*
* @param file_name The name of file to read.
*/

void services::read_file(std::string file_name)
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

service services::min()
{
	const auto first_element = 0;
	return sales[first_element];
}

service services::max()
{
	return sales[sales.size() - 1];
}

double services::range()
{
	const auto first_element = 0;
	return (sales[sales.size() - 1].getPrice() - sales[first_element].getPrice());
}

double services::average()
{
	double total = 0.0;
	for(auto &sale : sales)
	{
		total += sale.getPrice();
	}
	return (total/sales.size());
}

int services::total_count(std::string type)
{
	auto type_total = 0;
	for (auto sale : sales)
	{
		if(sale.getType()==type)
		{
			type_total++;
		}
		//no need for else do_nothing()
	}
	return type_total;
}

void services::make_list_of_types()
{
	for(auto sale : sales)
	{
		type_of_sales.insert(sale.getType());
	}
}

std::set<std::string> services::get_type_list()
{
	return type_of_sales;
}



std::string services::makeFiles()
{
	return std::string();
}

