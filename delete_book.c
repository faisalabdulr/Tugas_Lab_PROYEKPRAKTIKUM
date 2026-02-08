#include <stdio.h>
#include "data.h"

void delete_book() {
    viewBuku();

    if (jumlahBuku == 0) {
        printf("Daftar buku kosong.\n");
        return;
    }

    int index;
    printf("\nMasukkan index yang ingin dihapus: ");

    if (scanf("%d", &index) != 1) {
        printf("Input harus berupa angka!\n");

        // Bersihkan buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        return;
    }

    if (index < 1 || index > jumlahBuku) {
        printf("Index tidak valid.\n");
        return;
    }

    for (int i = index - 1; i < jumlahBuku - 1; i++) {
        daftarBuku[i] = daftarBuku[i + 1];
    }

    jumlahBuku--;

    printf("Buku berhasil dihapus (belum disimpan).\n");
}