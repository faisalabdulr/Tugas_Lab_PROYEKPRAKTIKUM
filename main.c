#include <stdio.h>
#include "data.h"

void insert_book() {
    printf("insert book\n");
}

void view_transactions() {
    printf("view transactions\n");
}

void view_books();

void delete_transaction() {
    printf("delete transaction\n");
}

void delete_book() {
    printf("delete book\n");
}

void exit_menu();

void insert_transaction() {
    printf("insert transaction\n");
}
void sort_books(int sort_type) {
    if (sort_type == 1) {
        printf("sort books by name\n");
    } else if (sort_type == 2) {
        printf("sort books by price\n");
    }
}

int main() {
    int input_menu;

    loadBuku();
    loadHistory();

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

        scanf("%d", &input_menu);

        switch (input_menu) {
            case 1:
                insert_book();
                break;
            case 2:
                viewBuku();
                break;
            case 3:
                viewBuku();
                break;
            case 4:
                delete_transaction();
                break;
            case 5:
                delete_book();
                break;
            case 6:
                saveAndExit();
                break;
            case 7:
                ;
                break;
            case 8: {
                int input_sort;

                do {
                    printf("Pilih sort:\n");
                    printf("1. Nama buku (ascending)\n");
                    printf("2. Harga buku (descending)\n");
                    scanf("%d", &input_sort);

                    if (input_sort != 1 && input_sort != 2) {
                        printf("Sort tidak valid.\n");
                    }
                } while (input_sort != 1 && input_sort != 2);

                sort_books(input_sort);
                break;
            }
            default:
                printf("Menu tidak valid\n");
        }
    } while (input_menu != 6);
    return 0;
}