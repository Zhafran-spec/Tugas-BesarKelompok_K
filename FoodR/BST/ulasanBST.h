#ifndef ULASANBST_H_INCLUDED
#define ULASANBST_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct UlasanKuliner
{
  string idReviewer;
  string idRestoran;
  string tanggalKunjungan;
  string namaMenu;
  float ratingRasa;
  float ratingHarga;
  float ratingPelayanan;
  float ratingSuasana;
  float ratingKeseluruhan; // Key BST
  int estimasiBiaya;
  string komentar;
  bool rekomendasi;
  string statusUlasan;
};

typedef UlasanKuliner infotypeBST;
typedef struct elemenNode *adrNode;

struct elemenNode
{
  infotypeBST info;
  adrNode left;
  adrNode right;
};

struct bst
{
  adrNode root;
};

/* I.S. Sembarang
   F.S. Terbentuk BST kosong (root = NULL) */
void createBST(bst &T);

/* I.S. Data infotypeBST x terdefinisi
   F.S. Mengembalikan alamat node baru dengan info = x, left = NULL, right = NULL */
adrNode allocateNode(infotypeBST x);

/* I.S. root terdefinisi (mungkin NULL), P adalah node baru
   F.S. Node P disisipkan ke dalam BST berdasarkan key ratingKeseluruhan */
void insertNode(adrNode &root, adrNode P);

/* I.S. root terdefinisi, keyRating terdefinisi
   F.S. Mengembalikan alamat node jika ratingKeseluruhan ditemukan, NULL jika tidak */
adrNode findNode(adrNode root, float keyRating);

/* I.S. root terdefinisi (tidak kosong)
   F.S. Mengembalikan alamat node dengan key ratingKeseluruhan terkecil */
adrNode findMin(adrNode root);

/* I.S. root terdefinisi (tidak kosong)
   F.S. Mengembalikan alamat node dengan key ratingKeseluruhan terbesar */
adrNode findMax(adrNode root);

/* I.S. root terdefinisi, keyRating terdefinisi
   F.S. Node dengan keyRating dihapus dari BST (jika ada) sambil menjaga sifat BST */
void deleteNode(adrNode &root, float keyRating);

/* I.S. root terdefinisi
   F.S. Menampilkan seluruh ulasan secara Pre-Order (Root - Left - Right) */
void printPreOrder(adrNode root);

/* I.S. root terdefinisi
   F.S. Menampilkan seluruh ulasan secara In-Order (Left - Root - Right) */
void printInOrder(adrNode root);

/* I.S. root terdefinisi
   F.S. Menampilkan seluruh ulasan secara Post-Order (Left - Right - Root) */
void printPostOrder(adrNode root);

#endif // ULASANBST_H_INCLUDED