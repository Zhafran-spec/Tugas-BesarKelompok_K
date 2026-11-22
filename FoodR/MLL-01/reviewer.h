#ifndef REVIEWER_H_INCLUDED
#define REVIEWER_H_INCLUDED

#include <iostream>
#include <string>
#include "kunjungan.h"

using namespace std;

struct FoodReviewer
{
  string idReviewer;
  string nama;
  string platform;
  int jumlahPengikut;
};

typedef FoodReviewer infotypeReviewer;
typedef struct elmReviewer *adrReviewer;

struct elmReviewer
{
  infotypeReviewer info;
  ListKunjungan relasi; // MLL-01: ListRelasi berada di dalam elemen Parent
  adrReviewer next;
  adrReviewer prev;
};

struct ListReviewer
{
  adrReviewer first;
  adrReviewer last;
};

/* I.S. Sembarang
   F.S. Terbentuk ListReviewer kosong (first = NULL, last = NULL) */
void createListReviewer(ListReviewer &LP);

/* I.S. Data infotypeReviewer x terdefinisi
   F.S. Mengembalikan alamat elemen reviewer baru dengan info = x dan ListKunjungan kosong */
adrReviewer allocateReviewer(infotypeReviewer x);

/* I.S. ListReviewer LP mungkin kosong, P terdefinisi
   F.S. Elemen P ditambahkan sebagai elemen pertama di LP */
void insertFirstReviewer(ListReviewer &LP, adrReviewer P);

/* I.S. ListReviewer LP mungkin kosong, P terdefinisi
   F.S. Elemen P ditambahkan sebagai elemen terakhir di LP */
void insertLastReviewer(ListReviewer &LP, adrReviewer P);

/* I.S. ListReviewer LP tidak kosong, Prec terdefinisi
   F.S. Elemen P disisipkan setelah elemen Prec */
void insertAfterReviewer(ListReviewer &LP, adrReviewer Prec, adrReviewer P);

/* I.S. ListReviewer LP mungkin kosong
   F.S. Elemen pertama LP dihapus dan alamatnya disimpan di P */
void deleteFirstReviewer(ListReviewer &LP, adrReviewer &P);

/* I.S. ListReviewer LP mungkin kosong
   F.S. Elemen terakhir LP dihapus dan alamatnya disimpan di P */
void deleteLastReviewer(ListReviewer &LP, adrReviewer &P);

/* I.S. ListReviewer LP tidak kosong, Prec terdefinisi
   F.S. Elemen setelah Prec dihapus dan alamatnya disimpan di P */
void deleteAfterReviewer(ListReviewer &LP, adrReviewer Prec, adrReviewer &P);

/* I.S. ListReviewer LP dan idReviewer terdefinisi
   F.S. Mengembalikan alamat reviewer jika ditemukan, NULL jika tidak */
adrReviewer findReviewer(ListReviewer LP, string idReviewer);

/* I.S. ListReviewer LP terdefinisi
   F.S. Seluruh data Food Reviewer pada LP ditampilkan ke layar */
void showReviewer(ListReviewer LP);

/* I.S. ListReviewer LP terdefinisi
   F.S. Seluruh data reviewer beserta daftar restoran yang dikunjunginya ditampilkan */
void showAllMLL(ListReviewer LP);

#endif // REVIEWER_H_INCLUDED