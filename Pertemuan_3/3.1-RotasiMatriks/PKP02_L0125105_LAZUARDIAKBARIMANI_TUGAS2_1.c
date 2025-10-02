/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/

#include <stdio.h>

int main() {
    int baris, kolom;
    scanf("%d %d", &baris, &kolom);

    int matriks[baris][kolom];
    for (int index_baris = 0; index_baris < baris; index_baris++) {
        for (int index_kolom = 0; index_kolom < kolom; index_kolom++) {
            scanf("%d", &matriks[index_baris][index_kolom]);
        }
    }

    for (int index_kolom = 0; index_kolom < kolom; index_kolom++) {
        for (int index_baris = baris - 1; index_baris >= 0; index_baris--) {
            printf("%d", matriks[index_baris][index_kolom]);
            if (index_baris != 0) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}