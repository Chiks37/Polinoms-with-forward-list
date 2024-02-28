#pragma once
class TListNode
{
	double val;
	int id; ///3-digit identification number
	TListNode* pNext;
public:
	TListNode(double _val, int _id, TListNode* _pNext) : val(_val), id(_id), pNext(_pNext) {};
	friend class TList;
};

