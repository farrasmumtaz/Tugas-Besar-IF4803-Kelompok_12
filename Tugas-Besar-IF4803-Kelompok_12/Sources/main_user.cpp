#include "main.h"
#include "Mahasiswa.h"
#include "UKM.h"
#include <iostream>

using namespace std;

void menuUser(listMhs &L)
{
    int option = -99;
    while (option != 0)
    {
        system("cls");
        cout << "====================== Menu Studi Kasus ===================== " << endl;
        cout << "|| 1. Tambah Mahasiswa                                     ||" << endl;
        cout << "|| 2. Hapus Mahasiswa                                      ||" << endl;
        cout << "|| 2. Tambah UKM                                           ||" << endl;
        cout << "|| 2. Hapus UKM                                            ||" << endl;
        cout << "|| 3. Tambah UKM ke Mahasiswa                              ||" << endl;
        cout << "|| 4. Hapus UKM dari Mahasiswa                             ||" << endl;
        cout << "|| 5. Cari Mahasiswa                                       ||" << endl;
        cout << "|| 6. Tampilkan UKM yang Diikuti Satu Mahasiswa            ||" << endl;
        cout << "|| 7. Hitung Total Mahasiswa                               ||" << endl;
        cout << "|| 8. Hitung UKM yang diikuti 1 Mahasiswa                  ||" << endl;
        cout << "|| 0. back                                                 ||" << endl;
        cout << "============================================================= " << endl;
        cout << "Choose your option : ";
        cin >> option;
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
            menuCari(L);
            break;
        case 6:
            tampilUKMUnik(L);
            break;
        case 7:
            cout << "Total Mahasiswa: " << totalMahasiswa(L) << endl;
            break;
        case 8:
        {
            string nim;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> nim;
            cout << "Total UKM: " << totalUKM_1Mhs(L, nim) << endl;
            break;
        }
        }
    }
    while (option != 0)
        ;
}

void menuTambahMahasiswa(listMhs &L)
{
    int pilih;
    string nama, nim;
    cout << "Nama Mahasiswa : ";
    cin >> nama;
    cout << "NIM Mahasiswa  : ";
    cin >> nim;

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
        string nim;
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
    }
}

/* ================= HAPUS MAHASISWA ================= */

void menuHapusMahasiswa(listMhs &L)
{
    int pilih;
    adrMhs p, prec;
    string nim;

    cout << "1. Delete First\n";
    cout << "2. Delete Last\n";
    cout << "3. Delete After\n";
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        deleteFirstParent(L, p);
        cout << "Mahasiswa dengan NIM " << p->info.nimMhs << " telah dihapus.\n";
        break;
    case 2:
        deleteLastParent(L, p);
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
            cout << "Mahasiswa dengan NIM " << p->info.nimMhs << " telah dihapus.\n";
        }
        else
        {
            cout << "Mahasiswa tidak ditemukan\n";
            break;
        }
    }
}

/* ================= TAMBAH UKM ================= */

void menuTambahUKM(listMhs &L)
{
    string nim, ukm;
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
    }
}

/* ================= HAPUS UKM ================= */

void menuHapusUKM(listMhs &L)
{
    string nim, ukm;
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
        cout << "UKM " << q->info << " telah dihapus.\n";
        break;
    case 2:
        deleteLastUKM(m, q);
        cout << "UKM " << q->info << " telah dihapus.\n";
        break;
    case 3:
        printInfoUKM_1Mhs(m);
        cout << "UKM prec: ";
        cin >> ukm;
        AddressUKM prec = searchUKM(m, ukm);
        if (prec != NULL)
        {
            deleteAfterUKM(m, q, prec);
            cout << "UKM " << q->info << " telah dihapus.\n";
        }
        else
        {
            cout << "UKM tidak ditemukan\n";
            break;
        }
    }
}

/* ================= CARI MAHASISWA ================= */

void menuCari(listMhs &L)
{
    string nim;
    cout << "Masukkan NIM: ";
    cin >> nim;

    adrMhs m = searchMhs(L, nim);
    if (m != NULL)
    {
        cout << "Nama: " << m->info.namaMhs << endl;
        printInfoUKM_1Mhs(m);
    }
    else
    {
        cout << "Mahasiswa tidak ditemukan\n";
    }
}

/* ================= UKM UNIK ================= */

void tampilUKMUnik(listMhs L)
{
    string ukmUnik[100]; // asumsi maksimal 100 UKM unik
    int jumlah = 0;

    adrMhs m = L.first;

    system("cls");
    cout << "===== DAFTAR UKM UNIK =====\n";

    while (m != NULL)
    {
        AddressUKM u = m->firstUKM;
        while (u != NULL)
        {
            bool sudahAda = false;

            // cek apakah UKM sudah pernah dicatat
            for (int i = 0; i < jumlah; i++)
            {
                if (ukmUnik[i] == u->info)
                {
                    sudahAda = true;
                    break;
                }
            }

            if (!sudahAda)
            {
                cout << "- " << u->info << endl;
                ukmUnik[jumlah] = u->info;
                jumlah++;
            }

            u = u->next;
        }
        m = m->next;
    }
}
