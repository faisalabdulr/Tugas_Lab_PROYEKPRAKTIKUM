#include <stdio.h>
#include data.h

void view_transactions()
{
    FILE *history;
    char line[256];
    char kodeBuku[20];
    int jumlah;
    float total;

    history = fopen("history.txt", "r");
    if (history == NULL)
    {
        printf("Belum ada data histori transaksi.\n");
        return;
    }

    printf("\nHISTORI TRANSAKSI PENJUALAN\n");
    printf("%-10s | %-15s | %-12s\n", "Kode Buku", "Jumlah Terjual", "Total Harga");
    printf("---------------------------------------------\n");

    while (fgets(line, sizeof(line), history))
    {
        sscanf(line, "%[^|]|%d|%f", kodeBuku, &jumlah, &total);
        printf("%-10s | %-15d | %.2f\n", kodeBuku, jumlah, total);
    }

    fclose(history);
}