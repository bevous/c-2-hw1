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
	return std::string();
}

std::string service::getType()
{
	return std::string();
}

int service::getPrice()
{
	return 0;
}

std::string service::getDate()
{
	return std::string();
}


service::~service()
{
}
