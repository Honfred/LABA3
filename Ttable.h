//
// Created by nabax on 18.11.22.
//

/* Операции в таблице:
 * 1) Положить
 * 2) Удалить
 * 3) По ключу выдать информацию
 * 4) Контроль пустоты
 * 5) Контроль полноты
 * 6) GetCount
 * 7) [ ]
 * 8) Поиск приватный
*/

#ifndef TEST_TTABLE_H
#define TEST_TTABLE_H

#include <string>
#include "TRecord.h"

using namespace std;

class Ttable {
private:
    TRecord *mem;
    int count;
    int size;
    int getNumber(string Key);

public:
    Ttable(int _size = 0);
    Ttable(const Ttable &tmp);
    ~Ttable();
    Ttable &operator=(const Ttable& tmp);

    void Add(TRecord tmp);
    void Del(string tmp);
    int Search(string Key);
    int IsEmpty();
    int IsFall();
    int getCount();
    TRecord operator[](int k);
};


#endif //TEST_TTABLE_H
