S
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
