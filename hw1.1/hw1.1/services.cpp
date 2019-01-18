
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

service services::min(std::string type)
{
	service lowest;
	const std::string default_name = "none";
	for(auto sale : sales)
	{
		if(sale.getType()==type)
		{
			if(lowest.getName() == default_name)
				{
					lowest = sale;
			}
			else if(sale.getPrice() < lowest.getPrice())
			{
				
				lowest = sale;
			}
		}//no else needed do_nothing()
	}
	return lowest;
}

service services::max(std::string type)
{
	service highest;
	for (auto sale : sales)
	{
		if (sale.getType() == type)
		{
			if (sale.getPrice() > highest.getPrice())
			{
				highest = sale;
			}
		}//no else needed do_nothing()
	}
	return highest;
}

double services::range(std::string type)
{
	auto smallest_sale = min(type);
	auto largest_sale = max(type);
	return (largest_sale.getPrice() - smallest_sale.getPrice());
}

double services::average(std::string type)
{
	auto total = 0.0;
	for(auto &sale : sales)
	{
		if (sale.getType() == type) {
			total += sale.getPrice();
		}// no need for else do_nothing()
	}
	return (total/total_count(type));
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

