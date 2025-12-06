#ifndef UKM_H
#define UKM_H
#include <iostream>
using namespace std;
typedef string   InfotypeUKM;
typedef struct elmenUKM *AddressUKM;
struct elmenUKM {
    InfotypeUKM info;
    AddressUKM next;
};

struct ListUKM {
    AddressUKM first;
};

void createListUKM_c103012400197(ListUKM &L);
AddressUKM isEmptyUKM_103012400197(ListUKM L);
AddressUKM createElementUKM_103012400197(InfotypeUKM x);
void insertLastUKM_103012400197(ListUKM &  L, AddressUKM P);
void printInfoUKM_103012400197(ListUKM L);
#endif