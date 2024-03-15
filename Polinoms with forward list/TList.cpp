#include "TList.h"

void TList::del(TListNode* pPrev)
{
    pPrev->pNext->val = 0;
    pPrev->pNext->id = 0;
    TListNode* pNextTemp = pPrev->pNext->pNext;
    pPrev->pNext->pNext = nullptr;

    delete pPrev->pNext;
    pPrev->pNext = pNextTemp;
}

TList::TList()
{
    pFirst = new TListNode(0, -1, nullptr);
    pFirst->pNext = pFirst;
}

TList::TList(const TList& sList)
{
    pFirst = new TListNode(0, -1, nullptr);
    pFirst->pNext = pFirst;

    TListNode* pFirstPrevious = pFirst;
    TListNode* pSecondCurrent = sList.pFirst->pNext;
    TListNode* pNew;

    while (pSecondCurrent != sList.pFirst) 
    {
        pNew = new TListNode(pSecondCurrent->val, pSecondCurrent->id, pFirst);
        pFirstPrevious->pNext = pNew;
        pFirstPrevious = pFirstPrevious->pNext;
        pSecondCurrent = pSecondCurrent->pNext;
    }
}

void TList::add(double _val, int _id) ///INCORRECT ORDER
{
    if (_val != 0 && _id > 0 && _id <= 999)
    {
        TListNode* pPrevious = pFirst;
        TListNode* pCurrent = pPrevious->pNext;

        while (_id < pCurrent->id) { // id1 < id2
            pPrevious = pCurrent;
            pCurrent = pCurrent->pNext;
        }
        if (_id == pCurrent->id) // id1 == id2
        {
            double valSum = pCurrent->val + _val;
            if (valSum != 0) 
            {
                pCurrent->val = valSum;
            }
            else
            {
                del(pPrevious);
            }
        }
        else // id1 > id2
        {
            TListNode* pNew = new TListNode(_val, _id, pCurrent);
            pPrevious->pNext = pNew;
        }
    }
    else
    {
        std::cout << "Incorrect data.\n";
    }
}

TList TList::operator+(const TList& pOp2)
{
    TList resultList;
    TListNode* pFirstCurrent = pFirst->pNext;
    TListNode* pSecondCurrent = pOp2.pFirst->pNext;
    TListNode* pResultLast = resultList.pFirst;///////////

    while (pFirstCurrent != pFirst || pSecondCurrent != pOp2.pFirst)
    {
        if (pFirstCurrent->id < pSecondCurrent->id)
        {
            TListNode* pNew = new TListNode(pSecondCurrent->val, pSecondCurrent->id, resultList.pFirst);
            pResultLast->pNext = pNew;
            pResultLast = pResultLast->pNext;
            pSecondCurrent = pSecondCurrent->pNext;
        }
        else if (pFirstCurrent->id > pSecondCurrent->id)
        {
            TListNode* pNew = new TListNode(pFirstCurrent->val, pFirstCurrent->id, resultList.pFirst);
            pResultLast->pNext = pNew;
            pFirstCurrent = pFirstCurrent->pNext;
        }
        else
        {
            double valSum = pFirstCurrent->val + pSecondCurrent->val;

            if (valSum != 0)
            {
                TListNode* pNew = new TListNode(valSum, pFirstCurrent->id, resultList.pFirst);
                pResultLast->pNext = pNew;
                pFirstCurrent = pFirstCurrent->pNext;
                pSecondCurrent = pSecondCurrent->pNext;
            }
        }
    }

    return resultList;
}

void TList::quickSum(TList& pOp2)
{
    TListNode* pFirstPrevious = pFirst;
    TListNode* pFirstCurrent = pFirst->pNext;
    TListNode* pSecondPrevious = pFirst;
    TListNode* pSecondCurrent = pOp2.pFirst->pNext;

    while (pSecondCurrent != pOp2.pFirst)
    {
        if (pFirstCurrent->id < pSecondCurrent->id)
        {
            pFirstPrevious->pNext = pSecondCurrent;
            pSecondPrevious->pNext = pSecondCurrent->pNext;
            pSecondCurrent->pNext = pFirstCurrent;

            pFirstPrevious = pFirstPrevious->pNext;
            pSecondCurrent = pSecondPrevious->pNext;
        }
        else if (pFirstCurrent->id > pSecondCurrent->id)
        { 
            pFirstPrevious = pFirstPrevious->pNext;
            pFirstCurrent = pFirstCurrent->pNext;
        }
        else
        {///THE WHOLE {...} IS DIFFERENT FROM TE NOTEBOOK, MAYBE INCORRECT
            pFirstCurrent->val += pSecondCurrent->val;
            pSecondPrevious = pSecondPrevious->pNext; ///WASNT WROTEN IN THE NOTEBOOK, MAYBE IS INCORRECT
            pSecondCurrent = pSecondCurrent->pNext;

            if (pFirstCurrent->val == 0) {
                pFirstCurrent = pFirstCurrent->pNext;
                del(pFirstPrevious);
            }
            else
            {
                pFirstCurrent = pFirstCurrent->pNext;
                pFirstPrevious = pFirstPrevious->pNext;
            }
        }
    }
}

void TList::print()
{
    TListNode* pCurrent = pFirst->pNext;

    if (pCurrent != pFirst)
    {
        std::cout << *pCurrent;
        pCurrent = pCurrent->pNext;
    }
    while (pCurrent != pFirst)
    {
        if (pCurrent->val > 0)
        {
            std::cout << "+";
        }
        std::cout << *pCurrent;
        pCurrent = pCurrent->pNext;
    }
    std::cout << '\n';
}

TList& TList::operator=(const TList& sList)
{
    pFirst = new TListNode(0, -1, nullptr);
    pFirst->pNext = pFirst;

    TListNode* pFirstPrevious = pFirst;
    TListNode* pSecondCurrent = sList.pFirst->pNext;
    TListNode* pNew;

    while (pSecondCurrent != sList.pFirst)
    {
        pNew = new TListNode(pSecondCurrent->val, pSecondCurrent->id, pFirst);
        pFirstPrevious->pNext = pNew;
        pFirstPrevious = pFirstPrevious->pNext;
        pSecondCurrent = pSecondCurrent->pNext;
    }
    return *this;
}

TList::~TList()
{
    TListNode* pPrevious = pFirst;
    TListNode* pCurrent = pFirst->pNext;

    pPrevious->val = 0;
    pPrevious->id = 0;
    pPrevious->pNext = nullptr;

    while (pCurrent != pFirst)
    {
        pPrevious->val = 0;
        pPrevious->id = 0;
        pPrevious->pNext = nullptr;

        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    } 
}

//std::ostream& operator<<(std::ostream& os, const TList& list)
//{
//    TListNode* pCurrent = list.pFirst->pNext;
//    if (pCurrent != pFirst)
//    {
//        std::cout << pCurrent;
//        pCurrent = pCurrent->pNext;
//    }
//    while (pCurrent != pFirst)
//    {
//        if (pCurrent->val > 0)
//        {
//            std::cout << "+";
//        }
//        std::cout << pCurrent;
//    }
//    return os;
//}
