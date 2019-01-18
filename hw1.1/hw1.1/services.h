#pragma once
#include <vector>
#include "service.h"
#include <string>
#include <set>
class services
{

private:
	std::vector<service>  sales;
	std::set<std::string> type_of_sales;

public:
	services();

	void read_file(std::string file_name = "data.csv");
	service min(std::string type);
	service max(std::string type) ;
	double range(std::string type);
	double average(std::string type);

	int total_count(std::string type);

	void make_list_of_types();
	std::set<std::string> get_type_list();
	std::string makeFiles();



};

