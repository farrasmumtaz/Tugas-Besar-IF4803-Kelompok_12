#include "UKM.h"
#include "Mahasiswa.h"

bool isEmptyUKM_1Mhs(adrMhs p){
    return p->firstUKM == nullptr;
}

AddressUKM createElementUKM(InfotypeUKM x) {
    AddressUKM p;
    p = new elmenUKM;
    p -> info = x;
    p -> next = nullptr;
    return p;
}

void insertLastUKM(adrMhs p, AddressUKM q) {
    if (isEmptyUKM_1Mhs(p)) {
        p -> firstUKM = q;
    } else {
        AddressUKM r = p -> firstUKM;
        while (r->next != nullptr) {
            r = r->next;
        }
        r -> next = q;
    }
}

void printInfoUKM_1Mhs(adrMhs p) {
    AddressUKM q = p -> firstUKM;
    if (q == nullptr) {
        cout << "Tidak ada UKM yang diikuti " << p -> info.namaMhs << " untuk ditampilkan.\n";
    } else {
        cout << "Daftar UKM yang diikuti oleh " << p -> info.namaMhs << ": \n";
        while (q != nullptr) {
            cout << "- " << q -> info << "\n";
            q = q -> next;
        }
    }
}

void UKM_Mhsterbanyak(listMhs L) {
    adrMhs m = L.first;
    int maxUKM = 0;
    string namaMhsTerbanyak;

    while (m != nullptr) {
        int count = 0;
        AddressUKM u = m->firstUKM;
        while (u != nullptr) {
            count++;
            u = u->next;
        }
        if (count > maxUKM) {
            maxUKM = count;
            namaMhsTerbanyak = m->info.namaMhs;
        }
        m = m->next;
    }

    if (maxUKM > 0) {
        cout << "Mahasiswa yang mengikuti UKM terbanyak adalah " << namaMhsTerbanyak << " dengan jumlah UKM: " << maxUKM << endl;
    } else {
        cout << "Tidak ada mahasiswa yang mengikuti UKM.\n";
    }
}