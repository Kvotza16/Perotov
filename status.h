#pragma once
#ifndef _STATUS
#define _STATUS
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
class status
{
protected:
	string sum;
	int goodColour;
	int badColour;
public:
	status();
	status(string sum, int goodColour, int badColour);
	void get_status();
	string get_sum();
	void print();
	//status status(&status other);
	~status();
};
#endif // !STATUS