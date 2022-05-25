#include "ArrayListLib.h"
#include <iostream>

void ArrayList::expand(int count)
{
    int* newdata = new int[count + this->capacity];

    for (int i = 0; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i];
    }

    delete[] this->data;
    this->data = newdata;
    this->capacity += count;
}

void ArrayList::swap(int posi, int posj)
{
    int var = this->data[posi];

    this->data[posi] = this->data[posj];
    this->data[posj] = var;
}

int ArrayList::ind(int index)
{
    if (index < 0)
    {
        pushbegin(0);
        return 0;
    }

    if (index >= this->count)
    {
        pushend(0);
        return this->count - 1;
    }

    return index;
}

ArrayList::ArrayList(int capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->data = new int[capacity];
}

ArrayList::ArrayList(const ArrayList& list)
{
    this->capacity = list.count;
    this->count = list.count;
    this->data = new int[list.count];

    for (int i = 0; i < list.count; ++i)
    {
        this->data[i] = list.data[i];
    }
}

ArrayList::~ArrayList()
{
    for (int i = 0; i < this->capacity; ++i)
    {
        this->data[i] = 0;
    }

    this->count = 0;
    this->capacity = 0;

    delete[] this->data;
}

int ArrayList::size()
{
    return this->count;
}

void ArrayList::pushend(int element)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }

    this->data[this->count] = element;
    this->count++;
}

void ArrayList::insert(int element, int position)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->count++;

    for (int i = this->count - 1; i > position; --i)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[position] = element;
}

void ArrayList::pushbegin(int element)
{
    this->insert(element, 0);
}


int ArrayList::extract(int position)
{
    int ans = this->data[position];

    this->count--;
    for (int i = position; i < this->count; ++i)
    {
        this->data[i] = this->data[i + 1];
    }
    this->data[this->count] = 0;

    return ans;
}

int ArrayList::extractbegin()
{
    return extract(0);
}

int ArrayList::extractend()
{
    this->count--;
    int var = this->data[this->count];
    this->data[this->count] = 0;

    return var;
}


int& ArrayList::operator[](int pos)
{
    return data[ind(pos)];
}

ArrayList merge(ArrayList l, ArrayList r)
{
    if (l.size() == 0)
    {
        return r;
    }
    else if (r.size() == 0)
    {
        return l;
    }

    ArrayList ans(l.size() + r.size());

    int i = 0;
    int j = 0;

    while ((i != l.size()) || (j != r.size()))
    {
        if ((j == r.size()) || ((i != l.size()) && (l[i] <= r[j])))
        {
            ans.pushend(l[i]);
            i++;
        }
        else
        {
            ans.pushend(r[j]);
            j++;
        }
    }

    return ans;
}

ArrayList quickSort(ArrayList arr)
{
    int l = 0;
    int r = arr.size();

    if (r - l == 1)
    {
        ArrayList var(1);
        var.pushend(arr[l]);
        return var;
    }

    int mid = ((l + r) >> 1);

    ArrayList arr_l(mid);
    ArrayList arr_r(r - mid);

    for (int i = 0; i < mid; ++i)
    {
        arr_l.pushend(arr[i]);
    }
    for (int i = mid; i < r; ++i)
    {
        arr_r.pushend(arr[i]);
    }

    return merge(quickSort(arr_l), quickSort(arr_r));
}



void ArrayList::sort()
{
    ArrayList var(quickSort(*this));

    for (int i = 0; i < var.count; ++i)
    {
        this->data[i] = var.data[i];
    }
}

std::ostream& operator<<(std::ostream& stream, ArrayList& list)
{
    stream << "[" << list.count << "/" << list.capacity << "] {";

    if (list.count == 0)
    {
        stream << "EMPTY";
    }
    else
    {
        for (int i = 0; i < list.count - 1; ++i)
        {
            stream << list.data[i] << ", ";
        }
        stream << list.data[list.count - 1];
    }

    stream << "}";

    return stream;
}