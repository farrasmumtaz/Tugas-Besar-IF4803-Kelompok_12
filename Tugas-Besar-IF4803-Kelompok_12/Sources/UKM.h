#ifndef UKM_H
#define UKM_H
#include <iostream>
using namespace std;

struct elemenMhs; //forward declaration dari elemenMhs agar bisa digunakan di UKM.h
typedef struct elemenMhs *adrMhs;

//infotype ukm berupa string (nama UKM)
typedef string InfotypeUKM;

typedef struct elmenUKM *AddressUKM;
struct elmenUKM {   
    InfotypeUKM info;
    AddressUKM next;
};

bool isEmptyUKM_1Mhs(adrMhs p);
AddressUKM createElementUKM(InfotypeUKM x);
void insertFirstUKM(adrMhs p, AddressUKM q);
void insertLastUKM(adrMhs p, AddressUKM q);
void insertAfterUKM(adrMhs p, AddressUKM q, AddressUKM prec);
void deleteFirstUKM(adrMhs p, AddressUKM &q);
void deleteLastUKM(adrMhs p, AddressUKM &q);
void deleteAfterUKM(adrMhs p, AddressUKM &q, AddressUKM prec);
//mencari UKM dalam daftar UKM seorang mahasiswa
AddressUKM searchUKM(adrMhs p, InfotypeUKM x);
//menampilkan daftar UKM yang diikuti oleh seorang mahasiswa
void printInfoUKM_1Mhs(adrMhs p);
#endif

