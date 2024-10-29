/*
Lane Jones-Popp
Computer Science Fall 2024
Oct. 29
Lab 4, Hourly temp star chart
In this lab we are meant to Write a C++ code that can input hourly  temperatures
and output them into a bar chart using a set of stars. First difficult lab I
Have been told.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "BarchartH.h"
int main()
{
	BarchartH loop(-33);  // Initialize with the value of -33. Precondtion that sets where the bar starts
	loop.runLoop();           // Run the loop 

	int i; // values for inFile while loop
	i = 0;
	int d = 0;

	std::ifstream inFile; // opens file that has temp values within
	inFile.open("inHTempstd.dat");
	float numx; // varible for my infile numbers
	inFile >> numx;

	while (inFile)
	{
		int Rdivide = round(numx / 3); // Divides numx by 3 then rounds said number. A pre condition for my negative number loop
		if (numx < 0 && numx > -31) // Loop that controls negative numbers. Must be with 0 and -31. Precondition
		{
			if (numx < 0) // subtracts 3 from d while numx < 0
			{
				d -= 3;
			}
			if (d == -3) // sets the lenght based off precondtion and sets numx to the left of the screen
			{
				std::cout << std::left << std::setw(Rdivide + 16) << numx << std::right; //Rdivivde + 16 is the post condition that sets the widith
			}
			if (d + 1 >= numx) // adds stars
			{
				std::cout << "*";
			}
			if (d <= numx) // Stops while loop by advancing a number. Post condition d <= numx
			{
				std::cout << "|" << std::endl;
				d = 0;
				inFile >> numx;
			}
		}
		else if (numx >= 0 && numx < 121) // loop used for positive number. Must be between 0 and 121. Precondtion
		{
			if (i == 0) // sets the bar at 0 for my positive numbers and then adds 3 to i
			{
				std::cout << std::left << std::setw(16) << numx << std::right << "|";
				i = +3;
			}
			if ((i - 1) <= numx) // adds star
			{
				std::cout << "*";
				i += 3;
			}
			else // ends the line and moves to the next number in the file
			{
				std::cout << "" << std::endl;
				i = 0;
				d = 0;
				inFile >> numx;
			}
		}
		else // if number is outside of parameters than moves to the next line and moves to the next number as well
		{
			std::cout << "" << std::endl;
			inFile >> numx;
		}
	}

	return 0;
}