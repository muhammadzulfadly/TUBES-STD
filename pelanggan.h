#ifndef PELANGGAN_H_INCLUDED
#define PELANGGAN_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) (L).First
#define Last(L) (L).Last
#define nil NULL

struct pelanggan {
    string nama;
    int usia;
    string jenisKelamin;
    int ID;
};

typedef struct elmListPelanggan *adrPelanggan;

struct elmListPelanggan {
    pelanggan info;
    adrPelanggan next;
    adrPelanggan prev;
};

struct ListPelanggan {
    adrPelanggan First;
    adrPelanggan Last;
};

void createList(ListPelanggan &L);
adrPelanggan alokasi(pelanggan x);
void insertLast(ListPelanggan &L, adrPelanggan P);
void deleteFirst(ListPelanggan &L, adrPelanggan &P);
void deleteLast(ListPelanggan &L, adrPelanggan &P);
void deleteAfter(adrPelanggan q, adrPelanggan &P);
void printInfo(ListPelanggan L);
void hapusData(ListPelanggan &L, adrPelanggan &P);
adrPelanggan findElm(ListPelanggan L, string nama, int ID);

#endif // PELANGGAN_H_INCLUDED
