

#include <stdio.h>

void insert_book() {
    printf("insert book\n");
}

void view_transactions() {
    printf("view transactions\n");
}

void view_books() {
    printf("view books\n");
}

void delete_transaction() {
    printf("delete transaction\n");
}

void delete_book() {
    printf("delete book\n");
}

void exit_menu() {
    printf("exit menu\n");
}

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
                exit_menu();
                break;
            case 7:
                insert_transaction();
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