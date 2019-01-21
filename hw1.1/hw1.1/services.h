#pragma once
#include <vector>
#include <string>
#include <set>
#include "service.h"
class services
{

private:
	std::vector<service>  sales;
	std::set<std::string> type_of_sales;

public:
	services();
	static bool validate_exists(const std::string& file_name = "data.csv");
	static bool validate_format(const std::string& file_name = "data.csv");
	void read_file(std::string file_name = "data.csv");
	service min(std::string type);
	service max(std::string type) ;
	double range(std::string type);
	double average(std::string type);

	int total_count(std::string type);

	void make_list_of_types();
	std::set<std::string> get_type_list() const;
	void make_files();



};

