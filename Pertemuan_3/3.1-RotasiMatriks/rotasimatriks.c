// Program untuk merotasi matriks

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    Soal: 3.1-RotasiMatriks

    Deskripsi:
    Program mengambil input n dan m yang merupakan representasi baris dan kolom dengan menggunakan konsep array 2 dimensi. Program akan
    mengambil input sebanyak n baris dan m angka. Tugas anda adalah merotasi array tersebut 270 derajat berlawanan arah jarum jam.

    Format Input:
    Sebuah baris n dan m n baris dengan masing-masing baris terdapat m angka

    Format Output:
    Matriks n x m yang diputar 270 derajat berlawanan arah jarum jam

    Contoh Input 1:
    3 3
    1 2 3
    4 5 6
    7 8 9

    Contoh Output 1:
    7 4 1
    8 5 2
    9 6 3

    Contoh Input 2:
    2 3
    1 2 3
    4 5 6

    Contoh Output 2:
    4 1
    5 2
    6 3
*/

#include <stdio.h>

int main() {
    int baris, kolom; // Deklarasi variabel untuk menyimpan jumlah baris dan kolom
    scanf("%d %d", &baris, &kolom); // Membaca input jumlah baris dan kolom

    int matriks[baris][kolom]; // Deklarasi array 2D untuk menyimpan matriks
    // Ini merupakan loop untuk mengisi matriks dengan input dari pengguna
    for (int index_baris = 0; index_baris < baris; index_baris++) { // Jika index_baris kurang dari jumlah baris
        for (int index_kolom = 0; index_kolom < kolom; index_kolom++) { // Jika index_kolom kurang dari jumlah kolom
            scanf("%d", &matriks[index_baris][index_kolom]); // Maka baca input dan simpan di matriks pada posisi [index_baris][index_kolom]
        }
    }

    // Ini merupakan loop untuk mencetak matriks yang telah diputar 270 derajat berlawanan arah jarum jam
    for (int index_kolom = 0; index_kolom < kolom; index_kolom++) { // Jika index_kolom kurang dari jumlah kolom
        for (int index_baris = baris - 1; index_baris >= 0; index_baris--) { // Jika index_baris lebih besar atau sama dengan 0
            printf("%d", matriks[index_baris][index_kolom]); // Maka cetak elemen matriks pada posisi [index_baris][index_kolom]
            if (index_baris != 0) { // Jika index_baris tidak sama dengan 0
                printf(" "); // Maka cetak spasi
            }
        }
        printf("\n"); // Pindah ke baris baru setelah mencetak satu kolom
    }

    return 0;
}

/*
    Alur Program:
    1. Program dimulai dengan mendeklarasikan variabel untuk menyimpan jumlah baris dan kolom.
    2. Program membaca input jumlah baris dan kolom dari pengguna.
    3. Program mendeklarasikan array 2D untuk menyimpan matriks.
    4. Program mengisi matriks dengan input dari pengguna menggunakan nested loop.
    5. Program mencetak matriks yang telah diputar 270 derajat berlawanan arah jarum jam.
    6. Program selesai.
*/