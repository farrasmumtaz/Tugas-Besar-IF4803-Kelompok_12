#include "Mahasiswa.h"

void createListMhs(listMhs &L)
{
    L.first = nullptr;
    L.last = nullptr;
}
// fungsi untuk membuat elemen mahasiswa
adrMhs createElemenMhs(string namaMhs, string nimMhs)
{
    adrMhs p;
    p = new elemenMhs;
    p->info.namaMhs = namaMhs;
    p->info.nimMhs = nimMhs;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstUKM = nullptr;
    return p;
}
// fungsi untuk mengecek apakah list mahasiswa kosong
bool isEmptyMhs(listMhs L)
{
    return L.first == nullptr && L.last == nullptr;
}
// fungsi untuk memasukkan elemen mahasiswa di awal list
void insertFirstParent(listMhs &L, adrMhs p)
{
    if (isEmptyMhs(L))
    {
        L.first = p;
        L.last = p;
    }
    else
    {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}
// fungsi untuk memasukkan elemen mahasiswa di akhir list
void insertLastParent(listMhs &L, adrMhs p)
{
    if (isEmptyMhs(L))
    {
        L.first = p;
        L.last = p;
    }
    else
    {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}
// fungsi untuk memasukkan elemen mahasiswa setelah elemen tertentu
void insertAfterParent(listMhs &L, adrMhs p, adrMhs prec)
{
    if (prec == L.last)
    {
        insertLastParent(L, p);
    }
    else
    {
        p->next = prec->next;
        p->prev = prec;
        prec->next = p;
        p->next->prev = p;
    }
}
// fungsi untuk menampilkan daftar mahasiswa
void displayMhs(listMhs L)
{
    adrMhs p = L.first;
    cout << "====== Daftar Mahasiswa ======\n";
    while (p != nullptr)
    {
        cout << "Nama Mahasiswa: " << p->info.namaMhs << "(" << p->info.nimMhs << ")\n";
        p = p->next;
    }
    cout << "==============================\n";
}
//fungsi untuk menghitung total mahasiswa
int totalMahasiswa(listMhs L)
{
    int i = 0;
    adrMhs q = L.first;
    while (q != nullptr)
    {
        i++;
        q = q->next;
    }
    return i;
}
