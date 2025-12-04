#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Nama    : Lazuardi Akbar Imani
    NIM     : L0125105
    Kelas   : Informatika 2025D
*/

// Definisi Struct untuk Menu
struct MenuItem {
    char nama[30];
    int harga;
};

// Definisi Struct untuk Pesanan
struct Pesanan {
    char namaPelanggan[50];
    int nomorMeja;
    char itemPesanan[50][30];
    int hargaItem[50];
    int jumlahItem;
};

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
void tampilkanStruk(struct Pesanan *pesanan);
void tampilkanMenuCategory(int jumlahPesanan);
void tampilkanCredit();

// Fungsi rekursi untuk menghitung total
int hitungTotalRekursi(int hargaPesanan[], int index, int jumlahPesanan);
int hitungTotal(int hargaPesanan[], int jumlahPesanan);

// Fungsi rekursi untuk menampilkan pesanan
void tampilkanPesananRekursi(char pesanan[][30], int hargaPesanan[], int index, int jumlahPesanan);

int caseMenuMakanan(struct Pesanan *pesanan);
int caseMenuMinuman(struct Pesanan *pesanan);
int caseMenuDessert(struct Pesanan *pesanan);
int caseSelesaiPesan();

int main() {
    struct Pesanan *pesanan = (struct Pesanan *)malloc(sizeof(struct Pesanan));
    
    // Cek apakah alokasi memori berhasil
    if (pesanan == NULL) {
        printf("[ERROR] Gagal mengalokasikan memori!\n");
        return 1;
    }
    
    pesanan->jumlahItem = 0;

    int pilihanKategori;
    int selesai = 0;

    tampilkanNamaAplikasi();

    printf("Masukkan Nama Anda : ");
    scanf("%s", pesanan->namaPelanggan);

    printf("Masukkan Nomor Meja: ");
    while (scanf("%d", &pesanan->nomorMeja) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Nomor meja harus berupa angka!\n");
        while (getchar() != '\n');
        printf("Masukkan Nomor Meja: ");
    }
    while (getchar() != '\n');

    while (selesai == 0)
    {
        tampilkanMenuCategory(pesanan->jumlahItem);

        if (scanf("%d", &pilihanKategori) != 1)
        {
            printf("[ERROR] Input tidak sesuai! Input harus berupa angka!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        // Jika user memilih opsi 4 tapi belum ada pesanan
        if (pilihanKategori == 4 && pesanan->jumlahItem == 0)
        {
            printf("Hey! Kamu belum memesan apapun! Silakan pilih menu terlebih dahulu.\n");
            continue;
        }

        switch (pilihanKategori)
        {
        case 1:
            caseMenuMakanan(pesanan);  // Passing pointer ke struct
            break;

        case 2:
            caseMenuMinuman(pesanan);  // Passing pointer ke struct
            break;

        case 3:
            caseMenuDessert(pesanan);  // Passing pointer ke struct
            break;

        case 4:
            selesai = caseSelesaiPesan();
            break;

        default:
            printf("[ERROR] Kategori tidak valid!\n");
        }
    }

    tampilkanStruk(pesanan);  // Passing pointer ke struct
    
    free(pesanan);
    printf("\n[INFO] Memori berhasil dibersihkan.\n");

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

// Fungsi rekursi untuk menghitung total pembayaran
int hitungTotalRekursi(int hargaPesanan[], int index, int jumlahPesanan)
{
    if (index >= jumlahPesanan)
    {
        return 0;
    }
    
    return hargaPesanan[index] + hitungTotalRekursi(hargaPesanan, index + 1, jumlahPesanan);
}

// Fungsi wrapper untuk menghitung total
int hitungTotal(int hargaPesanan[], int jumlahPesanan)
{
    return hitungTotalRekursi(hargaPesanan, 0, jumlahPesanan);
}

// Fungsi rekursi untuk menampilkan pesanan
void tampilkanPesananRekursi(char pesanan[][30], int hargaPesanan[], int index, int jumlahPesanan)
{
    if (index >= jumlahPesanan)
    {
        return;
    }
    
    printf("%-2d. %-20s Rp %d\n", index + 1, pesanan[index], hargaPesanan[index]);
    
    tampilkanPesananRekursi(pesanan, hargaPesanan, index + 1, jumlahPesanan);
}

// Fungsi cetak struk menggunakan pointer ke struct
void tampilkanStruk(struct Pesanan *p)
{
    printf("\n=====================================\n");
    printf("            STRUK PEMBAYARAN         \n");
    printf("=====================================\n");
    printf("Nama Pelanggan : %s\n", p->namaPelanggan);
    printf("Nomor Meja     : %d\n", p->nomorMeja);
    printf("-------------------------------------\n");
    printf("Pesanan Anda:\n");
    
    tampilkanPesananRekursi(p->itemPesanan, p->hargaItem, 0, p->jumlahItem);
    
    printf("-------------------------------------\n");
    int total = hitungTotal(p->hargaItem, p->jumlahItem);
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

// Fungsi caseMenuMakanan menggunakan pointer ke struct
int caseMenuMakanan(struct Pesanan *p)
{
    int pilihanMenu;
    
    printf("\n--- Daftar Makanan ---\n");
    tampilkanMenu(makanan, hargaMakanan, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return p->jumlahItem;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        strcpy(p->itemPesanan[p->jumlahItem], makanan[pilihanMenu - 1]);
        p->hargaItem[p->jumlahItem] = hargaMakanan[pilihanMenu - 1];
        p->jumlahItem++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", makanan[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }

    return p->jumlahItem;
}

// Fungsi caseMenuMinuman menggunakan pointer ke struct
int caseMenuMinuman(struct Pesanan *p)
{
    int pilihanMenu;

    printf("\n--- Daftar Minuman ---\n");
    tampilkanMenu(minuman, hargaMinuman, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return p->jumlahItem;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        strcpy(p->itemPesanan[p->jumlahItem], minuman[pilihanMenu - 1]);
        p->hargaItem[p->jumlahItem] = hargaMinuman[pilihanMenu - 1];
        p->jumlahItem++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", minuman[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }
    
    return p->jumlahItem;
}

// Fungsi caseMenuDessert menggunakan pointer ke struct
int caseMenuDessert(struct Pesanan *p)
{
    int pilihanMenu;

    printf("\n--- Daftar Dessert ---\n");
    tampilkanMenu(dessert, hargaDessert, 10);
    printf("Pilih menu (1-10): ");

    if (scanf("%d", &pilihanMenu) != 1)
    {
        printf("[ERROR] Input tidak sesuai! Pilihan menu harus berupa angka!\n");
        while (getchar() != '\n');
        return p->jumlahItem;
    }
    while (getchar() != '\n');

    if (pilihanMenu >= 1 && pilihanMenu <= 10)
    {
        strcpy(p->itemPesanan[p->jumlahItem], dessert[pilihanMenu - 1]);
        p->hargaItem[p->jumlahItem] = hargaDessert[pilihanMenu - 1];
        p->jumlahItem++;
        printf("[SUCCESS] %s berhasil ditambahkan!\n", dessert[pilihanMenu - 1]);
    }
    else
    {
        printf("[ERROR] Pilihan kamu tidak valid!\n");
    }
    
    return p->jumlahItem;
}

// Fungsi caseSelesaiPesan
int caseSelesaiPesan()
{
    char konfirmasi;
    
    printf("\nApakah anda yakin ingin menyelesaikan pesanan? (y/n): ");
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        return 1;
    }
    else if (konfirmasi == 'n' || konfirmasi == 'N')
    {
        printf("Baik, silakan lanjut memesan.\n");
        return 0;
    }
    else
    {
        printf("[ERROR] Input tidak valid!\n");
        return 0;
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