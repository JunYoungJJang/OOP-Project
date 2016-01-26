#ifndef _CONTAINER_H
#define _CONTAINER_H

#include "Account.h"
#include <iostream>

using std::endl;
using std::cout;

typedef Account* Element;

class Container
{
private:
	Element* arr;
	int length, idx;
public:
	Container(const int len=50);
	// Container(const Container& c);
	~Container();
	
	void Insert(Element elem);
	Element Remove(const int _idx);
	Element& GetItem(const int _idx);
	int GetElemSum() { return idx; }

	// Container& operator=(const Container& c);
};

#endif
