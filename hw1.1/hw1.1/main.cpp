// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

#include "service.h"
#include "services.h"

int main()
{
	const std::string file = "data.csv";//change this to change the file loaded in
	services sales;
	sales.readFile(file);
	system("pause");
}