// Program untuk mencari faktor bilangan

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    SOAL: 2.3-FaktorBilangan

    Deskripsi:
    Faktor-faktor suatu bilangan bulat N adalah bilangan-bilangan bulat positif yang habis membagi N. Misalnya
    faktor dari 24 adalah 24, 12, 8, 6, 4, 3, 2, dan 1. Om Robby memberikan anda sebuah bilangan bulat N. Tentukan faktor-faktor dari N.

    Format Input:
    Sebuah baris berisi sebuah bilangan bulat N

    Format Output:
    Faktor-faktor dari N, masing-masing dalam sebuah baris, terurut dari yang terbesar ke yang terkecil

    Contoh Input 1:
    24

    Contoh Output 1:
    24
    12
    8
    6
    4
    3
    2
    1

    Contoh Input 2:
    9

    Contoh Output 2:
    9
    3
    1
*/
#include <stdio.h>

int main() {
    int bilangan;
    scanf("%d", &bilangan);

    for (int faktor = bilangan; faktor >= 1; faktor--) {
        if (bilangan % faktor == 0) {
            printf("%d\n", faktor);
        }
    }

    return 0;
}