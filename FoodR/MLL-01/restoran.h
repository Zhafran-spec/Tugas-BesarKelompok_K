#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Restoran
{
  string idRestoran;
  string namaRestoran;
  string alamat;
  string kategoriRestoran;
  string kisaranHarga;
};

typedef Restoran infotypeRestoran;
typedef struct elmRestoran *adrRestoran;

struct elmRestoran
{
  infotypeRestoran info;
  adrRestoran next;
};

struct ListRestoran
{
  adrRestoran first;
};

/* I.S. Sembarang
   F.S. Terbentuk ListRestoran kosong (first = NULL) */
void createListRestoran(ListRestoran &LC);

/* I.S. Data infotypeRestoran x terdefinisi
   F.S. Mengembalikan alamat elemen restoran baru dengan info = x dan next = NULL */
adrRestoran allocateRestoran(infotypeRestoran x);

/* I.S. ListRestoran LC mungkin kosong, C terdefinisi
   F.S. Elemen C ditambahkan sebagai elemen pertama di LC */
void insertFirstRestoran(ListRestoran &LC, adrRestoran C);

/* I.S. ListRestoran LC mungkin kosong, C terdefinisi
   F.S. Elemen C ditambahkan sebagai elemen terakhir di LC */
void insertLastRestoran(ListRestoran &LC, adrRestoran C);

/* I.S. ListRestoran LC tidak kosong, Prec terdefinisi
   F.S. Elemen C disisipkan setelah elemen Prec */
void insertAfterRestoran(ListRestoran &LC, adrRestoran Prec, adrRestoran C);

/* I.S. ListRestoran LC mungkin kosong
   F.S. Elemen pertama LC dihapus dan alamatnya disimpan di C */
void deleteFirstRestoran(ListRestoran &LC, adrRestoran &C);

/* I.S. ListRestoran LC mungkin kosong
   F.S. Elemen terakhir LC dihapus dan alamatnya disimpan di C */
void deleteLastRestoran(ListRestoran &LC, adrRestoran &C);

/* I.S. ListRestoran LC tidak kosong, Prec terdefinisi
   F.S. Elemen setelah Prec dihapus dan alamatnya disimpan di C */
void deleteAfterRestoran(ListRestoran &LC, adrRestoran Prec, adrRestoran &C);

/* I.S. ListRestoran LC dan idRestoran terdefinisi
   F.S. Mengembalikan alamat restoran jika ditemukan, NULL jika tidak */
adrRestoran findRestoran(ListRestoran LC, string idRestoran);

/* I.S. ListRestoran LC terdefinisi
   F.S. Seluruh data restoran pada LC ditampilkan ke layar */
void showRestoran(ListRestoran LC);

#endif // RESTORAN_H_INCLUDED