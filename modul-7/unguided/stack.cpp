#include "stack.h"

int isEmpty(Stack S) {
    /* Top = 0 berarti kosong, sesuai komentar di stack.h dikembalikan 0 */
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;   /* Top 1..10 dipetakan ke indeks array 0..9 */
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.Top; i >= 1; i--) {
            cout << S.info[i - 1] << " ";
        }
        cout << endl;
    }
}

// 2. Tambahkan implementasi balikStack
void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    infotype val;
    // Pindahkan dari S ke temp1 (urutan jadi terbalik sementara)
    while (isEmpty(S) != 0) {
        pop(S, val);
        push(temp1, val);
    }
    // Pindahkan dari temp1 ke temp2 (urutan kembali normal seperti semula)
    while (isEmpty(temp1) != 0) {
        pop(temp1, val);
        push(temp2, val);
    }
    // Pindahkan dari temp2 kembali ke S (urutan menjadi terbalik di stack asli)
    while (isEmpty(temp2) != 0) {
        pop(temp2, val);
        push(S, val);
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    infotype val;

    // Jika elemen Top lebih besar dari x, pop ke stack sementara
    // agar urutan ascending dari bawah ke atas tetap terjaga
    while (isEmpty(S) != 0 && S.info[S.Top - 1] > x) {
        pop(S, val);
        push(temp, val);
    }

    // Masukkan elemen baru (x) di urutan yang tepat
    push(S, x);

    // Kembalikan elemen yang ditampung dari stack sementara ke S
    while (isEmpty(temp) != 0) {
        pop(temp, val);
        push(S, val);
    }
}

void getInputStream(Stack &S) {
    char ch;
    // Baca input terus menerus sampai menemukan newline (enter)
    while (cin.get(ch) && ch != '\n') {
        // Hanya push karakter angka (0-9) dengan konversi karakter ke nilai integer
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0');
        }
    }
}