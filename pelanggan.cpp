#include "pelanggan.h"

void createList(ListPelanggan &L){
    First(L) = NULL;
    Last(L) = NULL;
}

adrPelanggan alokasi(pelanggan x){
    adrPelanggan P = new elmListPelanggan;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLast(ListPelanggan &L, adrPelanggan P){
    adrPelanggan q;
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

void deleteFirst(ListPelanggan &L, adrPelanggan &P){
    adrPelanggan q;
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

void deleteLast(ListPelanggan &L, adrPelanggan &P){
    adrPelanggan q;
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

void deleteAfter(adrPelanggan q, adrPelanggan &P){
    P = next(q);
    prev(next(P)) = next(P);
    next(q) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
}

void printInfo(ListPelanggan L){
    adrPelanggan P;
    if(First(L) == NULL) {
        cout << "\nTidak ada Data Pelanggan !!!\n" << endl;
    }
    else {
        P = First(L);
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << ":\tNomor ID\t Nama\t\t Usia\t\t Jenis Kelamin\t\t:" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        while(next(P) != First(L)) {
            cout << "\t" << info(P).ID << "\t\t";
            cout << info(P).nama << "\t\t ";
            cout << info(P).usia << "\t\t ";
            cout << info(P).jenisKelamin << "\t\t\t";
            cout << endl;
            P = next(P);
        }
        cout << "\t" << info(P).ID << "\t\t";
        cout << info(P).nama << "\t\t ";
        cout << info(P).usia << "\t\t ";
        cout << info(P).jenisKelamin << "\t\t\t";
        cout << endl;
        P = next(P);
    }
}

void hapusData(ListPelanggan &L, adrPelanggan &P){
    adrPelanggan q, prec;
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

adrPelanggan findElm(ListPelanggan L, string nama, int ID){
    adrPelanggan P = First(L);
    do {
        if(info(P).nama == nama && info(P).ID == ID) {
            return P;
        }
        else if(info(P).ID == ID) {
           return P;
        }
        P = next(P);
    } while(P != First(L));

    if(info(P).nama != nama || info(P).ID != ID) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    else if(info(P).nama != nama && info(P).ID != ID) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    return P;
}
