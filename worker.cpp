#include "worker.h"



worker::worker()
{
	name = "unkmown";
	id = 0000;
	level = 0;
}

worker::worker(string name, int id, int level)
{
	this->name = name;
	this->id = id;
	this->level = level;
}


worker::~worker()
{
}

void worker::getid_worker()const
{
	cout<<(this->id);
}

void worker::get_level()
{
	cout << (this->level);
}

void worker::print()
{
	cout << "the worker is-\n";
	cout << this->name;
	cout << this->id;
	cout << "his level-" << this->level;
}
