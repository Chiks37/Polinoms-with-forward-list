#pragma once
#include <iostream>

class TListNode
{
	double val;
	int id; ///3-digit identification number
	TListNode* pNext;
public:
	TListNode(double value, int ID, TListNode* nextNodePointer) : val(value), id(ID), pNext(nextNodePointer) {};
	friend class TList;
	friend std::ostream& operator<< (std::ostream& outStream, const TListNode& nodeToOuput);
};

