# <h1 align="center">Laporan Praktikum Modul 4 SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>

<p align="center">Muhammad Farrel Argiyanto - 109082500018</p>

## Dasar Teori

Linked list merupakan salah satu struktur data yang terdiri dari sekumpulan elemen yang saling terhubung dan bersifat dinamis, sehingga jumlah elemennya dapat bertambah atau berkurang sesuai kebutuhan. Setiap elemen dapat menyimpan data tunggal maupun data majemuk. Berbeda dengan array yang memiliki ukuran tetap, linked list menggunakan pointer untuk menghubungkan elemen satu dengan elemen lainnya sehingga pengelolaan data menjadi lebih fleksibel.

Singly Linked List merupakan salah satu jenis linked list yang memiliki satu arah penghubung antarelemen. Setiap elemen atau node terdiri dari dua bagian, yaitu info untuk menyimpan data dan next untuk menyimpan alamat elemen berikutnya. Elemen pertama ditunjuk oleh pointer first atau head, sedangkan elemen terakhir menunjuk ke NULL yang menandakan bahwa tidak ada elemen selanjutnya. Karena hanya memiliki satu arah pointer, penelusuran data dilakukan dari elemen pertama menuju elemen berikutnya.

Dalam implementasinya, Singly Linked List menggunakan pointer untuk mengakses dan menghubungkan setiap node. Proses pembentukan node membutuhkan alokasi memori, yang dalam C++ dapat dilakukan menggunakan operator new. Sementara itu, memori yang tidak lagi digunakan dapat dibebaskan menggunakan operator delete. Pengelolaan memori ini penting agar setiap elemen dapat dibuat dan dihapus sesuai kebutuhan program.

Operasi dasar pada Singly Linked List meliputi pembuatan list (Create List), penyisipan elemen (Insert), penghapusan elemen (Delete), penelusuran dan penampilan data (View), pencarian data (Searching), serta pengubahan data (Update). Penyisipan dapat dilakukan pada awal list (Insert First), akhir list (Insert Last), atau setelah node tertentu (Insert After). Penghapusan juga dapat dilakukan pada awal, akhir, maupun setelah elemen tertentu sesuai kebutuhan.

Dalam pemrograman C++, implementasi Singly Linked List dapat disusun menggunakan struktur data yang berisi informasi dan pointer next, serta struktur List yang memiliki pointer first. Deklarasi tipe data dan prototipe fungsi dapat ditempatkan pada file header .h, sedangkan implementasi operasi list ditulis pada file .cpp. Pemisahan tersebut membuat program lebih terstruktur dan memudahkan pengelolaan operasi linked list.

Dengan demikian, Singly Linked List dapat digunakan untuk mengelola kumpulan data yang jumlah elemennya dapat berubah selama program berjalan. Pemahaman mengenai node, pointer, alokasi memori, penyisipan, penghapusan, dan penelusuran merupakan dasar penting untuk menerapkan struktur data ini dalam program C++.

## Guided

### 1. Implementasi Singly Linked List

##### list.h

```cpp
#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H
#define Nil NULL

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedList {
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```

##### list.cpp

```cpp
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    return List.first == Nil;
}

void createList(linkedList &List) {
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
    node = Nil;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address prev) {
    if (prev != Nil) {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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

void delFirst(linkedList &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        List.first = List.first->next;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;

        if (nodeHapus->next == Nil) {
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            address nodePrev = Nil;

            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }

            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;

        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;

    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

void deleteList(linkedList &List) {
    address nodeBantu = List.first;

    while (nodeBantu != Nil) {
        address nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }

    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

##### main.cpp

```cpp
#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;

    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211100014", 21);
    nodeC = alokasi("Rizal", "2311100029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;

    return 0;
}
```

Program ini menerapkan konsep **Singly Linked List** dengan memisahkan deklarasi struktur dan fungsi ke dalam file `list.h`, implementasi fungsi ke dalam `list.cpp`, dan program utama ke dalam `main.cpp`. Struktur data mahasiswa terdiri dari `nama`, `nim`, dan `umur`, yang disimpan dalam setiap node. Fungsi `createList()` digunakan untuk membuat list kosong, sedangkan `alokasi()` dan `dealokasi()` mengatur alokasi serta pembebasan memori. Operasi `insertFirst()`, `insertLast()`, dan `insertAfter()` digunakan untuk menambahkan node, sementara `delFirst()`, `delLast()`, dan `delAfter()` digunakan untuk menghapus node. Fungsi `printList()` menampilkan data mahasiswa dan `nbList()` menghitung jumlah node. Terakhir, `deleteList()` menghapus seluruh node sehingga list kembali kosong.

## Unguided

### 1. Buat program Singly Linked List menggunakan ADT yang menyimpan data bertipe integer. Program menggunakan operasi `createList()`, `alokasi()`, `insertFirst()`, dan `printInfo()` untuk membuat list, mengalokasikan node baru, menambahkan node pada awal list, serta menampilkan seluruh data.

##### Singlylist.h

```cpp
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address prec);
int nbList(List L);
void deleteList(List &L);

#endif
```

##### Singlylist.cpp

```cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L) {
    if (L.first != Nil) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == Nil) return;

    address P = L.first;

    if (P->next == Nil) {
        L.first = Nil;
        dealokasi(P);
        return;
    }

    address prec = Nil;
    while (P->next != Nil) {
        prec = P;
        P = P->next;
    }

    prec->next = Nil;
    dealokasi(P);
}

void deleteAfter(List &L, address prec) {
    if (prec != Nil && prec->next != Nil) {
        address P = prec->next;
        prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }

    cout << "- List Berhasil Terhapus -" << endl;
}
```

##### main.cpp

```cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

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

    printInfo(L);

    return 0;
}
```

### Output Unguided 1

#### Output 1

![Screenshot Output Unguided 1](https://github.com/Farrel-13/Laporan_Praktikum04/blob/main/ouput/output01.png?raw=true)


Program ini mengimplementasikan Singly Linked List menggunakan tiga file, yaitu `Singlylist.h` untuk deklarasi struktur dan fungsi, `Singlylist.cpp` untuk implementasi fungsi, serta `main.cpp` sebagai program utama. Fungsi `createList()` digunakan untuk membuat list kosong, sedangkan `alokasi()` membuat node baru yang berisi nilai integer. Fungsi `insertFirst()` menambahkan setiap node pada awal list sehingga urutan data menjadi `9 12 8 0 2`, sesuai dengan soal latihan Modul 4.

### 2.Modifikasi program sebelumnya dengan melakukan penghapusan node menggunakan `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`. Setelah itu, hitung jumlah node yang tersisa menggunakan `nbList()` dan hapus seluruh node dengan `deleteList()`.

##### main.cpp

```cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

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

    deleteFirst(L);
    deleteLast(L);

    address prec = L.first;
    deleteAfter(L, prec);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2

Output 2

![Screenshot Output Unguided 1](https://github.com/Farrel-13/Laporan_Praktikum04/blob/main/ouput/output02.png?raw=true)


Program ini melanjutkan implementasi Singly Linked List dengan melakukan tiga operasi penghapusan. Fungsi `deleteFirst()` menghapus node pertama yang bernilai 9, `deleteLast()` menghapus node terakhir yang bernilai 2, dan `deleteAfter()` menghapus node bernilai 8 yang berada setelah node 12. Hasilnya, list menyisakan nilai `12 0` dengan jumlah dua node. Selanjutnya, fungsi `deleteList()` menghapus seluruh node yang tersisa sehingga jumlah node menjadi nol.

## Kesimpulan

Berdasarkan praktikum Modul 4 tentang Singly Linked List, dapat disimpulkan bahwa Singly Linked List merupakan struktur data dinamis yang menghubungkan setiap node menggunakan pointer `next`. Pada bagian Guided, dilakukan pengelolaan data mahasiswa melalui operasi penambahan, penghapusan, penampilan, dan penghitungan jumlah node. Pada bagian Unguided, Singly Linked List diterapkan untuk menyimpan data integer dengan operasi `insertFirst()`, `deleteFirst()`, `deleteLast()`, dan `deleteAfter()`. Selain itu, fungsi `nbList()` digunakan untuk menghitung jumlah node, sedangkan `deleteList()` digunakan untuk menghapus seluruh elemen dalam list. Melalui praktikum ini, pemahaman mengenai pointer, alokasi dan dealokasi memori, serta pengelolaan node dalam Singly Linked List dapat ditingkatkan.

## Referensi

[1] Tim Praktikum Struktur Data. (t.t.). Modul 4: Singly Linked List (Bagian Pertama). Modul Praktikum Struktur Data, hlm. 36–46.

[2] Brandle, S., Robergé, J., Geisler, J., & Whittington, D. (2008). C++ Data Structures: A Laboratory Course (3rd ed.). Jones & Bartlett Learning.
