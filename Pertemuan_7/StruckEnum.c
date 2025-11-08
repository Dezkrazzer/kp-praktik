/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/
#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    int umur;
    float ipk;
};

enum Menu {
    MASUKKAN_DATA = 1,
    TAMPILKAN_DATA = 2,
    EDIT_DATA = 3,
    HAPUS_DATA = 4,
    KELUAR = 5
};

void tampilkanMenu();
void masukkanData(struct Mahasiswa mhs[], int *jumlah);
void tampilkanData(struct Mahasiswa mhs[], int jumlah);
void editData(struct Mahasiswa mhs[], int jumlah);
void hapusData(struct Mahasiswa mhs[], int *jumlah);
void clearBuffer();

int main()
{
    struct Mahasiswa mahasiswa[100];
    int jumlahMahasiswa = 0;
    int pilihan;

    printf("========================================\n");
    printf("|            Data Mahasiswa            |\n");
    printf("========================================\n");

    while (1)
    {
        tampilkanMenu();
        
        printf("Pilih menu: ");
        if (scanf("%d", &pilihan) != 1)
        {
            printf("[ERROR] Input harus berupa angka!\n\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (pilihan)
        {
            case MASUKKAN_DATA:
                masukkanData(mahasiswa, &jumlahMahasiswa);
                break;
            
            case TAMPILKAN_DATA:
                tampilkanData(mahasiswa, jumlahMahasiswa);
                break;
            
            case EDIT_DATA:
                editData(mahasiswa, jumlahMahasiswa);
                break;
            
            case HAPUS_DATA:
                hapusData(mahasiswa, &jumlahMahasiswa);
                break;
            
            case KELUAR:
                printf("\n========================================\n");
                printf("|            Thank you! ^_^            |\n");
                printf("|     L0125105_LAZUARDI AKBAR IMANI    |\n");
                printf("========================================\n");
                return 0;
            
            default:
                printf("[ERROR] Pilihan tidak valid!\n\n");
        }
    }

    return 0;
}

// Fungsi menampilkan menu
void tampilkanMenu()
{
    printf("\n========================================\n");
    printf("              Daftar Menu               \n");
    printf("========================================\n");
    printf("1. Masukkan data\n");
    printf("2. Tampilkan data\n");
    printf("3. Edit data\n");
    printf("4. Hapus data\n");
    printf("5. Keluar\n");
    printf("========================================\n");
}

// Fungsi untuk membersihkan buffer input
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi menambah data mahasiswa
void masukkanData(struct Mahasiswa mhs[], int *jumlah)
{
    if (*jumlah >= 100)
    {
        printf("[ERROR] Data sudah penuh! Maksimal 100 mahasiswa.\n\n");
        return;
    }

    printf("\n--- Input Data Mahasiswa ---\n");
    
    printf("Nama: ");
    fgets(mhs[*jumlah].nama, sizeof(mhs[*jumlah].nama), stdin);
    // Hapus newline dari fgets
    mhs[*jumlah].nama[strcspn(mhs[*jumlah].nama, "\n")] = '\0';
    
    printf("Umur: ");
    while (scanf("%d", &mhs[*jumlah].umur) != 1)
    {
        printf("[ERROR] Umur harus berupa angka!\n");
        clearBuffer();
        printf("Umur: ");
    }
    clearBuffer();
    
    printf("IPK : ");
    while (scanf("%f", &mhs[*jumlah].ipk) != 1)
    {
        printf("[ERROR] IPK harus berupa angka!\n");
        clearBuffer();
        printf("IPK : ");
    }
    clearBuffer();

    (*jumlah)++;
    printf("[SUCCESS] Data berhasil ditambahkan!\n\n");
}

// Fungsi menampilkan semua data mahasiswa dalam bentuk tabel
void tampilkanData(struct Mahasiswa mhs[], int jumlah)
{
    if (jumlah == 0)
    {
        printf("\n[INFO] Belum ada data mahasiswa.\n\n");
        return;
    }

    printf("\n");
    printf("================================================================================\n");
    printf("| No | %-30s | %-4s | %-6s |\n", "Nama", "Umur", "IPK");
    printf("================================================================================\n");
    
    int i;
    for (i = 0; i < jumlah; i++)
    {
        printf("| %-2d | %-30s | %-4d | %-6.2f |\n", 
               i + 1, 
               mhs[i].nama, 
               mhs[i].umur, 
               mhs[i].ipk);
    }
    
    printf("================================================================================\n");
    printf("Total mahasiswa: %d\n\n", jumlah);
}

// Fungsi mengedit data mahasiswa
void editData(struct Mahasiswa mhs[], int jumlah)
{
    if (jumlah == 0)
    {
        printf("\n[INFO] Belum ada data mahasiswa untuk diedit.\n\n");
        return;
    }

    int nomor;
    printf("\n--- Edit Data Mahasiswa ---\n");
    printf("Masukkan nomor mahasiswa yang ingin diedit (1-%d): ", jumlah);
    
    if (scanf("%d", &nomor) != 1)
    {
        printf("[ERROR] Input harus berupa angka!\n\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    if (nomor < 1 || nomor > jumlah)
    {
        printf("[ERROR] Nomor tidak valid!\n\n");
        return;
    }

    int index = nomor - 1;
    
    printf("\nData lama:\n");
    printf("Nama: %s\n", mhs[index].nama);
    printf("Umur: %d\n", mhs[index].umur);
    printf("IPK : %.2f\n\n", mhs[index].ipk);
    
    printf("Masukkan data baru:\n");
    
    printf("Nama: ");
    fgets(mhs[index].nama, sizeof(mhs[index].nama), stdin);
    mhs[index].nama[strcspn(mhs[index].nama, "\n")] = '\0';
    
    printf("Umur: ");
    while (scanf("%d", &mhs[index].umur) != 1)
    {
        printf("[ERROR] Umur harus berupa angka!\n");
        clearBuffer();
        printf("Umur: ");
    }
    clearBuffer();
    
    printf("IPK : ");
    while (scanf("%f", &mhs[index].ipk) != 1)
    {
        printf("[ERROR] IPK harus berupa angka!\n");
        clearBuffer();
        printf("IPK : ");
    }
    clearBuffer();

    printf("[SUCCESS] Data berhasil diupdate!\n\n");
}

// Fungsi menghapus data mahasiswa
void hapusData(struct Mahasiswa mhs[], int *jumlah)
{
    if (*jumlah == 0)
    {
        printf("\n[INFO] Belum ada data mahasiswa untuk dihapus.\n\n");
        return;
    }

    int nomor;
    printf("\n--- Hapus Data Mahasiswa ---\n");
    printf("Masukkan nomor mahasiswa yang ingin dihapus (1-%d): ", *jumlah);
    
    if (scanf("%d", &nomor) != 1)
    {
        printf("[ERROR] Input harus berupa angka!\n\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    if (nomor < 1 || nomor > *jumlah)
    {
        printf("[ERROR] Nomor tidak valid!\n\n");
        return;
    }

    int index = nomor - 1;
    
    printf("\nData yang akan dihapus:\n");
    printf("Nama: %s\n", mhs[index].nama);
    printf("Umur: %d\n", mhs[index].umur);
    printf("IPK : %.2f\n", mhs[index].ipk);
    
    char konfirmasi;
    printf("\nApakah Anda yakin ingin menghapus data ini? (y/n): ");
    scanf(" %c", &konfirmasi);
    clearBuffer();
    
    if (konfirmasi == 'y' || konfirmasi == 'Y')
    {
        // Geser semua elemen setelah index yang dihapus
        int i;
        for (i = index; i < *jumlah - 1; i++)
        {
            mhs[i] = mhs[i + 1];
        }
        (*jumlah)--;
        printf("[SUCCESS] Data berhasil dihapus!\n\n");
    }
    else
    {
        printf("[INFO] Penghapusan dibatalkan.\n\n");
    }
}