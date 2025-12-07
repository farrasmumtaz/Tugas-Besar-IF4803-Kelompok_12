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
AddressUKM createListUKM(InfotypeUKM x);
void insertLastUKM(ListUKM &  L, AddressUKM P);
void printInfoUKM(ListUKM L);
#endif

