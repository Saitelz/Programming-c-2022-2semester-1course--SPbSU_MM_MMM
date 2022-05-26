#include "LinkedListLib.h"

std::ostream& operator<<(std::ostream& stream, const Node& node)
{
    stream << node.data;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
    stream << "[" << list.count << "] : { ";
    Node* var = list.head;
    while (var != nullptr)
    {
        stream << *var << " ";
        var = var->next;
    }
    stream << "}";

    return stream;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        popHead();
    }
}

void LinkedList::pushHead(int element)
{
    head = new Node(element, head);

    if (tail == nullptr)
    {
        tail = head;
    }

    ++count;
}

void LinkedList::pushTail(int element)
{
    if (tail == nullptr)
    {
        return pushHead(element);
    }

    tail->next = new Node(element);
    tail = tail->next;

    ++count;
}

void LinkedList::insert(int element, int index)
{
    if (index == count)
    {
        return pushTail(element);
    }
    if (index == 0)
    {
        return pushHead(element);
    }

    Node* var = head;

    for (int i = 0; i < index - 1; ++i)
    {
        var = var->next;
    }

    var->next = new Node(element, var->next);

    ++count;
}

int LinkedList::extract(int index)
{
    if (index == 0)
    {
        return popHead();
    }
    if (index == count)
    {
        return popTail();
    }

    Node* var = head;

    for (int i = 0; i < index - 1; ++i)
    {
        var = var->next;
    }

    Node* k = var->next;

    int toReturn = k->data;

    var->next = k->next;
    k->~Node();

    --count;

    return toReturn;
}

void LinkedList::swap(int index1, int index2)
{
    Node *var1 = (*this)[index1];
    Node *var2 = (*this)[index2];

    int val = var1->data;

    var1->data = var2->data;
    var2->data = val;
}

int LinkedList::popHead()
{
    if (head == nullptr)
    {
        return 0;
    }

    --count;

    Node* var = head;

    int value = head->data;
    head = head->next;

    delete var;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    return value;
}

int LinkedList::popTail()
{
    if (tail == nullptr)
    {
        return 0;
    }
    if (head == tail)
    {
        return popHead();
    }

    Node* var = head;

    while (var->next != tail)
    {
        var = var->next;
    }

    --count;

    int value = tail->data;

    delete tail;

    tail = var;
    tail->next = nullptr;

    return value;
}

Node*& LinkedList::operator[](int pos)
{
    Node* var = this->head;

    for (int i = 0; i < pos; ++i)
    {
        var = var->next;
    }

    return var;
}