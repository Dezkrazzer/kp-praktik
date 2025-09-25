// Program Fibonacci

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    Soal: 2.2-Fibonacci

    Deskripsi:
    Bilangan fibbonaci merupakan bilangan hasil dari penjumlahan dua suku sebelumnya. Misalkan 6 bilangan fibonacci pertama adalah
    0, 1, 1, 2, 3, 5. Om Robby ingin menampilkan N bilangan fibbonaci pertama. Bantulah Om Robby untuk membuat program tersebut.

    Format Input:
    Sebuah baris berisi sebuah bilangan bulat N

    Format Output:
    Sebuah baris berisi N bilangan fibbonaci pertama

    Contoh Input 1:
    5

    Contoh Output 1:
    0 1 1 2 3

    Contoh Input 2:
    10

    Contoh Output 2:
    0 1 1 2 3 5 8 13 21 34
*/
#include <stdio.h>

int main() {
    int banyak_fibonacci;
    scanf("%d", &banyak_fibonacci);

    int fibonacci_0 = 0, fibonacci_1 = 1, bilangan_fibonacci_selanjutnya;

    for (int i = 0; i < banyak_fibonacci; i++) {
        if (i == 0) {
            printf("%d", fibonacci_0);
        } else if (i == 1) {
            printf(" %d", fibonacci_1);
        } else {
            bilangan_fibonacci_selanjutnya = fibonacci_0 + fibonacci_1;
            printf(" %d", bilangan_fibonacci_selanjutnya);
            fibonacci_0 = fibonacci_1;
            fibonacci_1 = bilangan_fibonacci_selanjutnya;
        }
    }
    printf("\n");
    return 0;
}