#ifndef UKM_H
#define UKM_H
#include <iostream>
using namespace std;

struct elemenMhs; //forward declaration
typedef struct elemenMhs *adrMhs;

//infotype ukm berupa string (nama UKM)
typedef string InfotypeUKM;

typedef struct elmenUKM *AddressUKM;
struct elmenUKM {   
    InfotypeUKM info;
    AddressUKM next;
};

//mengecek apakah UKM seorang mahasiswa kosong
bool isEmptyUKM_1Mhs(adrMhs p);
//membuat elemen UKM
AddressUKM createElementUKM(InfotypeUKM x);
//menyisipkan UKM di awal daftar UKM seorang mahasiswa
void insertFirstUKM(adrMhs p, AddressUKM q);
//menyisipkan UKM di akhir daftar UKM seorang mahasiswa
void insertLastUKM(adrMhs p, AddressUKM q);
//menyisipkan UKM setelah elemen tertentu dalam daftar UKM seorang mahasiswa
void insertAfterUKM(adrMhs p, AddressUKM q, AddressUKM prec);
//menghapus UKM pertama dalam daftar UKM seorang mahasiswa
void deleteFirstUKM(adrMhs p, AddressUKM &q);
//menghapus UKM terakhir dalam daftar UKM seorang mahasiswa
void deleteLastUKM(adrMhs p, AddressUKM &q);
//menghapus UKM setelah elemen UKM tertentu dalam daftar UKM seorang mahasiswa
void deleteAfterUKM(adrMhs p, AddressUKM &q, AddressUKM prec);
//mencari UKM dalam daftar UKM seorang mahasiswa
AddressUKM searchUKM(adrMhs p, InfotypeUKM x);
//menampilkan daftar UKM yang diikuti oleh seorang mahasiswa
void printInfoUKM_1Mhs(adrMhs p);
#endif

