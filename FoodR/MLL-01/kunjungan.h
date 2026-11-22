#ifndef KUNJUNGAN_H_INCLUDED
#define KUNJUNGAN_H_INCLUDED

#include <iostream>
#include <string>
#include "restoran.h"

using namespace std;

struct RiwayatKunjungan
{
  string tanggalKunjunganPertama;
  string tanggalKunjunganTerakhir;
  int jumlahKunjungan;
  string statusHubungan;
};

typedef RiwayatKunjungan infotypeKunjungan;
typedef struct elmKunjungan *adrKunjungan;

struct elmKunjungan
{
  infotypeKunjungan info;
  adrRestoran valChild;
  adrKunjungan next;
  adrKunjungan prev;
};

struct ListKunjungan
{
  adrKunjungan first;
  adrKunjungan last;
};

/* I.S. Sembarang
   F.S. Terbentuk ListKunjungan kosong (first = NULL, last = NULL) */
void createListKunjungan(ListKunjungan &LR);

/* I.S. Data infotypeKunjungan x dan alamat child C terdefinisi
   F.S. Mengembalikan alamat elemen kunjungan baru yang menunjuk ke C */
adrKunjungan allocateKunjungan(infotypeKunjungan x, adrRestoran C);

/* I.S. ListKunjungan LR mungkin kosong, R terdefinisi
   F.S. Elemen R ditambahkan sebagai elemen pertama di LR */
void insertFirstKunjungan(ListKunjungan &LR, adrKunjungan R);

/* I.S. ListKunjungan LR mungkin kosong, R terdefinisi
   F.S. Elemen R ditambahkan sebagai elemen terakhir di LR */
void insertLastKunjungan(ListKunjungan &LR, adrKunjungan R);

/* I.S. ListKunjungan LR tidak kosong, Prec terdefinisi
   F.S. Elemen R disisipkan setelah elemen Prec */
void insertAfterKunjungan(ListKunjungan &LR, adrKunjungan Prec, adrKunjungan R);

/* I.S. ListKunjungan LR mungkin kosong
   F.S. Elemen pertama LR dihapus dan alamatnya disimpan di R */
void deleteFirstKunjungan(ListKunjungan &LR, adrKunjungan &R);

/* I.S. ListKunjungan LR mungkin kosong
   F.S. Elemen terakhir LR dihapus dan alamatnya disimpan di R */
void deleteLastKunjungan(ListKunjungan &LR, adrKunjungan &R);

/* I.S. ListKunjungan LR tidak kosong, Prec terdefinisi
   F.S. Elemen setelah Prec dihapus dan alamatnya disimpan di R */
void deleteAfterKunjungan(ListKunjungan &LR, adrKunjungan Prec, adrKunjungan &R);

/* I.S. ListKunjungan LR dan idRestoran terdefinisi
   F.S. Mengembalikan alamat relasi kunjungan jika ditemukan, NULL jika tidak */
adrKunjungan findKunjungan(ListKunjungan LR, string idRestoran);

#endif // KUNJUNGAN_H_INCLUDED