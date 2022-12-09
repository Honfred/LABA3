//
// Created by nabax on 09.12.22.
//

#ifndef TEST_MAIN_FUNCTIONS_H
#define TEST_MAIN_FUNCTIONS_H

#include <iostream>
#include "TStack.h"
#include "Ttable.h"

void main_stack(){
    int sizeA = 5, sizeB = 7;

    TStack<int> A(sizeA);
    TStack<int> B(sizeB);

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.IsEmpty() << endl;
    cout << "B = " << B.IsEmpty() << endl << endl;

    for (int i = 0; !(A.IsFull()); i++)
    {
        cout << i << " ";
        A.add(i);
    }
    cout << endl;
    cout << endl;

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.IsEmpty() << endl;
    cout << "B = " << B.IsEmpty() << endl << endl;

    B = A;
    cout << "Стек В: " << endl;
    for (int i = 0; !(B.IsEmpty()); i++)
    {
        cout << B.get() << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.IsEmpty() << endl;
    cout << "B = " << B.IsEmpty() << endl << endl;
    cout << "Стек полон: " << endl;
    cout << "A = " << A.IsFull() << endl;
    cout << "B = " << B.IsFull() << endl << endl;

    cout << "Top A: " << endl;
    cout << "A = " << A.top() << endl << endl;

    cout << "get(pop) A: " << endl;
    cout << "A = " << A.get() << endl << endl;
    TStack<int>F(A);
    cout << "Стек В: " << endl;
    while (A.IsEmpty() != 1)
    {
        cout << A.get() << " ";
    }


    while (F.IsEmpty() != 1)
    {
        cout << F.get() << " ";
    }
}
void main_table(){
    int N = 5;

    TRecord recA("a", 3);
    TRecord recB("b", 2);

    Ttable A(N);
    Ttable B;

    A.Add(recA);
    A.Add(recB);

    B = A;
    cout << "B = A" << endl;
    for (int i = 0; i < A.getCount(); i++)
    {
        cout << A[i].getName() << " " << A[i].getValue() << endl;
    }

    B.Add(TRecord("c", 5));
    cout << endl;

    cout << "B add 'c'" << endl;
    for (int i = 0; i < B.getCount(); i++)
    {
        cout << B[i].getName() << " " << B[i].getValue() << endl;
    }
    cout << endl;


    Ttable C(A);
    cout << "C(A)" << endl;
    for (int i = 0; i < C.getCount(); i++)
    {
        cout << C[i].getName() << " " << C[i].getValue() << endl;
    }

    B.Del("b");
    for (int i = 0; i < B.getCount(); i++)
    {
        cout << B[i].getName() << " " << B[i].getValue() << endl;
    }
}

#endif //TEST_MAIN_FUNCTIONS_H
