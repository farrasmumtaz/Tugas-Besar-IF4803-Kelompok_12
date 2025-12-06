#ifndef UKM_H
#define UKM_H
#include <iostream>
using namespace std;
typedef string   InfotypeUKM;
<<<<<<< HEAD
typedef struct elmenUKM *AddressUKM;
=======
typedef elmenUKM AddressUKM;
>>>>>>> benarkan
struct elmenUKM {
    InfotypeUKM info;
    AddressUKM next;
};

struct ListUKM {
    AddressUKM first;
};

<<<<<<< HEAD
void createListUKM_c103012400197(ListUKM &L);
AddressUKM isEmptyUKM_103012400197(ListUKM L);
AddressUKM createElementUKM_103012400197(InfotypeUKM x);
void insertLastUKM_103012400197(ListUKM &  L, AddressUKM P);
void printInfoUKM_103012400197(ListUKM L);
#endif
=======
void createListUKM(ListUKM &L);
AddressUKM isEmptyUKM(ListUKM L);
AddressUKM createListUKM(InfotypeUKM x);
void insertLastUKM_103012400197(ListUKM &  L, AddressUKM P);
void printInfoUKM_103012400197(ListUKM L);
>>>>>>> benarkan
