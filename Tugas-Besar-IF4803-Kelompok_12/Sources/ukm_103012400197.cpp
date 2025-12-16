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

