#include "Container.h"
#include <iostream>

Container::Container(const int len) : idx(0)
{
	length = len;
	arr = new Element[length];
}
Container::~Container()
{
	for(int i=0; i<idx; i++) {
		delete arr[i];
	}
	delete []arr;
}

void Container::Insert(Element elem)
{
	if(idx >= length) {
		cout << "용량초과!" << endl;
		return;
	}
	arr[idx++] = elem;
}

Element Container::Remove(const int _idx)
{
	Element tmp = arr[_idx];
	for(int i=_idx; i<idx-1; i++) {
		arr[i] = arr[i+1];
	}
	idx--;

	return tmp;
}

Element& Container::GetItem(const int _idx)
{
	if(_idx >= idx) {
		cout << "범위 초과!" << endl;
		return arr[0];
	}
	return arr[_idx];
}
