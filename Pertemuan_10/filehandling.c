/*
Deskripsi:
Diberikan file text.txt. Isi file tersebut berupa beberapa kata (plaintext). Tugasnya adalah menghitung
berapa banyak huruf vokal (a, i, u, e, o, baik huruf besar maupun kecil) yang ada dalam file tersebut.

Format Keluaran:
Sebuah bilangan bulat yang menunjukkan jumlah total huruf vokal dalam file.

Contoh Keluaran:
Jumlah huruf vokal = ...
*/

#include <stdio.h>
#include <ctype.h>

// Fungsi untuk mengecek apakah karakter adalah huruf vokal
int isVokal(char c)
{
    // Ubah ke lowercase untuk memudahkan pengecekan
    c = tolower(c);
    
    // Cek apakah huruf vokal
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    {
        return 1;
    }
    return 0;
}

int main()
{
    FILE *file;
    char karakter;
    int jumlahVokal = 0;
    
    // Buka file text.txt untuk dibaca
    file = fopen("text.txt", "r");
    
    // Cek apakah file berhasil dibuka
    if (file == NULL)
    {
        printf("Error: File text.txt tidak ditemukan!\n");
        return 1;
    }
    
    // Baca file karakter per karakter sampai EOF
    while ((karakter = fgetc(file)) != EOF)
    {
        // Cek apakah karakter adalah vokal
        if (isVokal(karakter))
        {
            jumlahVokal++;
        }
    }
    
    // Tutup file
    fclose(file);
    
    // Tampilkan hasil
    printf("Jumlah huruf vokal = %d\n", jumlahVokal);
    
    return 0;
}