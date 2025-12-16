#include "Mahasiswa.h"

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

adrMhs searchMhs(listMhs L, string nimMhs) {
    adrMhs p = L.first;
    while (p != nullptr && p->info.nimMhs != nimMhs)
    {
        p = p->next;
    }
    return p;
}

// Menghitung total UKM yang diikuti oleh seorang mahasiswa
int totalUKM_1MHS(listMhs L, string nimMhs) {
    int count = 0;
    adrMhs m = searchMhs(L, nimMhs);

    if (m == NULL)
    {
        return 0;
    }

    AddressUKM u = m->firstUKM;

    while (u != NULL)
    {
        count++;
        u = u->next;
    }
    return count;
}
