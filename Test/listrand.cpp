#include "listrand.h"


ListRand::ListRand()
{
    head = nullptr;
    tail = nullptr;
}

void ListRand::Serialize(FILE* file)
{
    int index = 0;
    ListNode* retPrev = nullptr;

    if(head == nullptr) return;

    fputc(count, file);
    fputc('\n', file);

    for (auto el = head; el != nullptr; el = el->next, index++)
    {
        fputs(el->data.c_str(), file);
        fputc('\n', file);
        *reinterpret_cast<int*> (&(el->prev)) = index;
    }

    for (auto el = head; el != nullptr; el = el->next)
    {
        if (el->rand != nullptr)
            index = *reinterpret_cast<int*> (&(el->rand->prev));
        else
            index = 0;
        fputc(index, file);
        fputc('\n', file);
    }

    for (auto el = head; el != nullptr; el = el->next)
    {
        el->prev = retPrev;
        retPrev = el;
    }
}

void ListRand::Deserialize(FILE* file)
{
    std::string data;
    char buf[225];
    int index, i;
    ListNode* tmp;

    int numLines = fgetc(file);
    if (numLines == 0) return;

    fseek(file, 1, SEEK_CUR);

    for (i = 0; i < numLines; i++)
    {
        int j = -1;
        do
        {
            j++;
            buf[j] = fgetc(file);
        } while (buf[j] != '\n');
        buf[j] = '\0';
        data = buf;
    }

    i = 0;
    for (auto el = head; el != nullptr; el = el->next)
    {
        tmp = el;
        index = fgetc(file);
        fseek(file, 1, SEEK_CUR);
        if (index != 0)
        {
            if (index > i)
                for (int j = 0; j < index; j++)
                    tmp = tmp->next;
            else
                for (int j = index; j < i; j++)
                    tmp = tmp->prev;
            el->rand = tmp;
        }
        i++;
    }
}

void ListRand::AddElement(std::string data)
{
    ListNode* newNode = new ListNode;
    newNode->next = nullptr;
    newNode->data = data;
    count++;

    if (head != nullptr)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

        if (tail->prev != nullptr)
            newNode->rand = tail->prev;
        else
            newNode->rand = nullptr;
    }
    else
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        newNode->rand = nullptr;
        head = tail = newNode;
    }
}

void ListRand::GetRand()
{
    for (auto el = head; el != nullptr; el = el->next)
    {
        if (el->rand != nullptr)
            std::cout << (el->rand->data).c_str() << std::endl;
        else
            std::cout << "nullptr" << std::endl;
    }
}
