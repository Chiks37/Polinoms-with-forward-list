#include "TList.h"

bool TList::isEmpty()
{
    return (pFirst == nullptr);
}

void TList::append(int _val)  //NOT COMPLETED
{
    TListNode* pNew = new TListNode(_val);
}
