#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOK 100

typedef struct {
    char kode[10];
    char nama[50];
    char jenis[30];
    double harga;
} Book;

extern Book books[MAX_BOOK];
extern int book_count;

void insert_book();
void view_books();
void delete_book();

#endif
