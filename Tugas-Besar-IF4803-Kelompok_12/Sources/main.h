#ifndef MAIN_H
#define MAIN_H
#include "Mahasiswa.h"
#include <iostream>
using namespace std;

void menuAdmin(listMhs &L);
void menuParent(listMhs &L);
void menuChild(listMhs &L);
void menuUser(listMhs &L);
bool validasiInput(int x);
#endif