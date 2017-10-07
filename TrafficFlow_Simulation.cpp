/*
@Robert Coleman        10/7/2017
  -Traffic Flow Simulation Model-
   estimate the time taken for the traffic flow between point A and point B at any given time. 
   To solve this, you will be using a simple approach using random walk problem solving technique.
*/
#include "stdafx.h"
#include <iostream> 
#include <Windows.h>
#include<ctime>		
#include<cstdlib>


using namespace std;

// Variables
void setcolor();
int randNumberofCars;
int randNumberMove;
int randEvent;

// Controls the colors used in the text
void setcolor(unsigned short color)
{
	HANDLE textcolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(textcolor, color);
}
// Simple function to display program title
void programTitle()
{
	setcolor(3);// Sets the text color
	cout << "========================================= \n" ;
	cout << "    Traffic Flow Simulation Model         \n" ;
	cout << "-_--_-___----_-_-_---__--_----___---_--_- \n";
	cout << "========================================= \n" ;
	
}
// Funtion for the car movement which will be call on the next function!
void carMovement()
{
	if (randNumberMove == 1)
	{
		cout << "--Car turn left <--" << endl;
	}
	else if (randNumberMove == 2)
	{
		cout << "--Car turn right -->" << endl;
	}
	else
	{
		cout << "--Car move forward ^" << endl;
	}
	
}
// Function for the flow of traffic
void trafficFlow()
{
	if (randNumberofCars <= 3)
	{
		setcolor(4);
		cout << "*********" << endl;
		cout << "RED LIGHT" << endl;
		cout << "*********" << endl;
		cout << "--Car stop but it might!" << endl;
	}
	else if (randNumberofCars == 4)
	{
		setcolor(6);
		cout << "************" << endl;
		cout << "YELLOW LIGHT" << endl;
		cout << "************" << endl;
	}
	else if (randNumberofCars == 5)
	{
		setcolor(6);
		cout << "************" << endl;
		cout << "YELLOW LIGHT" << endl;
		cout << "************" << endl;
	}
	else if (randNumberofCars == 6)
	{
		setcolor(6);
		cout << "************" << endl;
		cout << "YELLOW LIGHT" << endl;
		cout << "************" << endl;
	}
	else 
	{
		setcolor(2);
		cout << "************" << endl;
		cout << "GREEN LIGHT" << endl;
		cout << "************" << endl;
	}
}
// Function for the trafic light (it also generates the number of cars at the traffic light) 
void trafficLightFunction()
{
	// TIMER START
	clock_t startTime = clock();
	/*
	   Construct point A to point B where light 1= point A and light 4= point B !
	   This is based on a route that consists of frout traffic lights intersections
	*/
		// initialize random seed 
		srand(time(0));
		// generate number of cars between 1 and 15
		randNumberofCars = rand() % 15 + 1;
		setcolor(3);
		cout << "Cars at trafic light 1 = " << randNumberofCars << " cars \n";
		// call function for traffic flow!
		trafficFlow();
		// generate random car movement
		randNumberMove = rand() % 3 + 1;
		// calling function for car movement
		carMovement();
		
		randNumberofCars = rand() % 15 + 1;
		setcolor(3);
		cout << "Cars at trafic light 2 = " << randNumberofCars << " cars \n";
		trafficFlow();
		randNumberMove = rand() % 3 + 1;
		carMovement();
		
		randNumberofCars = rand() % 15 + 1;
		setcolor(3);
		cout << "Cars at trafic light 3 = " << randNumberofCars << " cars \n";
		trafficFlow();
		randNumberMove = rand() % 3 + 1;
		carMovement();

		randNumberofCars = rand() % 15 + 1;
		setcolor(3);
		cout << "Cars at trafic light 4 = " << randNumberofCars << " cars \n";
		trafficFlow();
		randNumberMove = rand() % 3 + 1;
		carMovement();
	// TIMER END

	// Generate random event that can delay time to travel point B-------------------- 
	srand(time(0));
	randEvent = rand() % 4 + 1;
	if (randEvent == 1)
	{
		setcolor(3);
		cout << "\n There was an accident! delay on travel time" << endl;
		// add to time clock
		double(clock() - startTime) + 0.040;
		cout << "\n Time from point A to point B is: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	}
	else if (randEvent == 2)
	{
		setcolor(3);
		cout << "\n One traffic light was not working! delay on travel time" << endl;
		// add to time clock
		double(clock() - startTime) + 0.015;
		cout << "\n Time from point A to point B is: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	}
	else if (randEvent == 3)
	{
		setcolor(3);
		cout << "\n Detour! delay on travel time" << endl;
		// add to time clock
		double(clock() - startTime) + 0.035;
		cout << "\n Time from point A to point B is: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	}
	else
	{
		setcolor(3);
		cout << "\n Time from point A to point B is: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
	}

	//-------------------------
}
// Main function
int _tmain(int argc, _TCHAR* argv[])
{
	// calling functions to dislay data!
	programTitle();
	trafficLightFunction();
	system("pause");
	return 0;
}

