#include "pch.h"
#include "service.h"
#include <iostream>



service::service()
{
}


int service::compare_to(const service &other)
{
	if (this->getPrice() < other.getPrice()) {
		return -1;
	}
	else if (this->getPrice() > other.getPrice()) {
		return 1;
	}
	else {
		return 0;
	}
}


service::service(std::string nam, std::string typ, int pric, std::string dat)
{
	name = nam;
	type = typ;
	price = pric;
	date = dat;
}



std::string service::getName() const
{
	return name;
}

std::string service::getType() const
{
	return type;
}

double service::getPrice() const
{
	return price;
}

std::string service::getDate() const
{
	return date;
}


bool service::operator<(const service &rh)
{
	return this->compare_to(rh) < 0;
}

bool service::operator>(const service &rh)
{
	return this->compare_to(rh) > 0;
}

bool service::operator<=(const service &rh)
{
	return this->compare_to(rh) <= 0;
}

bool service::operator>=(const service &rh)
{
	return this->compare_to(rh) >= 0;
}

bool service::operator==(const service &rh)
{
	return this->compare_to(rh) == 0;
}

bool service::operator!=(const service &rh)
{
	return this->compare_to(rh) != 0;
}

std::ostream& operator<<(std::ostream& out, service &service)
{
	out << service.getName() << " " << service.getType() << " " << service.getPrice() 
		<< " " << service.getDate();
	return out;
}