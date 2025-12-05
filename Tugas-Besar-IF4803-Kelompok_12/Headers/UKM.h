#include <iostream>
using namespace std;
typedef string   InfotypeUKM;
typedef elmenUKM AddressUKM;
struct elmenUKM {
    InfotypeUKM info;
    AddressUKM next;
};

struct ListUKM {
    AddressUKM first;
};

void createListUKM_c103012400197(ListUKM &L);
AddressUKM isEmptyUKM_103012400197(ListUKM L);
AddressUKM createListUKM_103012400197(InfotypeUKM x);
void insertLastUKM_103012400197(ListUKM &  L, AddressUKM P);
void printInfoUKM_103012400197(ListUKM L);