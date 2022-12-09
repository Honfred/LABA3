//
// Created by nabax on 25.11.22.
//

#ifndef TEST_POLIZ_H
#define TEST_POLIZ_H

#include <string>
#include "TRecord.h"
#include "TStack.h"
#include "Ttable.h"

class Poliz {
    string *mem;
    int size_mem;
    int count_mem;

    string *lex;
    int size_lex;
    int count_lex;

    TStack<TRecord> Opstack;
    Ttable Table_Operation;
    Ttable* Table_Operand;

    void MadeTableOperation();
    void WorkLeft();
    void WorkRight();
    void WorkOperation(string st, int pr);
    void WorkOperand(string st);
    void WorkEnd();
    void MadePoliz(string str);
    void StringToWord(string str, string *_lex, int _count_lex);


public:
    Poliz(string tmp = "");
    Poliz(const Poliz&tmp);
    ~Poliz();

    Poliz&operator=(Poliz tmp);

    int GetCount();
    string operator[](int k);
    string GetPoliz();
    Ttable* GetTableOperand();
};


#endif //TEST_POLIZ_H
