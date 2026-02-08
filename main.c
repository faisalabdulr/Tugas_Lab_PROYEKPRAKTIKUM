#include <stdio.h>
#include "book.h"
#include "transaction.h"
#include "sort_buku.h"
#include "data.h"

int main() {
    int input_menu;

    // Load data dari file saat program mulai
    load_data();
    load_history();

    do {
        printf("\nPilih Menu:\n");
        printf("1. Input Data Buku Baru\n");
        printf("2. View History Transaksi Penjualan\n");
        printf("3. View Buku\n");
        printf("4. Delete History\n");
        printf("5. Delete Buku\n");
        printf("6. Exit\n");
        printf("7. Input Transaksi\n");
        printf("8. Sort Buku\n");
        printf("Pilih: ");

        // VALIDASI INPUT MENU
        if (scanf("%d", &input_menu) != 1) {
            while (getchar() != '\n'); // buang input invalid
            printf("Input harus berupa angka!\n");
            continue;
        }

        switch (input_menu) {
            case 1:
                insert_book();
                break;

            case 2:
                view_transactions();
                break;

            case 3:
                view_books();
                break;

            case 4:
                delete_transaction();
                break;

            case 5:
                delete_book();
                break;

            case 6:
                save_history();
                save_data();
                printf("Data disimpan. Keluar program.\n");
                break;

            case 7:
                insert_transaction();
                break;

            case 8:
                sort_menu();
                break;

            default:
                printf("Menu tidak valid!\n");
        }

    } while (input_menu != 6);

    return 0;
}
