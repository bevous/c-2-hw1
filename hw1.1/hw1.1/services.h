#pragma once
#include <vector>
#include "service.h"
#include <string>
class services
{

private:
	std::vector<service>  sales;

public:
	services();

	void readFile(std::string file_name = "data.csv");
	double min();
	double max();
	double range();
	double average();

	std::string makeFiles();

};

