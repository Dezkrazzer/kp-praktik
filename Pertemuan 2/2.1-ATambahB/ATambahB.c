// Program untuk menjumlahkan dua bilangan

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    Soal: 2.1-ATambahB

    Deskripsi:
    Pak Dengklek memiliki A ekor bebek jantan dan B ekor bebek betina. Tentukan banyaknya total bebek yang dimiliki Pak Dengklek.

    Format Input:
    Sebuah baris berisi dua buah bilangan bulat A dan B

    Format Output:
    Sebuah baris berisi sebuah bilangan bulat yang merupakan banyaknya total bebek

    Contoh Input:
    3 103

    Contoh Output:
    106
*/

#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int hasil = A + B;
    printf("%d\n", hasil);
    
    return 0;
}