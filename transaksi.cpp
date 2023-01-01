#include "transaksi.h"

void createList(ListTransaksi &L){
    First(L) = NULL;
    Last(L) = NULL;
}

adrTransaksi alokasi(adrPelanggan AP, adrTeater AT){
    adrTransaksi P = new elmListTransaksi;
    teater(P) = AT;
    pelanggan(P) = AP;
    next(P) = NULL;
    return P;
}

void insertLast(ListTransaksi &L, adrTransaksi P){
    if(First(L) == NULL) {
        if(info(teater(P)).kapasitas != 0) {

            First(L) = P;
            next(First(L)) = First(L);
            prev(First(L)) = First(L);
        }
    }
    else {
        if(info(teater(P)).kapasitas != 0) {

            adrTransaksi q = prev(First(L));
            prev(P) = q;
            prev(First(L)) = P;
            next(P) = First(L);
            next(q) = P;
        }
    }
    if(info(teater(P)).kapasitas == 0) {
        cout << "\nMohon Maaf, Kuota yang tersedia tidak cukup !!!\n";

    }
    else {
        info(teater(P)).kapasitas--;
        cout << "\nTransaksi anda telah berhasil !!!\n";
    }
}

void deleteFirst(ListTransaksi &L, adrTransaksi &P){
    adrTransaksi q;
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

void deleteLast(ListTransaksi &L, adrTransaksi &P){
    adrTransaksi q;
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

void deleteAfter(adrTransaksi q, adrTransaksi &P){
    P = next(q);
    prev(next(P)) = next(P);
    next(q) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
}

void printInfo(ListTransaksi L){
    adrTransaksi P;
    if(First(L) == NULL) {
        cout << "\nTidak ada Data Transaksi !!!\n" << endl;
    }
    else {
        P = First(L);
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << ":\tID\t\t Nama\t\t Studio\t\t Acara\t\t Jadwal\t\t:" << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;
        while(next(P) != First(L)) {
            cout << "\t" << info(pelanggan(P)).ID << "\t\t ";
            cout << info(pelanggan(P)).nama << "\t\t ";
            cout << info(teater(P)).studio << "\t\t";
            cout << info(teater(P)).acara << "\t\t";
            cout << info(teater(P)).jadwal << "\t\t";
            cout << endl;
            P = next(P);
        }
        cout << "\t" << info(pelanggan(P)).ID << "\t\t ";
        cout << info(pelanggan(P)).nama << "\t\t ";
        cout << info(teater(P)).studio << "\t\t";
        cout << info(teater(P)).acara << "\t\t";
        cout << info(teater(P)).jadwal << "\t\t";
        cout << endl;
        P = next(P);
    }
}

void hapusData(ListTransaksi &L, adrTransaksi &P){
    adrTransaksi q, prec;
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
    info(teater(P)).kapasitas++;
}

adrTransaksi findElm(ListTransaksi L, string studio, string acara, int ID){
    adrTransaksi P = First(L);
    do {
        if(info(teater(P)).studio == studio && info(teater(P)).acara == acara && info(pelanggan(P)).ID == ID) {
            return P;
        }
        P = next(P);
    } while(P != First(L));

    if(info(teater(P)).studio != studio || info(teater(P)).acara != acara) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    else if(info(teater(P)).studio != studio && info(teater(P)).acara != acara) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    else if(info(pelanggan(P)).ID != ID) {
        cout << "\nMohon Maaf, Data yang Anda masukkan salah !!!";
        cout << endl;
    }
    return P;
}

int menuAplikasi(){
    system("cls");
    cout << "==================================================" << endl;
    cout << "|\t      APLIKASI BOOKING TEATER\t\t |" << endl;
    cout << "==================================================" << endl;
    cout << "| 1.  | Tambahkan Pelanggan Baru\t\t |" << endl;
    cout << "| 2.  | Tambahkan Teater Baru\t\t\t |" << endl;
    cout << "| 3.  | Tambahkan Transaksi Baru\t\t |" << endl;
    cout << "| 4.  | Ubah Data Pelanggan\t\t\t |" << endl;
    cout << "| 5.  | Ubah Data Teater\t\t\t |" << endl;
    cout << "| 6.  | Lihat Pelanggan yang telah terdaftar\t |" << endl;
    cout << "| 7.  | Lihat Teater yang ada\t\t\t |" << endl;
    cout << "| 8.  | Lihat Transaksi yang selesai\t\t |" << endl;
    cout << "| 9.  | Hapus Data Pelanggan\t\t\t |" << endl;
    cout << "| 10. | Hapus Data Teater\t\t\t |" << endl;
    cout << "| 11. | Hapus Data Transaksi\t\t\t |" << endl;
    cout << "| 12. | Cari Data Pelanggaan\t\t\t |" << endl;
    cout << "| 13. | Cari Data Teater\t\t\t |" << endl;
    cout << "| 14. | Cari Data Transaksi\t\t\t |" << endl;
    cout << "| 0.  | Exit \t\t\t\t\t |" << endl;
    cout << "==================================================" << endl;
    cout << endl;
    cout << "Silahkan Pilih Menu : ";
    int pilihan = 0;
    cin >> pilihan;
    return pilihan;
}
