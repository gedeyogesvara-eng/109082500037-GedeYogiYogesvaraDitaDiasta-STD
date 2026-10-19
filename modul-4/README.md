# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Gede Yogi Yogesvara Dita Diasta - 109082500037</p>

## Dasar Teori
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk  merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string.[1].

### A. Singly Linked List<br/>
Singly Linked List merupakan model dari Abstract Data Type (ADT) Linked List yang hanya memiliki satu arah pointer (penunjuk). Karakteristik utama dari Singly Linked List adalah[1]:
1. Memerlukan satu buah pointer utama yang disebut first atau head untuk menunjuk alamat elemen pertama.
2. Setiap elemen menyimpan Data dan next penunjuk ke alamat elemen di depannya.
3. Node paling akhir selalu menunjuk ke NULL atau Nil sebagai tanda bahwa list telah berakhir.

### B. Operasi Dasar<br/>
Dalam praktiknya, Singly Linked List memiliki operasi primitif dasar untuk memanipulasi data di memori[2]:
1. Insert (Penyisipan): Operasi menambah elemen ke dalam list. Metode yang digunakan antara lain insertFirst (menambah di awal list), insertLast (menambah di akhir list), dan insertAfter (menyisipkan di tengah setelah elemen tertentu).
2. Delete (Penghapusan): Operasi mengambil atau menghapus elemen dari list yang dilanjutkan dengan dealokasi (pembebasan memori). Terdiri dari deleteFirst, deleteLast, dan deleteAfter.
3. View (Menampilkan): Operasi penelusuran (printInfo) mulai dari node first hingga Nil untuk menampilkan data.

## Guided 

### 1. list.h

```c++
#ifndef     LIST_H
#define     LIST_H
#define     Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

typedef struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodebaru);
void insertAfter(linkedlist &list, address nodebaru, address prev);
void insertLast(linkedlist &list, address nodebaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodehapus, address nodeprev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

#endif
```

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;

    return 0;
}
```
Penjelasan singkat guided:
Program di atas menerapkan konsep Singly Linked List menggunakan Abstract Data Type (ADT) dalam tiga file terpisah. File list.h bertugas sebagai cetak biru struct mahasiswa, file list.cpp menampung algoritma pengaturan pointer untuk alokasi, insert, dan delete memori, sedangkan file main.cpp digunakan untuk mengeksekusi operasi tersebut menggunakan data spesifik mahasiswa. Program membuktikan kemampuan linked list untuk menyisipkan data secara fleksibel di awal, akhir, maupun di tengah urutan.

## Unguided 

### 1. Buatlah ADT Singly Linked list di dalam file "Singlylist.h", implementasikan procedurenya di "Singlylist.cpp", dan buat program utama yang melakukan penambahan elemen.
### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter().

#### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);



void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = L.First->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == Nil) {
            P = L.First;
            L.First = Nil;
        } else {
            address Q = L.First;
            while (Q->next->next != Nil) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

```

#### main.cpp
```C++
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    cout << endl;

    address P;
    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    address Prec = L.First;
    deleteAfter(L, P, Prec);
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    cout << endl;

    deleteList(L);
    cout << "List Berhasil Terhapus" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}

```

### Output Unguided 1 & 2 :

##### Output 1 Menampilkan Hasil Insert Pertama
![Screenshot Output Unguided 1](https://github.com/gedeyogesvara-eng/109082500037-GedeYogiYogesvaraDitaDiasta-STD/blob/main/modul-4/img/modul%204%20soal%201.png)

##### Output 2 Menampilkan Sisa Node Setelah Dihapus
![Screenshot Output Unguided 2](https://github.com/gedeyogesvara-eng/109082500037-GedeYogiYogesvaraDitaDiasta-STD/blob/main/modul-4/img/modul%204%20soal%202.png)

penjelasan unguided 1 dan 2
Program singly linked list yang intinya program ini buat nyimpen data angka. buat ngejawab soal nomer 1 masukin data 2, 0, 8, 12, 9 ke memori. Karena di modul disuruh pakai fungsi insertFirst(), otomatis setiap data yang baru dimasukin bakal terus digeser jadi elemen yang paling depan first jadi hasil urutannya kebalik jadi 9 12 8 0 2.

buat ngejawab soal nomer 2 diminta menghapus beberapa data dari list buat angka 9 yang posisinya di paling depan, langsung putus menggunakan fungsi deleteFirst(). Terus buat angka 2 kan posisinya di ujung paling belakang itu cari pakai perulangan baru diputus pakai fungsi deleteLast(). Untuk menghapus angka 8 yang letaknya di tengah menggunakan fungsi deleteAfter() dengan ngejadiin pointer angka 12 sebagai previous. Kalo udah kehapus semua sesuai soal tinggal hitung sisa elemennya pakai fungsi nbList(), terus sisa listnya aku hapus bersih total dari memori pakai fungsi deleteList().

## Kesimpulan
Praktikum Modul 4 ini belajar gimana cara kerja ingly linked list pakai C++ beda dengan array yang tetap linked list ini lebih fleksibel karena setiap datanya itu disambungin menggunakan pointer di sini juga menerapkan operasi operasi penting kayak bikin list baru dari nol, nambahin data di awal insertFirst, sampai ngapus data di berbagai posisi beda, dimana itu di depan deleteFirst, di tengah deleteAfter, atau di paling belakang yang butuh perulangan dulu deleteLast. 

## Referensi
[1] Tim Asisten Praktikum Telkom University. (2024). *Modul 4 Singly Linked List (Bagian Pertama)*. Purwokerto: Laboratorium Informatika IT Telkom Purwokerto.
<br>[2] Triase. (2020). *Diktat Edisi Revisi: STRUKTUR DATA*. Medan: UNIVERSITAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
