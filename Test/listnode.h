#ifndef LISTNODE_H
#define LISTNODE_H

#include <QObject>

class ListNode
{
public:
    ListNode();

    ListNode* next;
    ListNode* prev;
    ListNode* rand;

    std::string data;

};

#endif // LISTNODE_H
