#ifndef UKM_H
#define UKM_H
#include <iostream>
using namespace std;

typedef string InfotypeUKM;
typedef struct elmenUKM *AddressUKM;
struct elmenUKM {   
    InfotypeUKM info;
    AddressUKM next;
};

struct ListUKM {
    AddressUKM first;
};

void createListUKM(ListUKM &L);
AddressUKM isEmptyUKM(ListUKM L);
AddressUKM createElementUKM(InfotypeUKM x);
void insertFirstUKM(ListUKM &L, AddressUKM p);
void insertLastUKM(ListUKM &  L, AddressUKM P);
void insertAfterUKM(ListUKM &L, AddressUKM p, AddressUKM prec);
void deleteFirstUKM(ListUKM &L, AddressUKM &p);
void deleteLastUKM(ListUKM &L, AddressUKM &p);
void deleteAfterUKM(ListUKM &L, AddressUKM &p, AddressUKM prec);
AddressUKM searchUKM(ListUKM &L, string x);
void printInfoUKM(ListUKM L);
#endif

