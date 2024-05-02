#pragma once
#include "TListNode.h"
#include <iostream>

class TList
{
	TListNode* pFirst;

	void del(TListNode* previousNodePointer);
public:
	TList();
	TList(const TList& secondList);
	void add(double nodeValue, int idValue);
	TList operator+(const TList& secondList);
	void quickSum(TList& secondList);
	void print();
	TList& operator=(const TList& secondList);
	~TList();
};

