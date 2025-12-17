#include "main.h"
#include "Mahasiswa.h"
#include "UKM.h"

void menuAdmin(listMhs &L){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin ============ " << endl;
        cout << "|| 1. Parent                      ||" << endl;
        cout << "|| 2. Child                       ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "==================================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        if(!validasiInput(option)){
            continue;
        }
        switch(option) {
           case 1  :
                 cout << "Memilih opsi 1" << endl;
                 system("cls");
                 menuParent(L);
                 continue;
           case 2  :
                cout << "Memilih opsi 2" << endl;
                system("cls");
                menuChild(L);
                continue;
            case 0  :
                system("cls");
                break;
            default :
                system("cls");
                cout << "Input tidak valid, coba lagi.\n";
        }
    }
}


void menuParent(listMhs &L){
    int option=-99;
    adrMhs p;
    adrMhs prec;
    InfotypeMhs x;
    string namaMhs;
    int nimMhs;
    while (option != 0) {
        cout << "=========== Menu Parent ============" << endl;
        cout << "|| 1. Insert First Parent         ||" << endl;
        cout << "|| 2. Insert Last Parent          ||" << endl;
        cout << "|| 3. Insert After Parent         ||" << endl;
        cout << "|| 4. Delete First Parent         ||" << endl;
        cout << "|| 5. Delete Last Parent          ||" << endl;
        cout << "|| 6. Delete After Parent         ||" << endl;
        cout << "|| 7. Print Parent                ||" << endl;
        cout << "|| 0. back                        ||" << endl;
        cout << "====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
                system("cls");
                cout << "Insert First Parent\n";
                cout << "Masukkan nama mahasiswa: ";
                cin >> x.namaMhs;
                cout << "Masukkan NIM mahasiswa(angka): ";
                cin >> x.nimMhs;
                if (!validasiNim(x.nimMhs)) {
                    break;
                }
                if (searchMhs(L, x.nimMhs) != nullptr){
                    cout << "Mahasiswa dengan NIM " << x.nimMhs << " sudah terdaftar.\n";
                    break;
                }
                p = createElemenMhs(x.namaMhs, x.nimMhs);
                insertFirstParent(L, p);
                break;
            case 2  :
                system("cls");
                cout << "Insert Last Parent\n";
                cout << "Masukkan nama mahasiswa: ";
                cin >> x.namaMhs;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> x.nimMhs;
                if (!validasiNim(x.nimMhs)) {
                    break;
                }
                if (searchMhs(L, x.nimMhs) != nullptr){
                    cout << "Mahasiswa dengan NIM " << x.nimMhs << " sudah terdaftar.\n";
                    break;
                }
                p = createElemenMhs(x.namaMhs, x.nimMhs);
                insertLastParent(L, p);
                break;
            case 3  :
                system("cls");
                cout << "Insert After Parent\n";
                displayMhs(L);
                cout << "Masukkan NIM mahasiswa yang menjadi prec: ";
                cin >> nimMhs;
                if (!validasiNim(nimMhs)) {
                    break;
                }
                prec = searchMhs(L, nimMhs);
                if (prec != nullptr) {
                    cout << "Masukkan nama mahasiswa: ";
                    cin >> x.namaMhs;
                    cout << "Masukkan NIM mahasiswa: ";
                    cin >> x.nimMhs;
                    if (!validasiNim(x.nimMhs)) {
                        break;
                    }
                    if (searchMhs(L, x.nimMhs) != nullptr){
                        cout << "Mahasiswa dengan NIM " << x.nimMhs << " sudah terdaftar.\n";
                        break;
                    }
                    p = createElemenMhs(x.namaMhs, x.nimMhs);
                    insertAfterParent(L, p, prec);
                } else {
                    cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                }
                break;
            case 4  :
                system("cls");
                cout << "Delete First Parent\n";
                deleteFirstParent(L, p);
                break;
            case 5  :
                system("cls");
                cout << "Delete Last Parent\n";
                deleteLastParent(L, p);
                break;
            case 6  :
                system("cls");
                cout << "Delete After Parent\n";
                displayMhs(L);
                cout << "Masukkan NIM mahasiswa yang menjadi prec: ";
                cin >> nimMhs;
                if (!validasiNim(nimMhs)) {
                    break;
                }
                prec = searchMhs(L, nimMhs);
                if (prec != nullptr) {
                    deleteAfterParent(L, p, prec);
                } else {
                    cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                }
                break;
            case 7  :
                system("cls");
                cout << "Print Parent\n";
                displayMhs(L);
                break;
            case 0  :
                system("cls");
                break;
            default :
                system("cls");
                cout << "Input tidak valid, coba lagi.\n";
        }
    }
}

void menuChild(listMhs &L){
    int option=-99;
    AddressUKM p;
    AddressUKM prec;
    InfotypeUKM x;
    adrMhs parent;
    int nimMhs;
    while (option != 0) {
        cout << "=========== Menu Child ============" << endl;
        cout << "|| 1. Insert First Child         ||" << endl;
        cout << "|| 2. Insert Last Child          ||" << endl;
        cout << "|| 3. Insert After Child         ||" << endl;
        cout << "|| 4. Delete First Child         ||" << endl;
        cout << "|| 5. Delete Last Child          ||" << endl;
        cout << "|| 6. Delete After Child         ||" << endl;
        cout << "|| 7. Print Child                ||" << endl;
        cout << "|| 0. back                       ||" << endl;
        cout << "===================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
              case 1  :
                    system("cls");
                    cout << "Insert First Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        cout << "Masukkan nama UKM: ";
                        cin >> x;
                        if (searchUKM(parent, x) != nullptr){
                            cout << "UKM dengan nama " << x << " sudah terdaftar untuk mahasiswa dengan NIM " << nimMhs << ".\n";
                            break;
                        }
                        p = createElementUKM(x);
                        insertFirstUKM(parent, p);
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 2  :
                    system("cls");
                    cout << "Insert Last Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        cout << "Masukkan nama UKM: ";
                        cin >> x;
                        if (searchUKM(parent, x) != nullptr){
                            cout << "UKM dengan nama " << x << " sudah terdaftar untuk mahasiswa dengan NIM " << nimMhs << ".\n";
                            break;
                        }
                        p = createElementUKM(x);
                        insertLastUKM(parent, p);
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 3  :
                    system("cls");
                    cout << "Insert After Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        printInfoUKM_1Mhs(parent);
                        if (isEmptyUKM_1Mhs(parent)) {
                            cout << "Tidak ada UKM yang dapat dijadikan prec.\n";
                            break;
                        }
                        cout << "Masukkan nama UKM yang menjadi prec: ";
                        cin >> x;
                        prec = searchUKM(parent, x);
                        if (prec != nullptr) {
                            cout << "Masukkan nama UKM: ";
                            cin >> x;
                            if (searchUKM(parent, x) != nullptr){
                                cout << "UKM dengan nama " << x << " sudah terdaftar untuk mahasiswa dengan NIM " << nimMhs << ".\n";
                                break;
                            }
                            p = createElementUKM(x);
                            insertAfterUKM(parent, p, prec);
                        } else {
                            cout << "UKM dengan nama " << x << " tidak ditemukan.\n";
                        }
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 4  :
                    system("cls");
                    cout << "Delete First Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        deleteFirstUKM(parent, p);
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 5  :
                    system("cls");
                    cout << "Delete Last Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        deleteLastUKM(parent, p);
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 6  :
                    system("cls");
                    cout << "Delete After Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        printInfoUKM_1Mhs(parent);
                        cout << "Masukkan nama UKM yang menjadi prec: ";
                        cin >> x;
                        prec = searchUKM(parent, x);
                        if (prec != nullptr) {
                            deleteAfterUKM(parent, p, prec);
                        } else {
                            cout << "UKM dengan nama " << x << " tidak ditemukan.\n";
                        }
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 7  :
                    system("cls");
                    cout << "Print Child\n";
                    displayMhs(L);
                    cout << "masukkan NIM mahasiswa parent: ";
                    cin >> nimMhs;
                    if (!validasiNim(nimMhs)) {
                        break;
                    }
                    parent = searchMhs(L, nimMhs);
                    if (parent != nullptr) {
                        printInfoUKM_1Mhs(parent);
                    } else {
                        cout << "Mahasiswa dengan NIM " << nimMhs << " tidak ditemukan.\n";
                    }
                    break;
                case 0  :
                    system("cls");
                    break;
                default :
                    system("cls");
                    cout << "Input tidak valid, coba lagi.\n";
        }
    }
}