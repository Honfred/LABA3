//
// Created by nabax on 18.11.22.
//

#ifndef TEST_TSTACK_H
#define TEST_TSTACK_H

#pragma once

#include <string>

using namespace std;

template<typename T>
class TStack
{
private:
    T* mem;
    int size;
    int count;
public:
    TStack(int _size = 0)
    {
        size = _size;
        count = 0;
        mem = new T[size];
        for (int i = 0; i < size; i++)
        {
            mem[i] = T(0);
        }
    }
    TStack(const TStack& tmp)
    {
        size = tmp.size;
        count = tmp.count;
        mem = new T[size];
        for (int i = 0; i < size; i++)
        {
            mem[i] = tmp.mem[i];
        }
    }
    ~TStack()
    {
        if (size != 0)
        {
            delete[]mem;
        }
    }
    TStack<T>& operator=(const TStack<T> &tmp)
    {
        if (size != tmp.size)
        {
            if (size != 0)
            {
                delete[]mem;
            }
            size = tmp.size;
            mem = new T[size];
        }
        count = tmp.count;
        for (int i = 0; i < size; i++)
        {
            mem[i] = tmp.mem[i];
        }
        return *this;
    }
    void add(T tmp)
    {
        if (count < size)
        {
            mem[count++] = tmp;
        }
    }
    T get()
    {
        if (count > 0)
        {
            return mem[--count];
        }
    }
    T top()
    {
        if (count > 0)
        {
            return mem[count - 1];
        }
    }
    int IsEmpty()
    {
        if (count == 0)
        {
            return 1; //Стек пуст
        }
        else
        {
            return 0; //Стек не пуст
        }
    }
    T IsFull()
    {
        if (count == size)
        {
            return 1; //Стек полон
        }
        else
        {
            return 0; //Стек не полон
        }
    }

};

#endif //TEST_TSTACK_H
