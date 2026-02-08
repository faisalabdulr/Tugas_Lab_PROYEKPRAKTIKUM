#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

char* generate_code() {
    int max = 0;

    for (int i = 0; i < jumlahBuku; i++) {
        if (strncmp(daftarBuku[i].kode, "BK", 2) == 0) {
            int angka = atoi(daftarBuku[i].kode + 2);
            if (angka > max)
                max = angka;
        }
    }

    char *new_id = malloc(10);
    sprintf(new_id, "BK%03d", max + 1);
    return new_id;
}

void insert_book() {
    Buku b;

    char *generated_id = generate_code();
    if (generated_id == NULL) {
        printf("Gagal generate ID\n");
        return;
    }

    strcpy(b.kode, generated_id);
    free(generated_id);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Masukkan nama buku: ");
    fgets(b.nama, sizeof(b.nama), stdin);
    b.nama[strcspn(b.nama, "\n")] = '\0';

    printf("Masukkan jenis buku: ");
    fgets(b.jenis, sizeof(b.jenis), stdin);
    b.jenis[strcspn(b.jenis, "\n")] = '\0';

    printf("Masukkan harga buku: ");
    scanf("%lf", &b.harga);

    daftarBuku[jumlahBuku++] = b;

    printf("Buku berhasil ditambahkan dengan ID %s (belum disimpan)\n", b.kode);
}
