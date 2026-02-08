#include <stdio.h>
#include <string.h>
#include "book.h"

Book books[MAX_BOOK];
int book_count = 0;

void insert_book() {
    Book b;

    sprintf(b.kode, "BK%03d", book_count + 1);

    printf("Nama buku  : ");
    scanf(" %[^\n]", b.nama);

    printf("Jenis buku : ");
    scanf(" %[^\n]", b.jenis);

    printf("Harga buku : ");
    scanf("%lf", &b.harga);

    books[book_count++] = b;

    printf("Buku berhasil ditambahkan.\n");
}

void view_books() {
    if (book_count == 0) {
        printf("Data buku kosong.\n");
        return;
    }

    for (int i = 0; i < book_count; i++) {
        printf("%d. %s | %s | %s | %.2lf\n",
               i + 1,
               books[i].kode,
               books[i].nama,
               books[i].jenis,
               books[i].harga);
    }
}

void delete_book() {
    int index;

    if (book_count == 0) {
        printf("Data buku kosong.\n");
        return;
    }

    view_books();

    printf("Pilih index buku yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > book_count) {
        printf("Index tidak valid.\n");
        return;
    }

    for (int i = index - 1; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }

    book_count--;

    printf("Data Successfully delete..\n");
}
