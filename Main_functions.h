//
// Created by nabax on 09.12.22.
//

#ifndef TEST_MAIN_FUNCTIONS_H
#define TEST_MAIN_FUNCTIONS_H

#include <iostream>
#include "TStack.h"

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

    cout << "Стек В: " << endl;
    while (A.IsEmpty() != 1)
    {
        cout << A.get() << " ";
    }
}


#endif //TEST_MAIN_FUNCTIONS_H
