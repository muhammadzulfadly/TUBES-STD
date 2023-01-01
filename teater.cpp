#include "teater.h"

void createList(ListTeater &L){
    First(L) = NULL;
    Last(L) = NULL;
}

adrTeater alokasi(teater x){
    adrTeater P = new elmListTeater;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLast(ListTeater &L, adrTeater P){
    adrTeater q;
    if(First(L) == NULL) {
        First(L) = P;
        next(P) = First(L);
    }
    else {
        q = First(L);
        while(next(q) != First(L)) {
            q = next(q);
        }
        next(q) = P;
        next(P) = First(L);
        prev(P) = q;
        prev(First(L)) = P;
    }
}

void deleteFirst(ListTeater &L, adrTeater &P){
    adrTeater q;
    if(First(L) != NULL) {
        q = First(L);
        while(next(q) != First(L)) {
            q = next(q);
        }
        P = First(L);
        First(L) = next(First(L));
        next(P) = NULL;
        prev(First(L)) = q;
        next(q) = First(L);
    }
}

void deleteLast(ListTeater &L, adrTeater &P){
    adrTeater q;
    if(First(L) != NULL) {
        P = First(L);
        do {
            q = P;
            P = next(P);
        } while(next(P) != First(L));
        next(q) = First(L);
        prev(First(L)) = q;
    }
}

void deleteAfter(adrTeater q, adrTeater &P){
    P = next(q);
    prev(next(P)) = next(P);
    next(q) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
}

void printInfo(ListTeater L){
    adrTeater P;
    if(First(L) == NULL) {
        cout << "\nTidak ada Data Teater !!!\n" << endl;
    }
    else {
        P = First(L);
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << ":\tStudio\t\t Acara\t\t Jadwal\t\t Kapasitas\t\t:" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        while(next(P) != First(L)) {
            cout << "\t" << info(P).studio << "\t\t ";
            cout << info(P).acara << "\t\t ";
            cout << info(P).jadwal << "\t\t";
            cout << info(P).kapasitas << "\t\t";
            cout << endl;
            P = next(P);
        }
        cout << "\t" << info(P).studio << "\t\t ";
        cout << info(P).acara << "\t\t ";
        cout << info(P).jadwal << "\t\t";
        cout << info(P).kapasitas << "\t\t";
        cout << endl;
        P = next(P);
    }
}

void hapusData(ListTeater &L, adrTeater &P){
    adrTeater q, prec;
    q = First(L);
    do {
        q = next(q);
    } while(next(q) != First(L));
    if(P != NULL) {
        if(P == First(L)) {
            if(next(P) == First(L)) {
                First(L) = NULL;
            }
            else {
                deleteFirst(L, P);
            }
        }
        else if(P == q) {
            deleteLast(L, P);
        }
        else {
            prec = prev(P);
            deleteAfter(prec, P);
        }
    }
}

adrTeater findElm(ListTeater L, string studio, string acara){
    adrTeater P = First(L);
    do {
        if(info(P).studio == studio && info(P).acara == acara) {
            return P;
        }
        else if(info(P).acara == acara) {
           return P;
        }
        P = next(P);
    } while(P != First(L));

    if(info(P).studio != studio || info(P).acara != acara) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    else if(info(P).studio != studio && info(P).acara != acara) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    return P;
}
