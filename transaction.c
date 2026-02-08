#include <stdio.h>
#include <string.h>
#include "transaction.h"
#include "book.h"

History histories[MAX_HISTORY];
int history_count = 0;

void view_transactions() {
    if (history_count == 0) {
        printf("History transaksi kosong.\n");
        return;
    }

    for (int i = 0; i < history_count; i++) {
        printf("%d. %s | %d | %.2lf\n",
               i + 1,
               histories[i].kode_buku,
               histories[i].jumlah,
               histories[i].total);
    }
}
void insert_transaction() {
    char kode[10];
    int jumlah;
    int found = -1;

    if (book_count == 0) {
        printf("Belum ada data buku.\n");
        return;
    }

    view_books();

    printf("Masukkan kode buku: ");
    scanf("%s", kode);

    printf("Masukkan jumlah terjual: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].kode, kode) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Kode buku tidak ditemukan.\n");
        return;
    }

    History h;
    strcpy(h.kode_buku, kode);
    h.jumlah = jumlah;
    h.total = jumlah * books[found].harga;

    histories[history_count++] = h;

    printf("Transaksi berhasil dicatat.\n");
}
void delete_transaction() {
    int index;

    if (history_count == 0) {
        printf("Tidak ada history untuk dihapus.\n");
        return;
    }

    view_transactions();

    printf("Pilih index history yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > history_count) {
        printf("Index tidak valid.\n");
        return;
    }

    for (int i = index - 1; i < history_count - 1; i++) {
        histories[i] = histories[i + 1];
    }

    history_count--;

    printf("Data Successfully delete..\n");
}
