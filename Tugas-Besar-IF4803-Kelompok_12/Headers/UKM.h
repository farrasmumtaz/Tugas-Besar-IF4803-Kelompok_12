#include <iostream>
#include <string>
using namespace std;
typedef string InfotypeUKM;
typedef elmenUKM AddressUKM;
struct elmenUKM {
    InfotypeUKM info;
    AddressUKM next;
};

struct ListUKM {
    AddressUKM first;
};