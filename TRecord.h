//
// Created by nabax on 18.11.22.
//

#ifndef TEST_TRECORD_H
#define TEST_TRECORD_H

#pragma once
#include <string>

using namespace std;
class TRecord
{
private:
    string name;
    int value;
public:
    TRecord(string _name = "", int _value = 0)
    {
        name = _name;
        value = _value;
    }
    void setvalue(int k)
    {
        value = k;
    }
    int getValue()
    {
        return value;
    }
    string getName()
    {
        return name;
    }
};

#endif //TEST_TRECORD_H
