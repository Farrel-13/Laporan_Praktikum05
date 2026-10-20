#include "Singlylist.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5;
    address hasilCari;

    createList(L);

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

    cout << "--- ISI SINGLY LINKED LIST ---" << endl;
    printInfo(L);

    cout << "\n--- PENCARIAN ELEMEN ---" << endl;
    hasilCari = findElm(L, 8);

    if (hasilCari != Nil)
    {
        cout << hasilCari->info << " ditemukan dalam list" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan dalam list" << endl;
    }

    cout << "\n--- TOTAL INFO ELEMEN ---" << endl;
    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    while (L.first != Nil)
    {
        address P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }

    return 0;
}