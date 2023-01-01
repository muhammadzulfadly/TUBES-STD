#include "teater.h"
#include "pelanggan.h"
#include "transaksi.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

int main()
{

    ListTeater LT;
    createList(LT);
    adrTeater AT;
    teater infoT;

    ListPelanggan LP;
    createList(LP);
    adrPelanggan AP;
    pelanggan infoP;

    ListTransaksi LS;
    createList(LS);
    adrTransaksi AS;

    int pilihan, x, i;
    string out;

    pilihan = menuAplikasi();

    while(pilihan != 0) {
        switch(pilihan) {
        case 1:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tMasukkan Data Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << endl;
            cout << "Jumlah Pelanggan yang ingin di daftar : ";
            cin >> x;
            i = 1;
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tMasukkan Data Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            while(i <= x) {
                cout << endl;
                cout << "Pelanggan ke-" << i << endl;
                cout << "Nomor ID \t: ";
                cin >> infoP.ID;
                cout << "Nama Pelanggan \t: ";
                cin >> infoP.nama;
                cout << "Usia \t\t: ";
                cin >> infoP.usia;
                cout << "Jenis Kelamin \t: ";
                cin >> infoP.jenisKelamin;
                cout << endl;
                AP = alokasi(infoP);
                insertLast(LP, AP);
                i++;
            }
            insertLast(LP, AP);
            break;
        case 2:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tMasukkan Data Teater\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << endl;
            cout << "Studio \t\t: ";
            cin >> infoT.studio;
            cout << "Acara \t\t: ";
            cin >> infoT.acara;
            cout << "Jadwal \t\t: ";
            cin >> infoT.jadwal;
            cout << "Kapasitas \t: ";
            cin >> infoT.kapasitas;
            AT = alokasi(infoT);
            insertLast(LT, AT);
            break;
        case 3:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tMasukkan Transaksi\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << endl;
            if(First(LP) == NULL) {
                cout << "Mohon masukkan data Pelanggan terlebih dahulu !!!\n" << endl;
            }
            else {
                cout << "Masukkan nomor ID Pelanggan : ";
                cin >> infoP.ID;
                AP = findElm(LP, infoP.nama, infoP.ID);
                if(infoP.ID == info(AP).ID && First(LP) != NULL) {
                    system("cls");
                    if(First(LT) != NULL) {
                        cout << "Halo, " << info(AP).nama << endl;
                        cout << "Selamat Datang Kembali ~" << endl;
                        printInfo(LT);
                        cout << endl;

                        cout << "Silahkan pilih Teater yang Anda inginkan" << endl;
                        cout << "Studio\t\t: ";
                        cin >> infoT.studio;
                        cout << "Acara\t\t: ";
                        cin >> infoT.acara;
                        AT = findElm(LT, infoT.studio, infoT.acara);
                        if(infoT.studio == info(AT).studio && infoT.acara == info(AT).acara) {
                            AS = alokasi(AP, AT);
                            insertLast(LS, AS);
                        }
                    }
                    else {
                        cout << "--------------------------------------------------" << endl;
                        cout << ":\t\tMasukkan Transaksi\t\t :" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << endl;
                        cout << "Mohon Maaf, Tidak ada Teater saat ini !!!" << endl;
                    }
                }
            }
            break;
        case 4:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tUbah Data Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LP);
            if(First(LP) != NULL) {
                cout << "\nMasukkan nomor ID dan Nama Pelanggan yang ingin diubah" << endl;
                cout << "Nomor ID\t: ";
                cin >> infoP.ID;
                cout << "Nama Pelanggan\t: ";
                cin >> infoP.nama;
                AP = findElm(LP, infoP.nama, infoP.ID);
                if(infoP.nama == info(AP).nama && infoP.ID == info(AP).ID) {
                    system("cls");
                    cout << "--------------------------------------------------" << endl;
                    cout << ":\t\tUbah Data Pelanggan\t\t :" << endl;
                    cout << "--------------------------------------------------" << endl;
                    cout << endl;
                    cout << "Data Sebelumnya" << endl;
                    cout << "Nomor ID\t: " << info(AP).ID << endl;
                    cout << "Nama Pelanggan\t: " << info(AP).nama << endl;
                    cout << "Usia\t\t: " << info(AP).usia << endl;
                    cout << "Jenis Kelamin\t: " << info(AP).jenisKelamin << endl;
                    cout << endl;

                    cout << endl;
                    cout << "Ubah menjadi" << endl;
                    cout << "Nomor ID\t: ";
                    cin >> info(AP).ID;
                    cout << "Nama Pelanggan\t: ";
                    cin >> info(AP).nama;
                    cout << "Usia\t\t: ";
                    cin >> info(AP).usia;
                    cout << "Jenis Kelamin\t: ";
                    cin >> info(AP).jenisKelamin;
                    cout << endl;
                    cout << "Data telah diUpdate !!!" << endl;
                }
            }
            break;
        case 5:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tUbah Data Teater\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LT);
            if(First(LT) != NULL) {
                cout << "\nMasukkan Studio dan Acara yang ingin diubah" << endl;
                cout << "Studio\t\t: ";
                cin >> infoT.studio;
                cout << "Acara\t\t: ";
                cin >> infoT.acara;
                AT = findElm(LT, infoT.studio, infoT.acara);
                if(infoT.studio == info(AT).studio && infoT.acara == info(AT).acara) {
                    system("cls");
                    cout << "--------------------------------------------------" << endl;
                    cout << ":\t\tUbah Data Teater\t\t :" << endl;
                    cout << "--------------------------------------------------" << endl;
                    cout << endl;
                    cout << "Data Sebelumnya" << endl;
                    cout << "Studio\t\t: " << info(AT).studio << endl;
                    cout << "Acara\t\t: " << info(AT).acara << endl;
                    cout << "Jadwal\t\t: " << info(AT).jadwal << endl;
                    cout << "Kapasitas\t: " << info(AT).kapasitas << endl;
                    cout << endl;

                    cout << endl;
                    cout << "Ubah menjadi" << endl;
                    cout << "Studio\t\t: ";
                    cin >> info(AT).studio;
                    cout << "Acara\t\t: ";
                    cin >> info(AT).acara;
                    cout << "Jadwal\t\t: ";
                    cin >> info(AT).jadwal;
                    cout << "Kapasitas\t: ";
                    cin >> info(AT).kapasitas;
                    cout << endl;
                    cout << "Data telah diUpdate !!!" << endl;
                }
            }
            break;
        case 6:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t  Data Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LP);
            break;
        case 7:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t  Data Teater\t\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LT);
            break;
        case 8:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t  Data Transaksi\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LS);
            break;
        case 9:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tHapus Data Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LP);
            if(First(LP) != NULL) {
                cout << "\nMasukkan nomor ID dan Nama Pelanggan yang ingin diHapus" << endl;
                cout << "Nomor ID\t: ";
                cin >> infoP.ID;
                cout << "Nama Pelanggan\t: ";
                cin >> infoP.nama;
                AP = findElm(LP, infoP.nama, infoP.ID);
                if(infoP.nama == info(AP).nama && infoP.ID == info(AP).ID) {
                    cout << endl;
                    cout << "Anda yakin ingin menghapus data ini? (Y/N) : ";
                    cin >> out;
                    if(out == "Y") {
                        hapusData(LP, AP);
                        cout << endl;
                        cout << "Data telah diUpdate !!!" << endl;
                    }
                    else if(out == "N") {
                        cout << endl;
                        cout << "Hapus data diBatalkan !!!" << endl;
                    }
                }
            }
            break;
        case 10:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tHapus Data Teater\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LT);
            if(First(LT) != NULL) {
                cout << "\nMasukkan nama Studio dan Acara yang ingin diHapus" << endl;
                cout << "Studio\t\t: ";
                cin >> infoT.studio;
                cout << "Acara\t\t: ";
                cin >> infoT.acara;
                AT = findElm(LT, infoT.studio, infoT.acara);
                if(infoT.studio == info(AT).studio && infoT.acara == info(AT).acara) {
                    cout << endl;
                    cout << "Anda yakin ingin menghapus data ini? (Y/N) : ";
                    cin >> out;
                    if(out == "Y") {
                        hapusData(LT, AT);
                        cout << endl;
                        cout << "Data telah diUpdate !!!" << endl;
                    }
                    else if(out == "N") {
                        cout << endl;
                        cout << "Hapus data diBatalkan !!!" << endl;
                    }
                }
            }
            break;
        case 11:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\tHapus Data Transaksi\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            printInfo(LS);
            if(First(LS) != NULL) {
                cout << "\nMasukkan nomor ID Pelanggan yang ingin diHapus" << endl;
                cout << "Nomor ID\t\t: ";
                cin >> infoP.ID;
                AS = findElm(LS, infoT.studio, infoT.acara, infoP.ID);
                if(infoP.ID == info(pelanggan(AS)).ID) {
                    cout << endl;
                    cout << "Anda yakin ingin menghapus data ini? (Y/N) : ";
                    cin >> out;
                    if(out == "Y") {
                        hapusData(LS, AS);
                        cout << endl;
                        cout << "Data telah diUpdate !!!" << endl;
                    }
                    else if(out == "N") {
                        cout << endl;
                        cout << "Hapus data diBatalkan !!!" << endl;
                    }
                }
            }
            break;
        case 12:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t  Cari Pelanggan\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            if(First(LP) != NULL) {
                cout << "\nMasukkan nomor ID Pelanggan : ";
                cin >> infoP.ID;
                AP = findElm(LP, infoP.nama, infoP.ID);
                if(infoP.ID == info(AP).ID) {
                    cout << endl;
                    cout << "Nomor ID\t: " << info(AP).ID << endl;
                    cout << "Nama Pelanggan\t: " << info(AP).nama << endl;
                    cout << "Usia\t\t: " << info(AP).usia << endl;
                    cout << "Jenis Kelamin\t: " << info(AP).jenisKelamin << endl;
                    cout << endl;
                }
            }
            else {
                cout << "\nTidak ada data Pelanggan !!!\n" << endl;
            }
            break;
        case 13:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t     Cari Teater\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            if(First(LT) != NULL) {
                cout << "\nMasukkan Nama Acara : ";
                cin >> infoT.acara;
                AT = findElm(LT, infoT.studio, infoT.acara);
                if(infoT.acara == info(AT).acara) {
                    while(infoT.acara == info(AT).acara) {
                        cout << endl;
                        cout << "Studio\t\t: " << info(AT).studio << endl;
                        cout << "Acara\t\t: " << info(AT).acara << endl;
                        cout << "Jadwal\t\t: " << info(AT).jadwal << endl;
                        cout << "Kapasitas\t: " << info(AT).kapasitas << endl;
                        cout << endl;
                        AT = next(AT);
                    }
                }
            }
            else {
                cout << "\nTidak ada data Teater !!!\n" << endl;
            }
            break;
        case 14:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << ":\t\t  Cari Transaksi\t\t :" << endl;
            cout << "--------------------------------------------------" << endl;
            if(First(LS) != NULL) {
                cout << "\nMasukkan nomor ID Pelanggan : ";
                cin >> infoP.ID;
                AS = findElm(LS, infoT.studio, infoT.acara, infoP.ID);
                if(infoP.ID == info(pelanggan(AS)).ID) {
                    cout << endl;
                    cout << "Nomor ID\t: " << info(pelanggan(AS)).ID << endl;
                    cout << "Nama Pelanggan\t: " << info(pelanggan(AS)).nama << endl;
                    cout << "Studio\t\t: " << info(teater(AS)).studio << endl;
                    cout << "Acara\t\t: " << info(teater(AS)).acara << endl;
                    cout << "Jadwal\t\t: " << info(teater(AS)).jadwal << endl;
                    cout << endl;
                    AS = next(AS);
                }
            }
            else {
                cout << "\nTidak ada Transaksi !!!\n" << endl;
            }
            break;
        }

        cout << endl;
        cout << "Kembali ke Menu Utama? (Y/N) : ";
        cin >> out;
        if(out == "Y") {
            pilihan = menuAplikasi();
        }
        else if(out != "N") {
            break;
        }
    }

    system("cls");
    cout << endl;
    cout << "==================================================" << endl;
    cout << "|\t  ANDA TELAH KELUAR DARI APLIKASI\t |" << endl;
    cout << "==================================================" << endl;

}
