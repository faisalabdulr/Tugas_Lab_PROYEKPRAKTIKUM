#include <stdio.h>

#include "data.h"

#define MAX_HISTORY 100

// data dummy history (sementara)
int history_count = 3;
char history_code[MAX_HISTORY][10] = {"BK001", "BK002", "BK003"};
int history_qty[MAX_HISTORY] = {2, 1, 5};
float history_total[MAX_HISTORY] = {50000, 30000, 125000};

void delete_transaction() {
    int i, index;

    if (history_count == 0) {
        printf("History transaksi kosong.\n");
        return;
    }

    printf("\nDaftar History Transaksi:\n");
    for (i = 0; i < history_count; i++) {
        printf("%d. Kode Buku: %s | Jumlah: %d | Total: %.2f\n",
               i + 1,
               history_code[i],
               history_qty[i],
               history_total[i]);
    }

    printf("\nMasukkan index yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > history_count) {
        printf("Index tidak valid.\n");
        return;
    }

    for (i = index - 1; i < history_count - 1; i++) {
        history_qty[i] = history_qty[i + 1];
        history_total[i] = history_total[i + 1];
        sprintf(history_code[i], "%s", history_code[i + 1]);
    }

    history_count--;

    printf("Data Successfully delete..\n");
}