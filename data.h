#ifndef DATA_H
#define DATA_H

#define MAX_BUKU 100
#define MAX_HISTORY 100

typedef struct {
    char kode[10];
    char nama[50];
    char jenis[30];
    double harga;
} Buku;

typedef struct {
    char kode[10];
    int jumlah;
    double total;
} History;

extern Buku daftarBuku[MAX_BUKU];
extern int jumlahBuku;

extern History daftarHistory[MAX_HISTORY];
extern int jumlahHistory;

#endif
