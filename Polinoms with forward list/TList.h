#pragma once
#include "TListNode.h"
#include <iostream>

class TList
{
	TListNode* pFirst;

	void del(TListNode* previousNode);
public:
	TList();
	TList(const TList& secondList);
	void add(double nodeValue, int idValue);
	TList operator+(const TList& secondOperatorPointer);
	void quickSum(TList& secondOperatorPointer);
	void print();
	TList& operator=(const TList& secondList);
	~TList();
	//friend std::ostream& operator<<(std::ostream& outStream, const TList& listToOutput);
};

