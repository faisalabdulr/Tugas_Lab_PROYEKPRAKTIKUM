#include <stdio.h>
#include <string.h>

#define MAX_BOOK 100

// STRUCT HARUS SAMA PERSIS DENGAN MAIN.C
typedef struct {
    char kode[10];
    char nama[50];
    char jenis[30];
    float harga;
} Book;

/* ==========
   DATA GLOBAL
   ========== */
Book books[MAX_BOOK] = {
    {"BK001", "Algoritma", "Teknik", 75000},
    {"BK002", "Basis Data", "Teknik", 65000},
    {"BK003", "Pemrograman C", "Teknik", 85000}
};
int book_count = 3;

/* ==========
   FUNGSI SORT (DIPANGGIL MAIN)
   ========== */
void sort_books(int sort_type) {
    int i, j, max_idx;
    Book temp;

    if (book_count == 0) {
        printf("Tidak ada data buku untuk diurutkan.\n");
        return;
    }

    // (a) Bubble Sort - Nama (Ascending)
    if (sort_type == 1) {
        for (i = 0; i < book_count - 1; i++) {
            for (j = 0; j < book_count - i - 1; j++) {
                if (strcmp(books[j].nama, books[j + 1].nama) > 0) {
                    temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        printf("Buku berhasil diurutkan berdasarkan nama (Ascending).\n");
    }

    // (b) Selection Sort - Harga (Descending)
    else if (sort_type == 2) {
        for (i = 0; i < book_count - 1; i++) {
            max_idx = i;
            for (j = i + 1; j < book_count; j++) {
                if (books[j].harga > books[max_idx].harga) {
                    max_idx = j;
                }
            }
            temp = books[i];
            books[i] = books[max_idx];
            books[max_idx] = temp;
        }
        printf("Buku berhasil diurutkan berdasarkan harga (Descending).\n");
    }

    // tampilkan hasil (versi sederhana)
    printf("\nHasil Sorting:\n");
    for (i = 0; i < book_count; i++) {
        printf("%d. %s | %s | Rp %.2f\n",
               i + 1,
               books[i].kode,
               books[i].nama,
               books[i].harga);
    }
}
