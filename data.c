#include <stdio.h>
#include "data.h"
#include "book.h"
#include "transaction.h"

void load_data() {
    FILE *fp = fopen("databuku.txt", "r");
    if (!fp) return;

    book_count = 0;
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%lf\n",
                  books[book_count].kode,
                  books[book_count].nama,
                  books[book_count].jenis,
                  &books[book_count].harga) == 4) {
        book_count++;
                  }

    fclose(fp);
}

void save_data() {
    FILE *fp = fopen("databuku.txt", "w");
    if (!fp) return;

    for (int i = 0; i < book_count; i++) {
        fprintf(fp, "%s|%s|%s|%.2lf\n",
                books[i].kode,
                books[i].nama,
                books[i].jenis,
                books[i].harga);
    }

    fclose(fp);
}

void load_history() {
    FILE *fp = fopen("history.txt", "r");
    if (!fp) return;

    history_count = 0;
    while (fscanf(fp, "%s %d %lf",
                  histories[history_count].kode_buku,
                  &histories[history_count].jumlah,
                  &histories[history_count].total) != EOF) {
        history_count++;
                  }

    fclose(fp);
}

void save_history() {
    FILE *fp = fopen("history.txt", "w");
    if (!fp) return;

    for (int i = 0; i < history_count; i++) {
        fprintf(fp, "%s %d %.2lf\n",
                histories[i].kode_buku,
                histories[i].jumlah,
                histories[i].total);
    }

    fclose(fp);
}
