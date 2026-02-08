#ifndef TRANSACTION_H
#define TRANSACTION_H

#define MAX_HISTORY 100

typedef struct {
    char kode_buku[10];
    int jumlah;
    double total;
} History;

extern History histories[MAX_HISTORY];
extern int history_count;

void view_transactions();
void insert_transaction();
void delete_transaction();

#endif
