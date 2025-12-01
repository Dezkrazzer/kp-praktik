/*
Deskripsi:
Program mengambil input sebuah bilangan bulat positif n. Dengan menggunakan konsep fungsi rekursi, program harus mencetak
deret angka dari n sampai 1 secara menurun.

Format Masukan:
Sebuah bilangan bulat positif n.

Format Keluaran:
Deret angka dari n sampai 1 secara menurun, dipisahkan oleh spasi.

Contoh Masukan 1:
7

Contoh Keluaran 1:
7 6 5 4 3 2 1

NOTE PENTING:
- Wajib menggunakan fungsi rekursi.
- Dilarang menggunakan perulangan (for, while, do-while).
*/

#include <stdio.h>

// Fungsi rekursi untuk mencetak deret menurun
void cetakDeretMenurun(int n)
{
    // Base case: jika n = 0, hentikan rekursi
    if (n == 0)
    {
        return;
    }
    
    // Cetak angka saat ini
    printf("%d", n);
    
    // Cetak spasi jika bukan angka terakhir (1)
    if (n > 1)
    {
        printf(" ");
    }
    
    // Rekursi dengan n-1
    cetakDeretMenurun(n - 1);
}

int main()
{
    int n;
    
    // Input bilangan bulat positif
    scanf("%d", &n);
    
    // Panggil fungsi rekursi
    cetakDeretMenurun(n);
    
    printf("\n");
    
    return 0;
}