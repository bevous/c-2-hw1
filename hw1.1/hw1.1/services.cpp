
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "services.h"


services::services()
= default;

/**
* Summary
* checks if the file exists
*
* @param file_name The name of file to read.
* 
* @returns bool true is file exists false if file does not exist
*/
bool services::validate_exists(const std::string& file_name)
{
	std::fstream file_check(file_name);
	auto is_file_real = file_check.good();
	file_check.close();
	return is_file_real;
}

bool services::validate_format(const std::string& file_name)
{
	bool is_format_good = true;

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

	while (std::getline(inFile, buffer) && is_format_good) {
		std::istringstream s(buffer);
		while (std::getline(s, buffer2, delim) && is_format_good) {
			switch (collum) {
			case 0: {
				name = buffer2;
				is_format_good = true;
				break;
			}
			case 1: {
				type = buffer2;
				is_format_good = true;
				break;
			}
			case 2: {
				try {
					price = std::stod(buffer2);
					is_format_good = true;
				}catch (std::invalid_argument ex)
				{
					std::cout << ex.what() << std::endl;
					is_format_good = false;
				}
				break;
			}
			case 3: {
				date = buffer2;
				is_format_good = true;
				break;
			}
			default: {
				//DONOTHING
				is_format_good = false;
				break;
			}
			}
			if(!is_format_good)
			{
				std::cout << "not good bruh" << std::endl;
			}
			collum++;
			//std::cout << "reading file " << buffer << std::endl;
		}
		collum = 0;// USE 0 TO RESET
	}

	inFile.close();

	return is_format_good;
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

