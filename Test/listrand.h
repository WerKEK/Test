#ifndef LISTRAND_H
#define LISTRAND_H

#include <QObject>
#include <listnode.h>
#include <iostream>


class ListRand
{
public:
    ListRand();

    ListNode* head;
    ListNode* tail;

    int count;

    void Serialize(FILE*);
    void Deserialize(FILE*);

    void AddElement(std::string);
    void GetRand();


};

#endif // LISTRAND_H
