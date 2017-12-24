#pragma once
#ifndef _FRUIT
#define _FRUIT
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include "status.h"
class fruit
{
protected:
	string name;
	int id;
	status status;
public:
	fruit();
	fruit(string name, int id, string sum, int goodColour, int badColour);
	void getid_fruit()const;//retrn id
	void get_status();
	string get_fruit_status_sum();
	void print();
	~fruit();
};
#endif // !FRUIT