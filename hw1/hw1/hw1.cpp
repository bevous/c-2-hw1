// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

#include "service.h"
#include "services.h"

int main()
{
    std::cout << "Hello World!\n"; 
	services sales;
	sales.readFile();
	system("pause");
}
