//============================================================================
// Name        : main.cpp
// Author      : Ari Suarkadipa
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include <fstream>

int main() {
	std::ofstream myfile ("example.txt");

	std::cout << "Creating the file" << std::endl;
	if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();
	}
	else
		std::cout << "Unable to open file";

	return 0;
}
