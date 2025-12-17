#include "main.h"
#include "Mahasiswa.h"
#include "UKM.h"
#include <iostream>

using namespace std;

void menuUser(listMhs &L)
{
    adrMhs p;
    int option = -99;
    while (option != 0)
    {
        cout << "========================== Menu Studi Kasus ========================= " << endl;
        cout << "|| 1. Tambah Mahasiswa                                             ||" << endl;
        cout << "|| 2. Hapus Mahasiswa                                              ||" << endl;
        cout << "|| 3. Tambah UKM                                                   ||" << endl;
        cout << "|| 4. Hapus UKM                                                    ||" << endl;
        cout << "|| 5. Cari Mahasiswa Dengan UKM Terbanyak                          ||" << endl;
        cout << "|| 6. Tampilkan UKM yang Diikuti Mahasiswa dengan UKM Terbanyak    ||" << endl;
        cout << "|| 7. Hitung Total Mahasiswa                                       ||" << endl;
        cout << "|| 8. Hitung UKM yang diikuti 1 Mahasiswa                          ||" << endl;
        cout << "|| 9. Tampilkan Seluruh UKM yang Diikuti mahasiswa                 ||" << endl;
        cout << "|| 0. back                                                         ||" << endl;
        cout << "===================================================================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        if (!validasiInput(option))
        {
            continue;
        }
        system("cls");
        switch (option)
        {
        case 1:
            menuTambahMahasiswa(L);
            break;
        case 2:
            menuHapusMahasiswa(L);
            break;
        case 3:
            menuTambahUKM(L);
            break;
        case 4:
            menuHapusUKM(L);
            break;
        case 5:
            menuCariMhsUKMTerbanyak(L); // done
            break;
        case 6:
            displayUKMmahasiswaDenganUKMTerbanyak(L);
            break;
        case 7:
            cout << "Total Mahasiswa: " << totalMahasiswa(L) << endl;
            break;
        case 8:
        {
            int nim;
            displayMhs(L);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            cout << "Total UKM: " << totalUKM_1Mhs(L, nim) << endl;
            break;
        }
        case 9:
        {
            tampilSemuaUKMdenganMahasiswa(L);
            break;
        }
        default:
            system("cls");
            cout << "Input tidak valid, coba lagi.\n";
        }
    }
    while (option != 0)
        ;
}
// 1. tambah mahasiswa

void menuTambahMahasiswa(listMhs &L)
{
    int pilih;
    string nama;
    int nim;
    cout << "Nama Mahasiswa : ";
    cin >> nama;
    cout << "NIM Mahasiswa  : ";
    cin >> nim;
    if (!validasiNim(nim))
    {
        return;
    }
    if (searchMhs(L, nim) != NULL)
    {
        cout << "Mahasiswa sudah terdaftar!\n";
        return;
    }

    adrMhs p = createElemenMhs(nama, nim);

    cout << "\nMetode Insert:\n";
    cout << "1. Insert First\n";
    cout << "2. Insert Last\n";
    cout << "3. Insert After\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        insertFirstParent(L, p);
        break;
    case 2:
        insertLastParent(L, p);
        break;
    case 3:
    {
        int nim;
        cout << "Insert setelah NIM: ";
        cin >> nim;
        adrMhs prec = searchMhs(L, nim);
        if (prec != NULL)
        {
            insertAfterParent(L, p, prec);
        }
        else
        {
            cout << "NIM tidak ditemukan\n";
            break;
        }
    }
    default:
        cout << "Input tidak valid\n";
        break;
    }
}

// 2. hapus mahasiswa
void menuHapusMahasiswa(listMhs &L)
{
    int pilih;
    adrMhs p, prec;
    int nim;
    displayMhs(L);
    cout << "1. Delete First\n";
    cout << "2. Delete Last\n";
    cout << "3. Delete After\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        deleteFirstParent(L, p);
        if (p == nullptr)
        {
            cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
            break;
        }
        cout << "Mahasiswa dengan NIM " << p->info.nimMhs << " telah dihapus.\n";
        break;
    case 2:
        deleteLastParent(L, p);
        if (p == nullptr)
        {
            cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
            break;
        }
        cout << "Mahasiswa dengan NIM " << p->info.nimMhs << " telah dihapus.\n";
        break;
    case 3:
        displayMhs(L);
        cout << "Masukkan NIM prec: ";
        cin >> nim;
        prec = searchMhs(L, nim);
        if (prec != NULL)
        {
            deleteAfterParent(L, p, prec);
            if (p == nullptr)
            {
                cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
                break;
            }
            cout << "Mahasiswa dengan NIM " << p->info.nimMhs << " telah dihapus.\n";
        }
        else
        {
            cout << "Mahasiswa tidak ditemukan\n";
            break;
        }
    default:
        cout << "Input tidak valid\n";
        break;
    }
}

// 3. tambah UKM
void menuTambahUKM(listMhs &L)
{
    string ukm;
    int nim;
    int pilih;
    displayMhs(L);
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> nim;

    adrMhs m = searchMhs(L, nim);
    if (m == NULL)
    {
        cout << "Mahasiswa tidak ditemukan\n";
        return;
    }

    cout << "Nama UKM: ";
    cin >> ukm;

    AddressUKM p = createElementUKM(ukm);

    cout << "\nMetode Insert UKM:\n";
    cout << "1. Insert First\n";
    cout << "2. Insert Last\n";
    cout << "3. Insert After\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        insertFirstUKM(m, p);
        break;
    case 2:
        insertLastUKM(m, p);
        break;
    case 3:
    {
        printInfoUKM_1Mhs(m);
        cout << "UKM prec: ";
        cin >> ukm;
        AddressUKM prec = searchUKM(m, ukm);
        if (prec != NULL)
        {
            insertAfterUKM(m, p, prec);
        }
        else
        {
            cout << "UKM tidak ditemukan\n";
            break;
        }
    }
    default:
        cout << "Input tidak valid\n";
        break;
    }
}

// 4. hapus UKM
void menuHapusUKM(listMhs &L)
{
    string ukm;
    int nim;
    int pilih;
    AddressUKM q;

    displayMhs(L);
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> nim;

    adrMhs m = searchMhs(L, nim);
    if (m == NULL)
    {
        cout << "Mahasiswa tidak ditemukan\n";
        return;
    }

    cout << "1. Delete First\n";
    cout << "2. Delete Last\n";
    cout << "3. Delete After\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        deleteFirstUKM(m, q);
        if (q == nullptr)
        {
            cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
            break;
        }
        cout << "UKM " << q->info << " telah dihapus.\n";
        break;
    case 2:
        deleteLastUKM(m, q);
        if (q == nullptr)
        {
            cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
            break;
        }
        cout << "UKM " << q->info << " telah dihapus.\n";
        break;
    case 3:
    {
        printInfoUKM_1Mhs(m);
        cout << "UKM prec: ";
        cin >> ukm;
        AddressUKM prec = searchUKM(m, ukm);
        if (prec != NULL)
        {
            deleteAfterUKM(m, q, prec);
            if (q == nullptr)
            {
                cout << "Tidak ada mahasiswa yang dihapus (list kosong).\n";
                break;
            }
            cout << "UKM " << q->info << " telah dihapus.\n";
        }
        else
        {
            cout << "UKM tidak ditemukan\n";
            break;
        }
    }
    default:
        cout << "Input tidak valid\n";
        break;
    }
}

// 5. cari mahasiswa dengan UKM terbanyak
void menuCariMhsUKMTerbanyak(listMhs &L)
{
    MahasiswaUKMTerbanyak(L);
}

void tampilSemuaUKMdenganMahasiswa(listMhs L)
{
    adrMhs p = L.first;

    if (p == NULL)
    {
        cout << "Tidak ada mahasiswa yang terdaftar.\n";
        return;
    }

    cout << "===== DAFTAR UKM SETIAP MAHASISWA =====\n";

    while (p != NULL)
    {
        cout << p->info.namaMhs << ": ";
        printInfoUKM_1Mhs(p);
        cout << endl;
        p = p->next;
    }
}