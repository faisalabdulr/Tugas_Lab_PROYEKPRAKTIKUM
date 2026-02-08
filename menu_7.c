#include <stdio.h>
#include <string.h>
#include data.h

void insert_transaction()
{
    char kodeBuku[20];
    int jumlah;
    float harga = 0;
    int ditemukan = 0;

    FILE *db, *history;
    char line[256];
    char fileKode[20], nama[50], jenis[30];
    float fileHarga;

    // input user
    printf("Masukkan Kode Buku : ");
    scanf("%s", kodeBuku);

    printf("Masukkan Jumlah Terjual: ");
    scanf("%d", &jumlah);

    // buka databuku.txt
    db = fopen("databuku.txt", "r");
    if (db == NULL)
    {
        printf("File databuku.txt tidak ditemukan!\n");
        return;
    }

    // cari harga buku
    while (fgets(line, sizeof(line), db))
    {
        sscanf(line, "%[^|]|%[^|]|%[^|]|%f",
               fileKode, nama, jenis, &fileHarga);

        if (strcmp(fileKode, kodeBuku) == 0)
        {
            harga = fileHarga;
            ditemukan = 1;
            break;
        }
    }
    fclose(db);

    if (!ditemukan)
    {
        printf("Kode buku tidak ditemukan!\n");
        return;
    }

    float totalHarga = jumlah * harga;

    // simpan ke history.txt
    history = fopen("history.txt", "a");
    if (history == NULL)
    {
        printf("Gagal membuka history.txt!\n");
        return;
    }

    fprintf(history, "%s|%d|%.2f\n", kodeBuku, jumlah, totalHarga);
    fclose(history);

    printf("Transaksi berhasil dicatat\n");
}