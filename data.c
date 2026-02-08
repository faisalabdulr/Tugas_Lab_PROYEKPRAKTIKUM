#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

History daftarHistory[MAX_HISTORY];
int jumlahHistory = 0;

void loadBuku() {
    jumlahBuku = 0;
    FILE *fp = fopen("databuku.txt", "r");
    if(fp != NULL) {
        char line[200];
        while(fgets(line, sizeof(line), fp)) {
            line[strcspn(line, "\n")] = 0; // hapus newline
            char *token = strtok(line, "|");
            if(token) strcpy(daftarBuku[jumlahBuku].kode, token);

            token = strtok(NULL, "|");
            if(token) strcpy(daftarBuku[jumlahBuku].nama, token);

            token = strtok(NULL, "|");
            if(token) strcpy(daftarBuku[jumlahBuku].jenis, token);

            token = strtok(NULL, "|");
            if(token) daftarBuku[jumlahBuku].harga = atof(token);

            jumlahBuku++;
        }
        fclose(fp);
    }
}

void loadHistory() {
    FILE *fp = fopen("history.txt", "r");
    if(fp != NULL) {
        char line[200];
        while(fgets(line, sizeof(line), fp)) {
            line[strcspn(line, "\n")] = 0;
            char *token = strtok(line, "|");
            if(token) strcpy(daftarHistory[jumlahHistory].kode, token);

            token = strtok(NULL, "|");
            if(token) daftarHistory[jumlahHistory].jumlah = atoi(token);

            token = strtok(NULL, "|");
            if(token) daftarHistory[jumlahHistory].total = atof(token);

            jumlahHistory++;
        }
        fclose(fp);
    }
}
