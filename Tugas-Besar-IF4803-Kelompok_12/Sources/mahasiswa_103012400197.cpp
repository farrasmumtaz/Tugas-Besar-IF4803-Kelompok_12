#include "Mahasiswa.h"
// fungsi untuk menghapus elemen mahasiswa di awal list
void deleteFirstParent(listMhs &L, adrMhs &p) {
    if (L.first == nullptr && L.last == nullptr)
    {
        p = nullptr;
    }
    else if (L.first == L.last)
    {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }
    else
    {
        p = L.first;
        L.first = p->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}
// fungsi untuk menghapus elemen mahasiswa di akhir list
void deleteLastParent(listMhs &L, adrMhs &p) {
    if (L.first == nullptr && L.last == nullptr)
    {
        p = nullptr;
    }
    else if (L.first == L.last)
    {
        deleteFirstParent(L, p);
    }
    else
    {
        p = L.last;
        L.last = p->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}
// fungsi untuk menghapus elemen mahasiswa setelah elemen tertentu
void deleteAfterParent(listMhs &L, adrMhs &p, adrMhs prec) {
    if (prec != nullptr && prec->next != nullptr)
    {
        p = prec->next;
        prec->next = p->next;

        if (p->next != nullptr)
        {
            p->next->prev = prec;
        }
        else
        {
            L.last = prec;
        }

        p->next = nullptr;
        p->prev = nullptr;
    }
    else
    {
        p = nullptr;
    }
}
// fungsi untuk mencari elemen mahasiswa berdasarkan NIM
adrMhs searchMhs(listMhs L, int nimMhs) {
    adrMhs p = L.first;
    while (p != nullptr && p->info.nimMhs != nimMhs)
    {
        p = p->next;
    }
    return p;
}

// Menghitung total UKM yang diikuti oleh seorang mahasiswa
int totalUKM_1Mhs(listMhs L, int nimMhs) {
    int count = 0;
    adrMhs m = searchMhs(L, nimMhs);

    if (m == NULL)
    {
        return 0;
        cout << "Mahasiswa tidak ditemukan\n";
    }

    AddressUKM u = m->firstUKM;

    while (u != NULL)
    {
        count++;
        u = u->next;
    }
    return count;
}

void MahasiswaUKMTerbanyak(listMhs L) {
    adrMhs m = L.first;
    int maxUKM = 0;


    while (m != nullptr) {
        int count = 0;
        AddressUKM u = m->firstUKM;
        while (u != nullptr) {
            count++;
            u = u->next;
        }
        if (count > maxUKM) {
            maxUKM = count;
        }
        m = m->next;
    }

    if (maxUKM > 0) {
        cout << "Mahasiswa dengan UKM terbanyak adalah:\n ";
        m = L.first;
        while (m != nullptr) {
            int count = 0;
            AddressUKM u = m->firstUKM;
            while (u != nullptr) {
                count++;
                u = u->next;
            }
            if (count == maxUKM) {
                cout << m->info.namaMhs << "(" << m->info.nimMhs << ")" << endl;
            }
            m = m->next;
        }
        cout << "Dengan jumlah UKM: " << maxUKM << endl;
    } else {
        cout << "Tidak ada mahasiswa yang mengikuti UKM.\n";
    }
}

void dataDummy(listMhs &L) {
    adrMhs m1 = createElemenMhs("Andi", 101);
    adrMhs m2 = createElemenMhs("Budi", 102);
    adrMhs m3 = createElemenMhs("Yanto", 103);
    adrMhs m4 = createElemenMhs("Dedi", 104);
    adrMhs m5 = createElemenMhs("Setiawan", 105);
    insertLastParent(L, m1);
    insertLastParent(L, m2);
    insertLastParent(L, m3);
    insertLastParent(L, m4);
    insertLastParent(L, m5);

    insertLastUKM(m1, createElementUKM("Basket"));
    insertLastUKM(m1, createElementUKM("Cianjur"));
    insertLastUKM(m1, createElementUKM("Catur"));
    
    insertLastUKM(m2, createElementUKM("Basket"));
    insertLastUKM(m2, createElementUKM("Pati"));
    insertLastUKM(m2, createElementUKM("Papua"));
    
    insertLastUKM(m3, createElementUKM("Futsal"));
    insertLastUKM(m3, createElementUKM("Tenis Meja"));

    insertLastUKM(m4, createElementUKM("Futsal"));
    insertLastUKM(m4, createElementUKM("Panahan"));

    insertLastUKM(m5, createElementUKM("Futsal"));
    insertLastUKM(m5, createElementUKM("Badminton"));
}