#pragma once
#include <vector>
#include <string>
#include <iostream>


class service
{
private:
	std::string name;
	std::string type;
	double price;
	std::string date;

	int compare_to(const service&);

public:
	service();
	service(std::string nam = "none", std::string typ = "none", int pric = -1, std::string dat = "none");
	
	//getters
	std::string getName() const;   // returns the client name
	std::string getType() const;  // returns the service type
	double getPrice() const;  // returns the type of service
	std::string getDate() const;  // returns the date of service

	//compare operators
	bool operator< (const service&);
	bool operator> (const service&);
	bool operator<= (const service&);
	bool operator>= (const service&);
	bool operator== (const service&);
	bool operator!= (const service&);


	//output operator overload
	friend std::ostream& operator<< (std::ostream& out, service &service);

};

