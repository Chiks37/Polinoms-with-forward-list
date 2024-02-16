#pragma once
class TListNode
{
	int val;
	TListNode* pNext;
public:
	TListNode(int _val) : val(_val), pNext(nullptr) {}
	TListNode(int _val, TListNode* _pNext) : val(_val), pNext(_pNext) {}
	friend TList; // TO SOLVE THIS PROBLEM
};

