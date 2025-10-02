// Program pemeriksa kandang

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    Soal: 3.2-Kandang

    Deskripsi:
    Pak Dengklek membuka sebuah toko kandang bebek. Ia menjual 5 kandang bebek dengan ukuran-ukuran sebagai berikut:
    A. 225 × 335 cm persegi
    B. 215 × 394 cm persegi
    C. 198 × 400 cm persegi
    D. 314 × 298 cm persegi
    E. 299 × 278 cm persegi
    F. 240 × 330 cm persegi
    Seorang pembeli hanya ingin membeli kandang yang berukuran setidaknya 80.000 cm². Pertanyaan: Ada berapa kandang yang memenuhi syarat tersebut?

    Contoh Ouput:
    Jumlah kandang bebek yang memenuhi syarat adalah sebanyak n kandang

    Petunjuk:
    Simpan data panjang dan lebar aquarium dalam array. Gunakan perulangan untuk memeriksa semua data
*/
#include <stdio.h>

int main() {
    int panjang[] = {225, 215, 198, 314, 299, 240}; // Deklarasi array untuk menyimpan panjang kandang
    int lebar[] = {335, 394, 400, 298, 278, 330}; // Deklarasi array untuk menyimpan lebar kandang
    int jumlah_kandang = 0; // Variabel untuk menyimpan jumlah kandang yang memenuhi syarat

    // Loop untuk memeriksa setiap kandang
    for (int i = 0; i < 6; i++) { // Jika i kurang dari 6 (jumlah kandang)
        int luas = panjang[i] * lebar[i]; // Hitung luas kandang
        // Periksa apakah luas kandang memenuhi syarat
        if (luas >= 80000) { // Jika luas kandang lebih besar atau sama dengan 80000
            jumlah_kandang++; // Maka tambahkan 1 ke jumlah_kandang
        }
    }

    printf("Jumlah kandang bebek yang memenuhi syarat adalah sebanyak %d kandang\n", jumlah_kandang); // Cetak hasil jumlah kandang yang memenuhi syarat
    return 0;
}

/*
    Alur program:
    1. Deklarasi array untuk menyimpan panjang dan lebar kandang
    2. Inisialisasi variabel jumlah_kandang untuk menyimpan jumlah kandang
    3. Loop untuk memeriksa setiap kandang
        a. Hitung luas kandang
        b. Periksa apakah luas kandang memenuhi syarat
        c. Jika memenuhi syarat, tambahkan 1 ke jumlah_kandang
    4. Cetak hasil jumlah kandang yang memenuhi syarat
    5. Akhiri program
*/