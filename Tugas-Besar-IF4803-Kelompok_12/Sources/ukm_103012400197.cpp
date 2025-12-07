#include "UKM.h"
#include <iostream>
using namespace std;

void createListUKM(ListUKM &L) {
    L.first = nullptr;
}

AddressUKM isEmptyUKM(ListUKM L) {
    return L.first = nullptr;
}

AddressUKM createElementUKM(InfotypeUKM x) {
    AddressUKM p;
    p = new elmenUKM;
    p -> info = x;
    p -> next = nullptr;
    return p;
}

void insertLastUKM(ListUKM &L, AddressUKM p) {
    if (isEmptyUKM(L)) {
        L.first = p;
    } else {
        AddressUKM q = L.first;
        while (q -> next != nullptr) {
            q = q -> next;
        }
        q -> next = p;
    }
}

void printInfoUKM(ListUKM L) {
    AddressUKM p = L.first;
    while (p != nullptr) {
        cout << "- " << p -> info << endl;
        p = p -> next;
    }
}