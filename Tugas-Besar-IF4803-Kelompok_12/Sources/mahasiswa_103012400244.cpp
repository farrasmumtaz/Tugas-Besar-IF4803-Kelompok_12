#include "Mahasiswa.h"
#include "main.h"

void createListMhs(listMhs &L)
{
    L.first = nullptr;
    L.last = nullptr;
}
// fungsi untuk membuat elemen mahasiswa
adrMhs createElemenMhs(string namaMhs, int nimMhs)
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
    cout << "========= Daftar Mahasiswa ===========\n";
    while (p != nullptr)
    {
        cout << "Nama Mahasiswa: " << p->info.namaMhs << "(" << p->info.nimMhs << ")\n";
        p = p->next;
    }
    cout << "====================================\n";
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

void displayUKMmahasiswaDenganUKMTerbanyak(listMhs L){
    adrMhs p;
    AddressUKM q;
    int maxUKM = 0;
    p = L.first;
    while (p != nullptr) {
        int temp = 0;
        q = p->firstUKM;
        while (q != nullptr) {
            temp++;
            q = q->next;
        }
        if (temp > maxUKM) {
            maxUKM = temp;
        }
        p = p->next;
    }

    if (maxUKM > 0) {
        cout << "Mahasiswa dengan UKM terbanyak adalah:\n ";
        p = L.first;
        while (p != nullptr) {
            int temp = 0;
            q = p->firstUKM;
            while (q != nullptr) {
                temp++;
                q = q->next;
            }
            if (temp == maxUKM) {
                cout << p->info.namaMhs << "(" << p->info.nimMhs << ")" << endl;
                q = p->firstUKM;
                while (q != nullptr) {
                    cout << " - " << q->info << "\n";
                    q = q->next;
                }
            }
            p = p->next;
        }
    } else {
        cout << "Tidak ada mahasiswa yang mengikuti UKM.\n";
    }
}

bool validasiNim(int nimMhs){
    if (cin.fail() || cin.peek()!='\n' || nimMhs<=0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "NIM tidak valid!\n";
        return false;
    }
    return true;
}

bool validasiInput(int x) {
    if (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid!\n";
        return false;
    }
    return true;
}