#include "TList.h"

void TList::del(TListNode* pPrev) 
{
    pPrev->pNext->val = 0;
    pPrev->pNext->id = 0;
    TListNode* pNextTemp = pPrev->pNext->pNext;
    pPrev->pNext->pNext = 0;
    delete pPrev->pNext;
    pPrev->pNext = pNextTemp;
}

TList::TList()
{
    pFirst = new TListNode(0, -1, nullptr);
    pFirst->pNext = pFirst;
}

bool TList::isEmpty()
{
    return (pFirst == pFirst->pNext);
}

void TList::add(double _val, int _id)
{
    if (_val != 0) {
        TListNode* pPrevious = pFirst;
        TListNode* pCurrent = pPrevious->pNext;

        while (_id > pCurrent->id) { // id1 > id2
            pPrevious = pCurrent;
            pCurrent = pCurrent->pNext;
        }
        if (_id == pCurrent->id) // id1 == id2
        {
            pCurrent->val += _val;
            if (pCurrent->val == 0) {
                del(pPrevious);
            }
        }
        else // id1 < id2
        {
            TListNode* pNew = new TListNode(_val, _id, pNew);

            if (pCurrent->pNext != pCurrent)// inward inserting
            {
                pNew->pNext = pCurrent->pNext;
            }

            pCurrent->pNext = pNew;
        }
    }
}

TList TList::operator+(const TList& pOp2)
{
    TList pResultList;
    TListNode* pFirstCurrent = pFirst;
    TListNode* pSecondCurrent = pOp2.pFirst;

    while (pFirstCurrent->pNext != pFirstCurrent) 
    {
        while ( (pFirstCurrent->id > pSecondCurrent->id)  &&  (pSecondCurrent->pNext != pSecondCurrent) ) // id1 > id2
        {
            pResultList.add(pSecondCurrent->val, pSecondCurrent->id);
            pSecondCurrent = pSecondCurrent->pNext;
        }
        if (pFirstCurrent->id == pSecondCurrent->id) // id1 == id2
        {
            pResultList.add(pFirstCurrent->val + pSecondCurrent->val, pFirstCurrent->id);
        }
        else // id1 < id2
        {
            pResultList.add(pFirstCurrent->val, pFirstCurrent->id);
        }

        pFirstCurrent = pFirstCurrent->pNext;
    }

    while (pSecondCurrent->pNext != pSecondCurrent) {
        pResultList.add(pSecondCurrent->val, pSecondCurrent->id);
    }

    return pResultList;
}
