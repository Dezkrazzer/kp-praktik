/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/

#include <stdio.h>

int main() {
    int panjang[] = {225, 215, 198, 314, 299, 240};
    int lebar[] = {335, 394, 400, 298, 278, 330};
    int jumlah_kandang = 0;

    for (int i = 0; i < 6; i++) {
        int luas = panjang[i] * lebar[i];
        if (luas >= 80000) {
            jumlah_kandang++;
        }
    }

    printf("Jumlah kandang bebek yang memenuhi syarat adalah sebanyak %d kandang\n", jumlah_kandang);
    return 0;
}