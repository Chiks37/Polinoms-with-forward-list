#pragma once
#include "TListNode.h"
#include <iostream>

class TList
{
	TListNode* pFirst;

	void del(TListNode* previousNode);
public:
	TList();
	bool isEmpty();
	void add(double nodeValue, int idValue);
	TList operator+(const TList& secondOperatorPointer);
	void quickSum(TList& secondOperatorPointer);
	void print();
	//friend std::ostream& operator<<(std::ostream& outStream, const TList& listToOutput);
};

