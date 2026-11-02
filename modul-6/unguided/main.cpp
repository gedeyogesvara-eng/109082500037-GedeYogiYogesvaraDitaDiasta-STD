#include <iostream>
#include "Buku.h"

using namespace std;

void inputData(List &L) {
    infotype dataBuku;
    address P;

    cout << "masukkan kode buku: ";
    cin >> dataBuku.kodeBuku;
    cout << "masukkan judul buku: ";
    cin >> dataBuku.judul;
    cout << "masukkan tahun terbit: ";
    cin >> dataBuku.thnTerbit;

    if (findElm(L, dataBuku) == Nil) {
        P = alokasi(dataBuku);
        insertLast(L, P);
    } else {
        cout << "kode buku sudah terdaftar" << endl;
    }
    cout << endl;
}

int main() {
    List L;
    CreateList(L);

    //soal nomer 1
    inputData(L);
    inputData(L);
    inputData(L);
    inputData(L);

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    //soal nomer 2
    infotype cari;
    cout << "Masukkan Kode Buku yang dicari: ";
    cin >> cari.kodeBuku;

    address ditemukan = findElm(L, cari);
    if (ditemukan != Nil) {
        cout << "Kode Buku    : " << ditemukan->info.kodeBuku << endl;
        cout << "Judul        : " << ditemukan->info.judul << endl;
        cout << "Tahun Terbit : " << ditemukan->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << cari.kodeBuku << " tidak ditemukan." << endl;
    }
    cout << endl;

    //soal nomer 3
    infotype hapus;
    cout << "Masukkan Kode Buku yang akan dihapus: ";
    cin >> hapus.kodeBuku;

    address target = findElm(L, hapus);
    if (target != Nil) {
        address P_hapus = Nil;

        if (target == L.First) {
            deleteFirst(L, P_hapus);
        } else if (target == L.Last) {
            deleteLast(L, P_hapus);
        } else {
            deleteAfter(target->prev, P_hapus);
        }

        dealokasi(P_hapus);
        cout << "Data dengan kode buku " << hapus.kodeBuku << " berhasil dihapus." << endl << endl;
    } else {
        cout << "Data dengan kode buku " << hapus.kodeBuku << " tidak ditemukan." << endl << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}