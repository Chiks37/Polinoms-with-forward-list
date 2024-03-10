#pragma once
#include <iostream>
//#include "TList.h"
class TListNode
{
	double val;
	int id; ///3-digit identification number
	TListNode* pNext;
public:
	TListNode(double _val, int _id, TListNode* _pNext) : val(_val), id(_id), pNext(_pNext) {};
	friend class TList;
	friend std::ostream& operator<< (std::ostream& outStream, const TListNode& nodeToOuput);
	//friend class ostream;															///WHY?
	//friend std::ostream& operator<<(std::ostream& outStream, const TList& listToOutput);
};

