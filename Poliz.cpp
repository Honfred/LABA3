//
// Created by nabax on 25.11.22.
//

#include "Poliz.h"

void Poliz::MadeTableOperation() {
    Table_Operation = Ttable(6);
    Table_Operation.Add(TRecord("+", 1));
    Table_Operation.Add(TRecord("-", 1));
    Table_Operation.Add(TRecord("*", 2));
    Table_Operation.Add(TRecord("/", 2));
    Table_Operation.Add(TRecord("^", 3));
}

void Poliz::WorkLeft() {
    Opstack.add(TRecord("(", 0));
}

void Poliz::WorkRight() {
    while ((Opstack.IsEmpty() == 0) && (Opstack.top().getName() != "("))
    {
        mem[count_mem++] = Opstack.get().getName();
    }
    if (Opstack.top().getName() == "(")
    {
        Opstack.get();
    }
}

void Poliz::WorkOperation(string st, int pr) {
    while ((Opstack.IsEmpty() == 0) && (Opstack.top().getValue() >= pr))
    {
        mem[count_mem++] = Opstack.get().getName();
    }
    Opstack.add(TRecord(st, pr));
}

void Poliz::WorkOperand(string st) {
    mem[count_mem++] = st;
    if (st[0] >= '0' && st[0] <= '9')
    {

        Table_Operand->Add(TRecord (st, stoi(st)));
    } else
    {
        Table_Operand->Add(TRecord (st, 0));
    }
}

void Poliz::WorkEnd() {
    while (Opstack.IsEmpty() == 0)
    {
        mem[count_mem++] = Opstack.get().getName();
    }
}

void Poliz::MadePoliz(string str) {
    count_mem = 0;
    for (int i = 0; i < lex->length(); ++i) {
        if (lex[i] == "(")
        {
            WorkLeft();
        } else {
            if (lex[i] == ")")
            {
                WorkRight();
            } else {
                int l = Table_Operation.Search(lex[i]);
                if (l > 0 && l <= 3)
                {
                    WorkOperation(lex[i], l);
                } else {
                    WorkOperand(lex[i]);
                }
            }
        }
    }
    WorkEnd();
}

void Poliz::StringToWord(string str, string *_lex, int _count_lex) {

}
// '+-*/^() ',
Poliz::Poliz(string tmp) {
    size_mem = tmp.length();
    count_mem = 0;
    mem = new string[size_mem];
    size_lex = size_mem;
    StringToWord(tmp, lex, count_lex);
    MadeTableOperation();
    Opstack = TStack<TRecord>(20);
    MadePoliz(tmp);
}

Poliz::Poliz(const Poliz &tmp) {
    size_mem = tmp.size_mem;
    count_mem = tmp.count_mem;
    mem = new string[size_mem];
    for (int i = 0; i < size_mem; i++)
    {
        mem[i] = tmp.mem[i];
    }
    lex = new string[size_mem];
    Table_Operation = tmp.Table_Operation;
    Opstack = tmp.Opstack;
    Table_Operand = tmp.Table_Operand;
}

Poliz::~Poliz() {
    delete[]mem;
    delete[]lex;
    delete Table_Operand;
}

Poliz &Poliz::operator=(Poliz tmp) {
    if (size_mem != tmp.size_mem)
    {
        if (size_mem != 0)
        {
            delete[]mem;
        }
        size_mem = tmp.size_mem;
        mem = new string[size_mem];
    }
    count_mem = tmp.count_mem;
    for (int i = 0; i < size_mem; i++)
    {
        mem[i] = tmp.mem[i];
    }
    lex = new string[size_mem];
    Table_Operation = tmp.Table_Operation;
    Opstack = tmp.Opstack;
    Table_Operand = tmp.Table_Operand;
    return *this;
}

int Poliz::GetCount() {
    return count_mem;
}

string Poliz::operator[](int k) {
    if ((k >= 0)&&(k < count_mem))
    {
        return mem[k];
    }
    else
    {
        return " ";
    }
}

string Poliz::GetPoliz() {
    string str = "";
    for (int i = 0; i < count_mem; i++)
    {
        str = str + mem[i] + " ";
    }
    return str;
}

Ttable *Poliz::GetTableOperand() {
    return Table_Operand;
}
