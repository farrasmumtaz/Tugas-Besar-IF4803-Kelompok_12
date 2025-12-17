#include <iostream>
#include "main.h"
#include "Mahasiswa.h"
#include "UKM.h"

using namespace std;

int main()
{  
   listMhs L;
   createListMhs(L);
   dataDummy(L);
   int option=-99;
   while (option != 0) {
        system("cls");
        cout << "====== APP UKM MAHASISWA ======" << endl;
        cout << "|| 1. Test Case              ||" << endl;
        cout << "|| 2. Study Case             ||" << endl;
        cout << "|| 0. exit                   ||" << endl;
        cout << "===============================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuAdmin(L);
              break;
           case 2  :
              cout << "you choose option 2" << endl;
              menuUser(L);
              break;

           default :
              exit(1);
        }
    }


    return 0;
}