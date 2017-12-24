#include "status.h"

status::status()
{
	sum = "";
	goodColour = 0;
	badColour = 0;
}

status::status(string sum, int goodColour, int badColour)
{
	this->sum = sum;
	this->goodColour = goodColour;
	this->badColour = badColour;
}

status::~status()
{
}

void status::get_status()
{
	// Variables (scales 1-4)
	int sumGood = 0;
	int sumBad = 0;
	int scales[] = { 0,30,60,90,101 };
	string sum;

	// calc the summery for the current fruit status based on good colour
	for (int currentScale = 0; currentScale < 4; currentScale++)
	{
		if (goodColour >= scales[currentScale] && goodColour < scales[currentScale + 1])
		{
			sumGood = currentScale + 1;
		}
	}

	// calc the summery for the current fruit status based on bad colour
	for (int currentScale = 0; currentScale < 4; currentScale++)
	{
		if (badColour >= scales[currentScale] && badColour < scales[currentScale + 1])
		{
			sumBad = currentScale + 1;
		}
	}

	// sum it all up
	if (sumGood == 4 && sumBad <= 1)
	{
		sum =  "A";
	}
	if (sumGood == 3 && sumBad <= 2)
	{
		sum = "B";
	}
	if (sumGood == 2 && sumBad <= 1)
	{
		sum = "C";
	}
	if (sumGood == 1 && sumBad >= 3)
	{
		sum = "D";
	}

	// Print
	cout << "Fruit quality is: " + sum << endl;

	// update sum
	this->sum = sum;
}

string status::get_sum()
{
	return this->sum;
}

void status::print()
{
	cout << "the fruit is ready for distribution :)";
}
