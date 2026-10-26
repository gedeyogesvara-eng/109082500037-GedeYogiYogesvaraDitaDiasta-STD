#include "Singlylist.h"

void createList(List &L) {
    L.first = NIL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NIL) {
        P->info = x;
        P->next = NIL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NIL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (L.first == NIL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

address findElm(List L, infotype x) {
        address P = L.first;
        while (P != NIL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NIL;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != NIL) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}