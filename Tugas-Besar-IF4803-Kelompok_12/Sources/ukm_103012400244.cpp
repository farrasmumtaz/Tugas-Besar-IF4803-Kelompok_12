#include "UKM.h"
#include <iostream>
using namespace std;

void insertFirstUKM(ListUKM &L, AddressUKM p){
    if (isEmptyUKM(L)){
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void insertAfterUKM(ListUKM &L, AddressUKM p, AddressUKM prec){
    if (prec->next == nullptr){
        insertLastUKM(L,p);
    } else {
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirstUKM(ListUKM &L, AddressUKM &p){
    if (isEmptyUKM(L)){
        cout << "List Kosong\n";
        p = nullptr;
    } else if (L.first->next == nullptr){
        p = L.first;
        L.first = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastUKM(ListUKM &L, AddressUKM &p){
    if (isEmptyUKM(L)){
        cout << "List Kosong\n";
        p = nullptr;
    } else if (L.first->next == nullptr){
        p = L.first;
        L.first = nullptr;
    } else {
        AddressUKM q = L.first;
        while (q->next->next != nullptr){
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

void deleteAfterUKM(ListUKM &L, AddressUKM &p, AddressUKM prec){
    if (prec->next->next == nullptr){
        p = prec->next;
        prec->next = nullptr;
    } else {
        //cek lgi nanti
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

AddressUKM searchUKM(ListUKM &L, string x){
    AddressUKM q = L.first;
    while (q->info != x && q != nullptr){
        q = q->next;
    }
    return q;
}