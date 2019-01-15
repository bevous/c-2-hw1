#pragma once
#include <vector>
#include <string>



class service
{
private:
	std::string name;
	std::string type;
	int price;
	std::string date;

	std::string formatter(); // formats the data for output

public:
	service();
	service(std::string nam = "none", std::string typ = "none", int pric = -1, std::string dat = "none");
	
	//getters
	std::string Sformat(); //returns everything for output is string format

	std::string getName(); // returns the client name
	std::string getType(); // returns the service type
	int getPrice(); // returns the type of service
	std::string getDate(); // returns the date of service



};

