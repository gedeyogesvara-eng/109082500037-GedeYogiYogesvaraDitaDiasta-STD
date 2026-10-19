# <h1 align="center">Laporan Praktikum Modul 3 ABSTRACT DATA TYPE (ADT)  </h1>
<p align="center">Gede Yogi Yogesvara Dita Diasta - 109082500037</p>

## Dasar Teori

Abstract Data Type (ADT) adalah sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Pada ADT yang lengkap, turut disertakan definisi invarian dari TYPE dan aksioma yang berlaku, dan ADT bersifat STATIK. Definisi type pada sebuah ADT dapat mengandung ADT lain, misalnya ADT waktu yang terdiri dari ADT JAM dan ADT DATE, atau ADT garis yang terdiri dari dua buah ADT POINT. Dalam bahasa C/C++, TYPE diterjemahkan menjadi struct, sedangkan PRIMITIF dalam konteks prosedural diterjemahkan menjadi fungsi atau prosedur.

### A. Primitif pada ADT<br/>
Primitif adalah operasi dasar yang dibuat untuk sebuah type primitif dibagi ke beberapa kelompok
#### 1. Konstruktor
Dipakai untuk membentuk nilai dari type tersebut. Semua variabel yang bertype itu harus dibentuk lewat konstruktor, dan namanya biasanya diawali Make atau create
#### 2. Selector dan Prosedur Pengubah Komponen
Selector dipakai untuk mengambil nilai komponen dari type biasanya namanya diawali Get sedangkan prosedur pengubah dipakai untuk mengganti nilai komponennya biasanya diawali Set
#### 3. Primitif
Validator komponen, destruktor/dealokator untuk menghapus objek beserta memorinya, baca/tulis untuk interaksi dengan input/output device, operator relasional, aritmatika, dan konversi dari type ke tipe dasar

### B. Implementasi ADT dalam Modul Program<br/>
Waktu diimplementasikan ADT biasanya dibagi jadi dua modul utama dan satu modul driver sebagai program utamanya
#### 1. File Header .h
Isinya spesifikasi type dan header dari primitif. Untuk fungsi dituliskan nama, domain, range, dan prekondisi (kalau ada). Untuk prosedur dituliskan initial state, final state, dan proses yang dilakukan
#### 2. File Body .cpp
Isinya realisasi atau kode dari primitif yang sudah dideklarasikan di header. Sebisa mungkin realisasinya memakai selector dan konstruktor
#### 3. File Driver main.cpp
Isinya program utama yang meng-include file header, lalu memanggil primitif yang sudah dibuat

## Guided 

### 1. Program Mahasiswa tanpa Pemisahan File Satu File

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "input nama : ";
    cin >> m.nim;
    cout << "input nilai 1 : ";
    cin >> m.nilai1;
    cout << "input nilai 2 : ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata = " << rata2(mhs) << endl;
    return 0;
}
```
Program ini terdapat type mahasiswa yang punya nim, nilai1, dan nilai2 ada dua primitif prosedur inputMhs untuk mengisi data parameternya pakai &m supaya perubahannya ikut tersimpan di variabel dan fungsi rata2 untuk menghitung rata-rata dari dua nilai untuk yang ini semuanya masih ditaruh dalam satu file.

### 2. Penerapan ADT dengan Pemisahan File (.h, .cpp, main.cpp)

**mahasiswa.h**
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2 (mahasiswa m);
#endif
```

**mahasiswa.cpp**
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama: ";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2)/2;
}

```

**main.cpp**
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
Program dipecah jadi tiga file dengan konsep ADT mahasiswa.h berisi struct dan header fungsi/prosedurnya ditambah #ifndef #define dan #endif supaya header tidak ter-include dua kali mahasiswa.cpp berisi isi dari fungsi dan prosedurnya sedangkan main.cpp hanya jadi program utama yang memanggil semuanya.

## Unguided 

### 1. Program yang menyimpan data mahasiswa (maks. 10) ke dalam array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts + 0.4*uas + 0.3*tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    mahasiswa data[MAX];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> data[i].nama;
        cout << "NIM   : ";
        cin >> data[i].nim;
        cout << "UTS   : ";
        cin >> data[i].uts;
        cout << "UAS   : ";
        cin >> data[i].uas;
        cout << "Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "Daftar Nilai Mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << endl;
        cout << "Nama        : " << data[i].nama << endl;
        cout << "NIM         : " << data[i].nim << endl;
        cout << "Nilai Akhir : " << data[i].nilaiAkhir << endl;
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
Screenshot Output Unguided 1![https://github.com/(username github)/(nama repository)/blob/main/Pertemuan3_Modul3/Output-Unguided1-1.png](https://github.com/gedeyogesvara-eng/109082500037-GedeYogiYogesvaraDitaDiasta-Modul03/blob/main/img/latihan1%20modul%203.png?raw=true)

Program menggunakan struct mahasiswa lalu menyimpannya di array data dengan ukuran maksimal 10 (MAX). Jumlah mahasiswa yang diinput maksimal 10 lewat do while supaya tidak lebih dari 10 nilai akhir tidak diinput manual, tapi dihitung oleh fungsi hitungNilaiAkhir memakai rumus 0.3UTS + 0.4UAS + 0.3*Tugas lalu hasilnya disimpan ke field nilaiAkhir setelah semua data terisi, program menampilkan seluruh data mahasiswa beserta nilai akhirnya

### 2. ADT pelajaran (pelajaran.h, pelajaran.cpp, main.cpp)

**pelajaran.h**
```C++
#include <iostream>
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```

**pelajaran.cpp**
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namamapel = namapel;
    pel.kodemapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namamapel << endl;
    cout << "nilai : " << pel.kodemapel << endl;
}
```

**main.cpp**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
Screenshot Output Unguided 2![(https://github.com/(username github)/(nama repository)/blob/main/Pertemuan3_Modul3/Output-Unguided2-1.png)](https://github.com/gedeyogesvara-eng/109082500037-GedeYogiYogesvaraDitaDiasta-Modul03/blob/main/img/latihan2%20modul%203.png?raw=true)

ADT pelajaran punya dua field yaitu namamapel dan kodemapel fungsi create_pelajaran sebagai konstruktor untuk membentuk satu data pelajaran dari nama dan kode yang dikirim prosedur tampil_pelajaran dipakai untuk menampilkan isinya lalu tulisan output disamakan dengan contoh di modul yaitu nama pelajaran : Struktur Data dan nilai : STD.

### 3. Program array 2D 3x3, pointer integer, tampil array, tukar isi array pada posisi tertentu, dan tukar isi variabel yang ditunjuk pointer

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int arrayA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int arrayB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int var1 = 100;
    int var2 = 999;
    int *ptr1 = &var1;
    int *ptr2 = &var2;

    cout << "Array A:" << endl;
    tampilArray(arrayA);
    cout << "Array B:" << endl;
    tampilArray(arrayB);

    cout << "Tukar isi array pada posisi (1,1):" << endl;
    tukarIsiArray(arrayA, arrayB, 1, 1);
    
    cout << "Array A setelah ditukar:" << endl;
    tampilArray(arrayA);
    cout << "Array B setelah ditukar:" << endl;
    tampilArray(arrayB);

    cout << "Tukar isi pointer:" << endl;
    cout << "Sebelum ditukar: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    
    cout << "Setelah ditukar: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
Screenshot Output Unguided 3![https://github.com/(username github)/(nama repository)/blob/main/Pertemuan3_Modul3/Output-Unguided3-1.png](https://github.com/gedeyogesvara-eng/109082500037-GedeYogiYogesvaraDitaDiasta-Modul03/blob/main/img/modul3%20modul%203.png?raw=true)

program membuat dua array 2D integer ukuran 3x3 arrayA dan arrayB dan dua pointer integer ptr1 dan ptr2 yang menunjuk ke var1 dan var2 prosedur tampilArray dipakai untuk mencetak isi array per baris dan kolom prosedur tukarIsiArray menukar isi arrayA dan arrayB pada posisi tertentu dan di main posisi yang dipakai adalah baris 2 kolom 2 jadi angka 9 di array A tertukar dengan angka 1 di array B lalu tukarPointer menukar nilai dua variabel lewat pointer memakai * sehingga isi var1 dan var2 bertukar dari 100 dan 999 menjadi 999 dan 100.

## Kesimpulan
Dari praktikum ini saya belajar bahwa ADT membantu intuk membuat sebuah type beserta operasinya dengan lebih rapi, karena type dan primitifnya dipisah dari program utama jadi dengan membagi program jadi file header .h body .cpp dan driver main.cpp kodenya jadi lebih mudah dibaca, lebih gampang diperbaiki dan bisa dipakai lagi di program lain

## Referensi
[1] Laboratorium Informatika. (2024). "Modul 3 Abstract Data Type (ADT)", Modul Praktikum Struktur Data. Bandung: Fakultas Informatika, Telkom University.
<br>