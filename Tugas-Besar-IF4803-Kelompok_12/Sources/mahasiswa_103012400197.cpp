#include <iostream>
#include "Mahasiswa.h"

void deleteFirstParent(listMhs &L, adrMhs &p) {
    if (L.first == NULL)
    {
        p = NULL;
    }
    else if (L.first == L.last)
    {
        p = L.first;
        L.first = NULL;
        L.last = NULL;
    }
    else
    {
        p = L.first;
        L.first = p->next;
        L.first->prev = NULL;
        p->next = NULL;
    }
}

void deleteLastParent(listMhs &L, adrMhs &p) {
    if (L.first == NULL)
    {
        p = NULL;
    }
    else if (L.first == L.last)
    {
        deleteFirstParent(L, p);
    }
    else
    {
        p = L.last;
        L.last = p->prev;
        L.last->next = NULL;
        p->prev = NULL;
    }
}

void deleteAfterParent(listMhs &L, adrMhs &p, adrMhs prec) {
    if (prec != NULL && prec->next != NULL)
    {
        p = prec->next;
        prec->next = p->next;

        if (p->next != NULL)
        {
            p->next->prev = prec;
        }
        else
        {
            L.last = prec;
        }

        p->next = NULL;
        p->prev = NULL;
    }
    else
    {
        p = NULL;
    }
}

adrMhs searchMhs(listMhs L, string nimMhs) {
    adrMhs p = L.first;
    while (p != NULL && p->info.nimMhs != nimMhs)
    {
        p = p->next;
    }
    return p;
}

void printUKMFromPointer(AddressUKM first) {
    if (first == NULL)
    {
        cout << "Tidak ada UKM";
        return;
    }

    AddressUKM p = first;
    while (p != NULL)
    {
        cout << p->info;
        if (p->next != NULL)
            cout << ", ";
        p = p->next;
    }
}

int totalUKM(listMhs L, string nimMhs) {
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
