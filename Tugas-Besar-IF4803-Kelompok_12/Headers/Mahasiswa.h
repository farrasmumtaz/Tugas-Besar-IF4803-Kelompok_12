#ifndef MAHASISWA_H
#define MAHASISWA_H
#include "UKM.h"
#include <iostream>
using namespace std;

typedef struct elemenMhs *adrMhs;

struct Mahasiswa
{
    string namaMhs;
    string nimMhs;
};

struct elemenMhs
{
    Mahasiswa info;
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
adrMhs createElemenMhs(string namaMhs, string nimMhs);
bool isEmptyMhs(listMhs L);

void insertFirstParent(listMhs &L, adrMhs p);
void insertLastParent(listMhs &L, adrMhs p);
void insertAfterParent(listMhs &L, adrMhs p, adrMhs prec);

void deleteFirstParent(listMhs &L, adrMhs &p);
void deleteLastParent(listMhs &L, adrMhs &p);
void deleteAfterParent(listMhs &L, adrMhs &p, adrMhs prec);

adrMhs searchMhs(listMhs L, string nimMhs);
void displayMhs(listMhs L);
int totalMahasiswa(listMhs L);
int totalUKM(listMhs L, string nimMhs);
#endif