
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "services.h"


/**
* Summary
* this is the default constructor for the class.
*
*/
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


/**
* Summary
* validates the format of the csv file
*
* @param file_name The name of file to read.
*
* @returns bool true if the file is formatted correctly. false if file is not formatted correctly
*/
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
			collum++;
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
* @param first service to compare.
* 
* @param other service to compare
* 
* @return bool
*/
bool compare_type(service& first, service& other)
{
	return first.getType() < other.getType();
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

	std::sort(sales.begin(), sales.end(), compare_type);
}


/**
* Summary
* finds the smallest sale in the largest category.
*
* @param type The sale category to check.
*
* @returns service 
*/
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



/**
* Summary
* finds the largest sale in the given category.
*
* @param type The sale category to check.
*
* @returns service
*/
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


/**
* Summary
* calculates the range between the largest sale and the smallest sale in the given category.
*
* @param type The sale category to check.
*
* @returns double
*/
double services::range(std::string type)
{
	auto smallest_sale = min(type);
	auto largest_sale = max(type);
	return (largest_sale.getPrice() - smallest_sale.getPrice());
}



/**
* Summary
* calculates the average sale price in the given category.
*
* @param type The sale category to check.
*
* @returns double
*/
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



/**
* Summary
* counts the number of sales in the given category.
*
* @param type The sale category to check.
*
* @returns int
*/
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



/**
* Summary
* generates a list of sale types.
*
*/
void services::make_list_of_types()
{
	for(auto sale : sales)
	{
		type_of_sales.insert(sale.getType());
	}
}



/**
* Summary
* passes the list of sale types out of the class.
*
* @returns set<string>
*/
std::set<std::string> services::get_type_list() const
{
	return type_of_sales;
}



/**
* Summary
* generates output files for each category. each file is given the name of the category.
*
*/
void services::make_files()
{
	for (auto type : type_of_sales) {
		auto out_file_name = type + ".txt";

		std::ofstream out_file(out_file_name);

		for(auto sale : sales)
		{
			if(sale.getType()==type)
			{
				out_file << sale << std::endl;
			}
		}
		out_file << std::endl;
		out_file << std::fixed << std::setprecision(2) << std::endl;

		out_file<< type << ": " << this->total_count(type) << std::endl;
		out_file<< "Average: " << this->average(type) << std::endl;
		out_file<< "Minimum: " << this->min(type) << std::endl;
		out_file<< "Maximum: " << this->max(type) << std::endl;
		out_file<< "Range: " << this->range(type) << std::endl;

		out_file.close();
	}
}

