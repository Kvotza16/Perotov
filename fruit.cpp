#include "fruit.h"
#include "status.h"


fruit::fruit():status()
{
	name = "fruit";
	id = 0000;
}

fruit::fruit(string name, int id, string sum, int goodColour, int badColour):status(sum, goodColour, badColour)
{
	this->name = name;
	this->id = id;
}


fruit::~fruit()
{
}

void fruit::getid_fruit()const
{
	cout << (this->id);
}

void fruit::get_status()
{
	this->status.get_status();
}

string fruit::get_fruit_status_sum()
{
	return this->status.get_sum();
}

void fruit::print()
{
	cout << "the fruit is-\n";
	cout << this->name;
	cout << this->id;
	//cout << "his status is: " << this->status;
}
