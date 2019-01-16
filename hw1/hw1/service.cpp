#include "pch.h"
#include "service.h"


std::string service::formatter()
{
	return std::string();
}

service::service()
{
}

service::service(std::string nam, std::string typ, int pric, std::string dat)
{
	name = nam;
	type = typ;
	price = pric;
	date = dat;
}

std::string service::Sformat()
{
	return std::string();
}

std::string service::getName()
{
	return name;
}

std::string service::getType()
{
	return type;
}

int service::getPrice()
{
	return price;
}

std::string service::getDate()
{
	return date;
}

