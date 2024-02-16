#pragma once
#include "TListNode.h"

class TList
{
	TListNode* pFirst;
	TListNode* pLast;
public:
	TList() : pFirst(nullptr), pLast(nullptr) {}
	bool isEmpty();
	void append(int _val);

};

