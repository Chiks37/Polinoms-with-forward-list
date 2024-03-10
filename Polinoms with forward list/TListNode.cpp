#include "TListNode.h"

std::ostream& operator<<(std::ostream& os, const TListNode& node)
{
    os << node.val;

    if (node.id / 100)
    {
        os << "x^" << node.id / 100;
    }
    if ((node.id % 10) / 10)
    {
        os << "y^" << (node.id % 10) / 10;
    }
    if (node.id % 10)
    {
        os << "z^" << (node.id % 10);
    }
    return os;
}
