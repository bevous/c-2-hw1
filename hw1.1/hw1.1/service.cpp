#include "service.h"
#include <iostream>


/**
* Summary
* compares this service to another service.
*
* @param other the right hand value.
* @param select
*
* @returns int
*/
int service::compare_to(const service &other) const
{
	if (this->getPrice() < other.getPrice())
	{
		return -1;
	}
	else if (this->getPrice() > other.getPrice())
	{
		return 1;
	}
	else
	{
		return 0;
	}

}




// ReSharper disable once CppDoxygenUnresolvedReference
/**
* Summary
* initializes all elements of the class.
*
* @param nam customers name
* @param typ service provided
* @param pric price of the service
* @param dat date of the sale
*
*/
service::service(std::string nam, std::string typ, double pric, std::string dat)
{
	name = nam;
	type = typ;
	price = pric;
	date = dat;
}



/**
* Summary
* gives the customers name
*
* @returns name
*/
std::string service::getName() const
{
	return name;
}


/**
* Summary
* gives the sale type
*
* @returns type
*/
std::string service::getType() const
{
	return type;
}


/**
* Summary
* gives the price of the sale
*
* @returns price
*/
double service::getPrice() const
{
	return price;
}


/**
* Summary
* gives the date of the sale
*
* @returns date
*/
std::string service::getDate() const
{
	return date;
}


/**
* Summary
* determines if this object is less than the right hand object
*
* @returns bool
*/
bool service::operator<(const service &rh)
{
	return this->compare_to(rh) < 0;
}



/**
* Summary
* determines if this object is greater than the right hand object
*
* @returns bool
*/
bool service::operator>(const service &rh)
{
	return this->compare_to(rh) > 0;
}


/**
* Summary
* determines if this object is less than or equal to the right hand object
*
* @returns bool
*/
bool service::operator<=(const service &rh)
{
	return this->compare_to(rh) <= 0;
}


/**
* Summary
* determines if this object is greater than or equal to the right hand object
*
* @returns bool
*/
bool service::operator>=(const service &rh)
{
	return this->compare_to(rh) >= 0;
}


/**
* Summary
* determines if this object is equal to the right hand object
*
* @returns bool
*/
bool service::operator==(const service &rh)
{
	return this->compare_to(rh) == 0;
}


/**
* Summary
* determines if this object is not equal to the right hand object
*
* @returns bool
*/
bool service::operator!=(const service &rh)
{
	return this->compare_to(rh) != 0;
}


/**
* Summary
* overloads the stream insertion operator
*
* @returns out
*/
std::ostream& operator<<(std::ostream& out, const service &s)
{
	out << s.getName() << " " << s.getType() << " " << s.getPrice()
		<< " " << s.getDate();
	return out;
}