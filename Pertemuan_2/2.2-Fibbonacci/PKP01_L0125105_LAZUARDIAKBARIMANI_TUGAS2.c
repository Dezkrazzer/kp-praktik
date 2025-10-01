/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
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