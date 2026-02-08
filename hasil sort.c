#include <stdio.h>
#include <string.h>

void tampilkan_buku() {
    printf("\nHasil Sorting:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s | %s | Rp %.2f\n",
               i + 1,
               books[i].kode,
               books[i].nama,
               books[i].harga);
    }
}
void menu_sort_buku() {
    int pilihan;

    do {
        printf("\n=== MENU SORT BUKU ===\n");
        printf("1. Urutkan berdasarkan nama buku (Ascending - Bubble Sort)\n");
        printf("2. Urutkan berdasarkan harga buku (Descending - Selection Sort)\n");
        printf("0. Kembali ke menu utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                sort_nama_ascending();
                break;

            case 2:
                sort_harga_descending();
                break;

            case 0:
                printf("Kembali ke menu utama...\n");
                break;

            default:
                printf("Menu tidak valid!\n");
        }

    } while (pilihan != 0);
}

/MAIN PROGRAM

int main() {
    int menu;

    do {
        printf("\n=== MENU UTAMA ===\n");
        printf("8. Sort Buku\n");
        printf("0. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 8:
                menu_sort_buku();
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Menu tidak valid.\n");
        }

    } while (menu != 0);

    return 0;
}
