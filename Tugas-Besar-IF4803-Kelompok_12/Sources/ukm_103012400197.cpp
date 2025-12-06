#include "UKM.h"
#include <iostream>
using namespace std;

void createListUKM_103012400197(ListUKM &L) {
    L.first = nullptr;
}

AddressUKM isEmptyUKM_103012400197(ListUKM L) {
    return L.first = nullptr;
}

AddressUKM createElementUKM_103012400197(InfotypeUKM x) {
    AddressUKM p;
    p = new elmenUKM;
    p -> info = x;
    p -> next = nullptr;
    return p;
}

void insertLastUKM_103012400197(ListUKM &L, AddressUKM p) {
    if (isEmptyUKM_103012400197(L)) {
        L.first = p;
    } else {
        AddressUKM q = L.first;
        while (q -> next != nullptr) {
            q = q -> next;
        }
        q -> next = p;
    }
}

void printInfoUKM_103012400197(ListUKM L) {
    AddressUKM p = L.first;
    while (p != nullptr) {
        cout << "- " << p -> info << endl;
        p = p -> next;
    }
}