//
// Created by nabax on 18.11.22.
//

#include <string>
#include "Ttable.h"

int Ttable::getNumber(string key) {
    int l = -1;
    int i = 0;
    while ((l == -1) && (i < count)){
        if (key == mem[i].getName()){
            l = i;
        }
        i++;
    }
    return l;
}

Ttable::Ttable(int _size) {
    size = _size;
    count = 0;

    mem = new TRecord[size];
    for (int i = 0; i < size; ++i) {
        mem[i] = TRecord("", 0);
    }
}

Ttable::Ttable(const Ttable &tmp) {
    size = tmp.size;
    count = tmp.count;

    mem = new TRecord[size];
    for (int i = 0; i < size; ++i) {
        mem[i] = tmp.mem[i];
    }
}

Ttable::~Ttable() {
    if (size != 0){
        delete[]mem;
    }
}

Ttable &Ttable::operator=(const Ttable& tmp) {
    if (size != tmp.size){
        if (size != 0){
            delete[]mem;
        }
        size = tmp.size;
        mem = new TRecord[size];
    }
    count = tmp.count;
    for (int i = 0; i < size; i++) {
        mem[i] = tmp.mem[i];
    }
}

void Ttable::Add(TRecord tmp) {
    int l = getNumber(tmp.getName());
    if (l == -1){
        mem[count++] = tmp;
    }
    else {
        mem[l] = tmp;
    }
}

void Ttable::Del(TRecord tmp) {
    int l = getNumber(tmp.getName());
    if (l > 0){
        mem[l] = mem[--count];
    }
}

int Ttable::Search(string Key) {
    int l = getNumber(Key);
    if (l > 0){
        return mem[l].getValue();
    } else{
        return -1;
    }
}

int Ttable::IsEmpty() {
    if (count == 0){
        return  0; // Пусто
    } else {
        return 1;  // Не пусто
    }
}

int Ttable::IsFall() {
    if (count == size){
        return 1;
    } else {
        return 0;
    }
}

int Ttable::getCount() {
    return count;
}

TRecord Ttable::operator[](int k) {
    if ((k >= 0) && (k < count)){
        return mem[k];
    } else {
        return TRecord("", 0);
    }
}
