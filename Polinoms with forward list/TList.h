#pragma once
#include "TListNode.h"

class TList
{
	TListNode* pFirst;

	void del(TListNode* previousNode);
public:
	TList();
	bool isEmpty();
	void add(double nodeValue, int idValue);
	TList operator+(const TList& secondOperatorPointer);	
};

