#ifndef TRANSAKSI_H_INCLUDED
#define TRANSAKSI_H_INCLUDED

#include "transaksi.h"
#include "teater.h"
#include "pelanggan.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) (L).First
#define Last(L) (L).Last
#define teater(P) (P)->teater
#define pelanggan(P) (P)->pelanggan

typedef struct elmListTransaksi *adrTransaksi;

struct elmListTransaksi {
    adrTransaksi next;
    adrTransaksi prev;
    adrTeater teater;
    adrPelanggan pelanggan;
};

struct ListTransaksi {
    adrTransaksi First;
    adrTransaksi Last;
};

void createList(ListTransaksi &L);
adrTransaksi alokasi(adrPelanggan AP, adrTeater AT);
void insertLast(ListTransaksi &L, adrTransaksi P);
void deleteFirst(ListTransaksi &L, adrTransaksi &P);
void deleteLast(ListTransaksi &L, adrTransaksi &P);
void deleteAfter(adrTransaksi q, adrTransaksi &P);
void printInfo(ListTransaksi L);
void hapusData(ListTransaksi &L, adrTransaksi &P);
adrTransaksi findElm(ListTransaksi L, string studio, string acara, int ID);
int menuAplikasi();

#endif // TRANSAKSI_H_INCLUDED
