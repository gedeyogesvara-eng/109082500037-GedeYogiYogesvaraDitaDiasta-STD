#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Buat list kosong
    linkedlist daftarBuah;
    createList(daftarBuah);

    // 2. Tambahkan data untuk testing
    cout << "--- Menambahkan Data Buah ---" << endl;
    address buah1 = alokasi("Apel", 10, 15000);
    insertFirst(daftarBuah, buah1);

    address buah2 = alokasi("Jeruk", 5, 20000);
    insertLast(daftarBuah, buah2);
    
    address buah3 = alokasi("Mangga", 12, 12000);
    insertFirst(daftarBuah, buah3);

    // 3. Tampilkan list
    printList(daftarBuah);
    cout << "Jumlah buah di list: " << nbList(daftarBuah) << "\n\n";

    // 4. Test searching
    cout << "--- Test Pencarian ---" << endl;
    FindNodeByData(daftarBuah, "Jeruk");

    // 5. Bersihkan memori sebelum program selesai
    deleteList(daftarBuah);

    return 0; // Wajib ada untuk menandakan program selesai tanpa error
}