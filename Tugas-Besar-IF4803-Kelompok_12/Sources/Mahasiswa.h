#ifndef MAHASISWA_H
#define MAHASISWA_H
#include "UKM.h"
#include <iostream>
using namespace std;


typedef struct elemenMhs *adrMhs;
typedef struct Mahasiswa InfotypeMhs;
struct Mahasiswa
{
    string namaMhs;
    int nimMhs;
};

struct elemenMhs
{
    InfotypeMhs info;
    adrMhs next;
    adrMhs prev;
    AddressUKM firstUKM;
};

struct listMhs
{
    adrMhs first;
    adrMhs last;
};

void createListMhs(listMhs &L);
adrMhs createElemenMhs(string namaMhs, int nimMhs);
bool isEmptyMhs(listMhs L);

void insertFirstParent(listMhs &L, adrMhs p);
void insertLastParent(listMhs &L, adrMhs p);
void insertAfterParent(listMhs &L, adrMhs p, adrMhs prec);

void deleteFirstParent(listMhs &L, adrMhs &p);
void deleteLastParent(listMhs &L, adrMhs &p);
void deleteAfterParent(listMhs &L, adrMhs &p, adrMhs prec);

adrMhs searchMhs(listMhs L, int nimMhs);
void displayMhs(listMhs L);
int totalMahasiswa(listMhs L);
int totalUKM_1Mhs(listMhs L, int nimMhs);

void menuTambahMahasiswa(listMhs &L);
void menuHapusMahasiswa(listMhs &L);
void menuCariMhsUKMTerbanyak(listMhs &L);
void MahasiswaUKMTerbanyak(listMhs L);
void menuTambahUKM(listMhs &L);
void menuHapusUKM(listMhs &L);
void displayUKMmahasiswaDenganUKMTerbanyak(listMhs L);

bool validasiNim(int nimMhs);
void tampilSemuaUKMdenganMahasiswa(listMhs L);
void dataDummy(listMhs &L);

#endif