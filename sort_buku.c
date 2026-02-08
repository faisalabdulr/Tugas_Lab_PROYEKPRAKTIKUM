#include <stdio.h>
#include "sort_buku.h"

void sort_menu() {
    int input_sort;

    do {
        printf("Pilih sort:\n");
        printf("1. Nama buku (ascending)\n");
        printf("2. Harga buku (descending)\n");
        scanf("%d", &input_sort);

        if (input_sort == 1) {
            printf("sort books by name\n");
        } else if (input_sort == 2) {
            printf("sort books by price\n");
        } else {
            printf("Sort tidak valid.\n");
        }
    } while (input_sort != 1 && input_sort != 2);
}
