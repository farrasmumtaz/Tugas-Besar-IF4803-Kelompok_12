#include "UKM.h"
#include "Mahasiswa.h"

void insertFirstUKM(adrMhs p, AddressUKM q)
{
    if (isEmptyUKM_1Mhs(p))
    {
        p->firstUKM = q;
    }
    else
    {
        q->next = p->firstUKM;
        p->firstUKM = q;
    }
}

void insertAfterUKM(adrMhs L, AddressUKM p, AddressUKM prec)
{
    if (prec != NULL)
    {
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteFirstUKM(adrMhs p, AddressUKM &q)
{
    if (isEmptyUKM_1Mhs(p))
    {
        cout << "Tidak ada UKM yang diikuti " << p->info.namaMhs << "untuk dihapus.\n";
        q = nullptr;
    }
    else
    {
        q = p->firstUKM;
        p->firstUKM = q->next;
        q->next = nullptr;
    }
}

void deleteLastUKM(adrMhs p, AddressUKM &q)
{
    if (isEmptyUKM_1Mhs(p))
    {
        cout << "Tidak ada UKM yang diikuti " << p->info.namaMhs << "untuk dihapus.\n";
        q = nullptr;
    }
    else if (p->firstUKM->next == nullptr)
    {
        deleteFirstUKM(p, q);
    }
    else
    {
        AddressUKM r = p->firstUKM;
        while (r->next->next != nullptr)
        {
            r = r->next;
        }
        q = r->next;
        r->next = nullptr;
    }
}

void deleteAfterUKM(adrMhs p, AddressUKM &q, AddressUKM prec)
{
    if (prec != nullptr && prec->next != nullptr)
    {
        q = prec->next;
        prec->next = q->next;
        q->next = nullptr;
    }
    else
    {
        q = nullptr;
    }
}

AddressUKM searchUKM(adrMhs p, InfotypeUKM x)
{
    AddressUKM q = p->firstUKM;
    while (q != nullptr && q->info != x)
    {
        q = q->next;
    }
    return q;
}