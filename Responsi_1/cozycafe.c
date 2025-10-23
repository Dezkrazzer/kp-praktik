#include <stdio.h>

/*
    Nama    : Lazuardi Akbar Imani
    NIM     : L0125105
    Kelas   : Informatika 2025D
*/

// Deklarasi array menu sebagai variabel global
char makanan[10][30] = {
    "Ayam_Goreng",
    "Ayam_Bakar",
    "Mie_Goreng",
    "Mie_Rebus",
    "Nasi_Bakar",
    "Nasi_Goreng",
    "Nasi_Katsu",
    "Ricebowl",
    "Steak_Ayam",
    "Steak_Wagyu"};

int hargaMakanan[10] = {
    20000, // Ayam_Goreng
    25000, // Ayam_Bakar
    12000, // Mie_Goreng
    15000, // Mie_Rebus
    10000, // Nasi_Bakar
    18000, // Nasi_Goreng
    22000, // Nasi_Katsu
    25000, // Ricebowl
    30000, // Steak_Ayam
    80000  // Steak_Wagyu
};

char minuman[10][30] = {
    "Es_Teh",
    "Es_Jeruk",
    "Espresso",
    "Macchiato",
    "Mochachino",
    "Cappucino",
    "Caffe_Latte",
    "Hazelnut_Latte",
    "Caramel_Macchiato",
    "Matcha_Latte"};

int hargaMinuman[10] = {
    5000,  // Es_Teh
    7000,  // Es_Jeruk
    15000, // Espresso
    25000, // Macchiato
    25000, // Mochachino
    20000, // Cappucino
    22000, // Caffe_Latte
    25000, // Hazelnut_Latte
    27000, // Caramel_Macchiato
    28000  // Matcha_Latte
};

char dessert[10][30] = {
    "Puding_Coklat",
    "Cheesecake",
    "Pancake",
    "Mix_Plater",
    "French_Fries",
    "Waffle",
    "Brownies",
    "Ice_Cream",
    "Cireng",
    "Roti_Bakar"};

int hargaDessert[10] = {
    15000, // Puding_Coklat
    30000, // Cheesecake
    25000, // Pancake
    30000, // Mix_Plater
    20000, // French_Fries
    25000, // Waffle
    15000, // Brownies
    18000, // Ice_Cream
    30000, // Cireng
    22000  // Roti_Bakar
};

// Deklarasi fungsi
void tampilkanNamaAplikasi();
void tampilkanMenu(char menu[][30], int harga[], int jumlah);
void tampilkanStruk(char nama[], int meja, char pesanan[][30], int hargaPesanan[], int jumlahPesanan);
void tampilkanMenuCategory(int jumlahPesanan);
void tampilkanCredit();

int hitungTotal(int hargaPesanan[], int jumlahPesanan);

int caseMenuMakanan(char pesanan[][30], int hargaPesanan[], int jumlahPesanan);
int caseMenuMinuman(char pesanan[][30], int hargaPesanan[], int jumlahPesanan);
int caseMenuDessert(char pesanan[][30], int hargaPesanan[], int jumlahPesanan);
int caseSelesaiPesan();

int main()
{
    char nama[50];
    int meja;

    // Data pesanan
    char pesanan[50][30];
    int hargaPesanan[50];
    int jumlahPesanan = 0;

    int pilihanKategori, pilihanMenu;
    int selesai = 0;
    char konfirmasi;

    tampilkanNamaAplikasi();

    printf("Masukkan Nama Anda : ");
    scanf("%s", nama);

    printf("Masukkan Nomor Meja: ");
    while (scanf("%d", &meja) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Nomor meja harus berupa angka!\n");
        while (getchar() != '\n');
        printf("Masukkan Nomor Meja: ");
    }
    while (getchar() != '\n');

    while (selesai == 0)
    {

        tampilkanMenuCategory(jumlahPesanan);

        if (scanf("%d", &pilihanKategori) != 1)
        {
            printf("[ERROR] Input tidak sesuai! Input harus berupa angka!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        // Jika user memilih opsi 4 tapi belum ada pesanan
        if (pilihanKategori == 4 && jumlahPesanan == 0)
        {
            printf("Hey! Kamu belum memesan apapun! Silakan pilih menu terlebih dahulu.\n");
            continue;
        }

        switch (pilihanKategori)
        {
        case 1:
            jumlahPesanan = caseMenuMakanan(pesanan, hargaPesanan, jumlahPesanan);
            break;

        case 2:
            jumlahPesanan = caseMenuMinuman(pesanan, hargaPesanan, jumlahPesanan);
            break;

        case 3:
            jumlahPesanan = caseMenuDessert(pesanan, hargaPesanan, jumlahPesanan);
            break;

        case 4:
            selesai = caseSelesaiPesan();
            break;

        default:
            printf("[ERROR] Kategori tidak valid!\n");
        }
    }

    tampilkanStruk(nama, meja, pesanan, hargaPesanan, jumlahPesanan);

    return 0;
}

// Fungsi menampilkan nama aplikasi
void tampilkanNamaAplikasi()
{
    printf("=====================================\n");
    printf("|      Selamat Datang di CozyCafe   |\n");
    printf("=====================================\n\n");
}

// Fungsi menampilkan menu kategori
void tampilkanMenu(char menu[][30], int harga[], int jumlah)
{
    int i;
    for (i = 0; i < jumlah; i++)
    {
        printf("%2d. %-25s Rp %d\n", i + 1, menu[i], harga[i]);
    }
}

// Fungsi menghitung total pembayaran
int hitungTotal(int hargaPesanan[], int jumlahPesanan)
{
    int total = 0;
    int i;
    for (i = 0; i < jumlahPesanan; i++)
    {
        total += hargaPesanan[i];
    }
    return total;
}

// Fungsi cetak struk
void tampilkanStruk(char nama[], int meja, char pesanan[][30], int hargaPesanan[], int jumlahPesanan)
{
    int i;
    printf("\n=====================================\n");
    printf("            STRUK PEMBAYARAN         \n");
    printf("=====================================\n");
    printf("Nama Pelanggan : %s\n", nama);
    printf("Nomor Meja     : %d\n", meja);
    printf("-------------------------------------\n");
    printf("Pesanan Anda:\n");
    for (i = 0; i < jumlahPesanan; i++)
    {
        printf("%-2d. %-20s Rp %d\n", i + 1, pesanan[i], hargaPesanan[i]);
    }
    printf("-------------------------------------\n");
    int total = hitungTotal(hargaPesanan, jumlahPesanan);
    printf("Total Pembayaran: Rp %d\n", total);
    printf("=====================================\n");
    printf("Terima kasih telah berkunjung!\n");
    printf("=====================================\n");

    tampilkanCredit();
}

// Fungsi menampilkan menu kategori
void tampilkanMenuCategory(int jumlahPesanan)
{
    printf("\n=======================================\n");
    printf("|        Menu Kategori CozyCafe       |\n");
    printf("=======================================\n");
    printf("| 1 | Makanan                         |\n");
    printf("| 2 | Minuman                         |\n");
    printf("| 3 | Dessert                         |\n");
    if (jumlahPesanan > 0)
    {
        printf("| 4 | Selesai Pesan                   |\n");
    }
    printf("=======================================\n");
    printf("Pilih kategori: ");
}

// Fungsi caseMenuMakanan
int caseMenuMakanan(char pesanan[][30], int hargaPesanan[], int jumlahPesanan)
{
    int pilihanMenu;
    
    printf("\n--- Daftar Makanan ---\n");
    tampilkanMenu(makanan, hargaMakanan, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return jumlahPesanan;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        int i;
        for (i = 0; makanan[pilihanMenu - 1][i] != '\0'; i++)
        {
            pesanan[jumlahPesanan][i] = makanan[pilihanMenu - 1][i];
        }
        pesanan[jumlahPesanan][i] = '\0';
        hargaPesanan[jumlahPesanan] = hargaMakanan[pilihanMenu - 1];
        jumlahPesanan++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", makanan[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }

    return jumlahPesanan;
}

// Fungsi caseMenuMinuman
int caseMenuMinuman(char pesanan[][30], int hargaPesanan[], int jumlahPesanan)
{
    int pilihanMenu;

    printf("\n--- Daftar Minuman ---\n");
    tampilkanMenu(minuman, hargaMinuman, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return jumlahPesanan;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        int i;
        for (i = 0; minuman[pilihanMenu - 1][i] != '\0'; i++)
        {
            pesanan[jumlahPesanan][i] = minuman[pilihanMenu - 1][i];
        }
        pesanan[jumlahPesanan][i] = '\0';
        hargaPesanan[jumlahPesanan] = hargaMinuman[pilihanMenu - 1];
        jumlahPesanan++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", minuman[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }
    
    return jumlahPesanan;
}

// Fungsi caseMenuDessert
int caseMenuDessert(char pesanan[][30], int hargaPesanan[], int jumlahPesanan)
{
    int pilihanMenu;

    printf("\n--- Daftar Dessert ---\n");
    tampilkanMenu(dessert, hargaDessert, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return jumlahPesanan;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        int i;
        for (i = 0; dessert[pilihanMenu - 1][i] != '\0'; i++)
        {
            pesanan[jumlahPesanan][i] = dessert[pilihanMenu - 1][i];
        }
        pesanan[jumlahPesanan][i] = '\0';
        hargaPesanan[jumlahPesanan] = hargaDessert[pilihanMenu - 1];
        jumlahPesanan++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", dessert[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }
    
    return jumlahPesanan;
}

// Fungsi caseSelesaiPesan
int caseSelesaiPesan()
{
    char konfirmasi;
    
    printf("\nApakah anda yakin ingin menyelesaikan pesanan? (y/n): ");
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        return 1; // Return 1 jika selesai
    }
    else if (konfirmasi == 'n' || konfirmasi == 'N')
    {
        printf("Baik, silakan lanjut memesan.\n");
        return 0; // Return 0 jika belum selesai
    }
    else
    {
        printf("[ERROR] Input tidak valid!\n");
        return 0; // Return 0 jika input tidak valid
    }
}

// Fungsi menampilkan credit aplikasi
void tampilkanCredit()
{
    printf("\n=====================================\n");
    printf("|              CozyCafe             |\n");
    printf("|        Lazuardi Akbar Imani       |\n");
    printf("|              L0125105             |\n");
    printf("=====================================\n");
}