#include "stdafx.h"
#include "FuelTank.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;



FuelTank::FuelTank()		// default constructor (capacity = 0.0, level = 0.0)
{
	capacity = 0.0;						// maximum capacity of fuel tank - gallons
	level = 0.0;							// current level of fuel in tank - gallons
}


FuelTank::FuelTank(double cap)					// construct setting fuel capacity (level = 0.0)
{
	 capacity = cap;
	 level = 0.0;
}

FuelTank::FuelTank(double cap, double lvl)		// construct setting fuel capacity and level
{
	 capacity = cap;
	 level = lvl;
}

void	FuelTank::setCapacity(double amt)		// set or change capacity
{
	
	if (level > amt)
		capacity = level;
	else capacity = amt;
	
}

double	FuelTank::addFuel(double amt)			// add to level - return amount added
{
	
	if (getUnusedCapacity() < amt)
		amt = getUnusedCapacity();
	
	level = level + amt;

	return amt;

}

double	FuelTank::useFuel(double amt)			// subtract from level - return amount used
{
	
	if (getLevel() < amt)
		amt = level;

	level = level - amt;
	
	return amt;
}

double	FuelTank::fillUp()						// return amount used
{
	double fillUp = getUnusedCapacity();

	level = level + fillUp;

	return fillUp;
}


double	FuelTank::getCapacity()			const		// return fuel tank capacity
{
	return capacity;
}

double	FuelTank::getLevel()				const		// return current fuel level in tank
{
	return level;
}

double	FuelTank::getUnusedCapacity()		const		// return available (unused) fuel capacity
{
	return capacity - level;
}

void	FuelTank::displayFuelTankInfo()	const		// show capacity, current level, unused capacity
{
	string display = "  ";

	if (isFull() == true)
		display = "FULL";
	else if (isEmpty() == true)
		display = "EMPTY";

	cout << " fuel capacity:  " << fixed << setprecision(1) << setw(3) << getCapacity() << "\t fuel on hand:   " << getLevel() << "\t remaining capacity:  " <<
		getUnusedCapacity() << "\t" << display << endl;
}

bool	FuelTank::isFull()				const		// return true if tank is full, else false
{
	bool full = false;

	if (level == capacity && capacity > 0.0)
		full = true;

	return full;

}

bool	FuelTank::isEmpty()				const		// return true if tank is empty, else false	
{
	bool empty = false;
	
	if (level == 0.0)
		empty = true;

	return empty;
}
