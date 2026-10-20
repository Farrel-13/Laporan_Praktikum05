# <h1 align="center">Laporan Praktikum Modul 5 SINGLY LINKED LIST (BAGIAN KEDUA) </h1>

<p align="center">Muhammad Farrel Argiyanto - 109082500018</p>

## Dasar Teori

Singly Linked List merupakan struktur data dinamis yang terdiri dari node-node yang saling terhubung menggunakan pointer. Setiap node memiliki dua bagian, yaitu info untuk menyimpan data dan next untuk menunjukkan alamat node berikutnya. Struktur list memiliki pointer first yang menunjukkan node pertama. Jika list kosong, pointer first bernilai Nil atau NULL. Dengan struktur tersebut, data dapat ditambahkan, dihapus, dan diproses sesuai kebutuhan program.

Salah satu operasi dasar pada Singly Linked List adalah searching, yaitu proses mencari node tertentu dengan mengunjungi setiap node secara berurutan sampai data yang dicari ditemukan atau seluruh node telah diperiksa. Operasi pencarian dapat dilakukan menggunakan fungsi findElm() untuk memperoleh alamat node berdasarkan nilai informasi yang dicari. Jika data ditemukan, fungsi mengembalikan alamat node tersebut, sedangkan jika tidak ditemukan, fungsi mengembalikan Nil. Pencarian juga dapat dilakukan menggunakan fungsi fFindElm() untuk memeriksa keberadaan node berdasarkan alamatnya.

Selain pencarian, Singly Linked List memiliki operasi penyisipan dan penghapusan node. Penyisipan dapat dilakukan menggunakan insertFirst(), insertAfter(), dan insertLast(), yaitu untuk menambahkan node pada awal list, setelah node tertentu, atau pada akhir list. Penghapusan dapat dilakukan menggunakan delFirst(), delLast(), delAfter(), dan delP(), sesuai dengan posisi atau nilai data yang ingin dihapus. Operasi tersebut memerlukan pengaturan pointer agar hubungan antarnode tetap terjaga setelah terjadi perubahan.

Modul ini juga membahas operasi untuk memproses seluruh elemen list. Fungsi printInfo() digunakan untuk menampilkan informasi dari setiap node, sedangkan nbList() digunakan untuk menghitung jumlah node dalam list. Fungsi delAll() berfungsi menghapus seluruh elemen dan membebaskan memori yang digunakan. Selain itu, terdapat invertList() untuk membalik urutan elemen, copyList() untuk menyalin list ke list lain, dan fCopyList() untuk menghasilkan salinan list.

Dalam implementasinya, Singly Linked List disusun menggunakan konsep Abstract Data Type (ADT), yaitu dengan memisahkan deklarasi struktur data dan prototipe fungsi dari implementasi operasinya. Pada modul ini, deklarasi tipe data, struktur node, struktur list, dan fungsi ditempatkan dalam file header .h, sedangkan implementasi operasi ditulis dalam file .cpp. Pemisahan tersebut membantu membuat program lebih terorganisasi dan memudahkan pengelolaan setiap operasi linked list.

Dengan mempelajari materi ini, pemahaman mengenai pencarian data, penyisipan dan penghapusan node, penghitungan jumlah elemen, serta pengolahan seluruh isi list dapat ditingkatkan. Operasi-operasi tersebut menjadi dasar untuk mengelola data secara dinamis menggunakan pointer dalam bahasa C++.

## Guided

### 1. Implementasi Singly Linked List

#### a. File `listBuah.h`

```cpp
// Header guard digunakan untuk mencegah file header yang sama
// di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah
{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; // Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; // Mendefinisikan alias address sebagai pointer ke struct node

struct node
{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist
{ // ini linked list nya
    address first;
};

// semua function & prosedur yang akan dipakai
// Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

// materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

#### b. File `listBuah.cpp`

```cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List Kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
// prosedur-prosedur untuk searching data
// prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

// prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if (harga >= hargaAwal && harga <= hargaAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}

```

#### c. File `main.cpp`

```cpp
#include "listBuah.h"

#include <iostream>
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### 2. Penjelasan Program

Program ini mengimplementasikan Singly Linked List untuk menyimpan dan mengelola data buah yang terdiri dari nama, jumlah, dan harga. Pada file `listBuah.h`, didefinisikan struktur data serta deklarasi fungsi yang digunakan dalam program. File `listBuah.cpp` berisi implementasi operasi linked list, termasuk penambahan node, penghapusan node, pembaruan data, dan pencarian data. Sementara itu, file `main.cpp` digunakan untuk menjalankan dan menguji seluruh operasi tersebut.

Pada awal program, dibuat list kosong menggunakan fungsi `createList()`, kemudian lima data buah, yaitu Jeruk, Apel, Pir, Semangka, dan Durian, dimasukkan ke dalam list menggunakan fungsi `alokasi()`, `insertFirst()`, `insertLast()`, dan `insertAfter()`. Setelah itu, data ditampilkan menggunakan `printList()` dan jumlah node dihitung dengan `nbList()`. Program kemudian melakukan pembaruan data melalui `updateFirst()`, `updateLast()`, dan `updateAfter()`. Proses pencarian dilakukan menggunakan `FindNodeByData()` untuk mencari buah berdasarkan nama, `FindNodeByAddress()` untuk mencari node berdasarkan alamat, serta `FindNodeByRange()` untuk menampilkan buah berdasarkan rentang harga. Selanjutnya, penghapusan data dilakukan menggunakan `delFirst()`, `delLast()`, dan `delAfter()`. Pada bagian akhir, fungsi `deleteList()` digunakan untuk menghapus seluruh node sehingga list kembali kosong. Melalui program ini, operasi dasar Singly Linked List serta penerapan update dan searching dapat dipahami secara langsung.

## Unguided

### Buat ADT Singly Linked list, Carilah elemen dengan info 8 dengan membuat fungsi baru,dan Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

##### Singlylist.h

```cpp
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```

##### Singlylist.cpp

```cpp
#include "Singlylist.h"

void createList(List &L)
{
    L.first = Nil;
}

address alokasi(infotype x)
{
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P)
{
    delete P;
    P = Nil;
}

void printInfo(List L)
{
    address P = L.first;

    while (P != Nil)
    {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x)
{
    address P = L.first;

    while (P != Nil)
    {
        if (P->info == x)
        {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

int totalInfo(List L)
{
    int total = 0;
    address P = L.first;

    while (P != Nil)
    {
        total += P->info;
        P = P->next;
    }

    return total;
}
```

##### main.cpp

```cpp
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
```

### Output Unguided 1

#### Output 1

![Screenshot Output Unguided 1](https://github.com/Farrel-13/Laporan_Praktikum05/blob/main/foto_output/ouputno123.png?raw=true)


Program ini mengimplementasikan Singly Linked List menggunakan tiga file, yaitu `Singlylist.h` untuk deklarasi struktur dan fungsi, `Singlylist.cpp` untuk implementasi fungsi, serta `main.cpp` sebagai program utama. Fungsi `createList()` digunakan untuk membuat list kosong, sedangkan `alokasi()` membuat node baru yang berisi nilai integer. Fungsi `insertFirst()` menambahkan setiap node pada awal list sehingga urutan data menjadi `9 12 8 0 2`, sesuai dengan soal latihan Modul 5. Selanjutnya, fungsi `printInfo()` digunakan untuk menampilkan seluruh elemen, `findElm()` untuk mencari elemen bernilai `8`, dan `totalInfo()` untuk menghitung jumlah seluruh nilai dalam list. Hasil pencarian menunjukkan bahwa nilai `8` ditemukan, sedangkan hasil penjumlahan seluruh elemen adalah `31`. Setelah seluruh proses selesai, node dihapus dari memori untuk mencegah penggunaan memori yang tidak diperlukan.


## Kesimpulan

Berdasarkan praktikum Modul 5 tentang Singly Linked List (Bagian Kedua), dapat disimpulkan bahwa Singly Linked List merupakan struktur data dinamis yang menghubungkan setiap node menggunakan pointer `next`. Pada bagian Guided, dilakukan pengelolaan data buah melalui operasi penambahan, penghapusan, pembaruan, dan pencarian data berdasarkan nama, alamat node, serta rentang harga. Pada bagian Unguided, Singly Linked List diterapkan untuk menyimpan data integer dengan operasi `insertFirst()`, `printInfo()`, `findElm()`, dan `totalInfo()`. Hasil pengujian menunjukkan bahwa data dapat ditampilkan dengan urutan `9 12 8 0 2`, nilai `8` berhasil ditemukan, dan jumlah seluruh elemen adalah `31`. Melalui praktikum ini, pemahaman mengenai penggunaan pointer, alokasi dan dealokasi memori, serta penerapan operasi update dan searching pada Singly Linked List dapat ditingkatkan.


## Referensi

[1] Tim Praktikum Struktur Data. (t.t.). Modul 5: Singly Linked List (Bagian Kedua). Modul Praktikum Struktur Data, hlm. 47–50.

[2] Pai, G. A. V. (2023). Linked Lists. Dalam A Textbook of Data Structures and Algorithms 1. Wiley. https://onlinelibrary.wiley.com/doi/10.1002/9781394192076.ch6
