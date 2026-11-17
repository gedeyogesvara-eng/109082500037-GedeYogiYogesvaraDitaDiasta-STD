/*file: queue.h
contoh ADT queue dengan representasi fisik pointer
representasi address dengan pointer
info tipe adalah integer */

#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include <iostream>
using namespace std;

#define Nil NULL
#define boolean bool

typedef int infotype;
typedef struct elmQ *address;

struct elmQ {
    infotype info;
    address next;
};

/* deklarasi tipe data queue, terdiri dari head dan tail, queue kosong jika
   head == Nil */
struct queue {
    address head, tail;
};

/*prototype*/
/********* pengecekan apakah queue kosong ***********/
boolean isEmpty (queue Q);
/*mengembalikan nilai true jika queue kosong*/

/********* pembuatan queue kosong *********/
void CreateQueue (queue &Q);
/* I.S. sembarang
   F.S. terbentuk queue kosong*/

/********* manajemen memori *********/
address alokasi (infotype X);
/* mengirimkan address dari alokasi elemen
   jika alokasi berhasil, maka nilai address tidak Nil dan jika gagal, nilai
   address Nil */

void dealokasi (address P);
/* I.S. P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

/********* pencarian sebuah elemen list *********/
address findElm (queue Q, infotype X);
/* mencari apakah ada elemen queue dengan P->info = X
   jika ada, mengembalikan address elemen tsb, dan Nil jika sebaliknya */

boolean fFindElm (queue Q, address P);
/* mencari apakah ada elemen queue dengan alamat P
   mengembalikan true jika ada dan false jika tidak ada */

/********* penambahan elemen **********/
void insert (queue &Q, address P);
/* I.S. sembarang, P sudah dialokasikan
   F.S. menempatkan elemen beralamat P pada akhir queue*/

/********* penghapusan sebuah elemen **********/
void deleteQueue (queue &Q, address &P);
/* I.S. queue tidak kosong
   F.S. menunjuk elemen pertama queue, head dari queue menunjuk pada next
   elemen head yang lama. Queue mungkin menjadi kosong */

/********* proses semua elemen queue**********/
void printInfo (queue Q);
/* I.S. queue mungkin tidak kosong
   F.S. jika queue tidak kosong, maka menampilkan semua info yang ada pada
   queue */

int nbList (queue Q);
/* mengembalikan jumlah elemen pada queue */

void delAll (queue &Q);
/* menghapus semua elemen pada queue dan semua elemen di-dealokasi */

#endif