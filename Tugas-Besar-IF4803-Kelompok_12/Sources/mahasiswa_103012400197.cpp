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
adrMhs searchMhs(listMhs L, string nimMhs) {
    adrMhs p = L.first;
    while (p != nullptr && p->info.nimMhs != nimMhs)
    {
        p = p->next;
    }
    return p;
}

// Menghitung total UKM yang diikuti oleh seorang mahasiswa
int totalUKM_1Mhs(listMhs L, string nimMhs) {
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

void dataDummy(listMhs &L) {
    adrMhs m1 = createElemenMhs("Andi", "103012400120");
    adrMhs m2 = createElemenMhs("Budi", "103012400635");
    adrMhs m3 = createElemenMhs("Yanto", "103012400285");
    adrMhs m4 = createElemenMhs("Dedi", "103012400733");
    adrMhs m5 = createElemenMhs("Setiawan", "103012400419");

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