#ifndef TEATER_H_INCLUDED
#define TEATER_H_INCLUDED

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

struct teater {
    string studio;
    string acara;
    string jadwal;
    int kapasitas;
};

typedef struct elmListTeater *adrTeater;

struct elmListTeater {
    teater info;
    adrTeater next;
    adrTeater prev;
};

struct ListTeater {
    adrTeater First;
    adrTeater Last;
};

void createList(ListTeater &L);
adrTeater alokasi(teater x);
void insertLast(ListTeater &L, adrTeater P);
void deleteFirst(ListTeater &L, adrTeater &P);
void deleteLast(ListTeater &L, adrTeater &P);
void deleteAfter(adrTeater q, adrTeater &P);
void printInfo(ListTeater L);
void hapusData(ListTeater &L, adrTeater &P);
adrTeater findElm(ListTeater L, string studio, string acara);

#endif // TEATER_H_INCLUDED
