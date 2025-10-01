/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

#include <stdio.h>

int main() {
    int bilangan;
    scanf("%d", &bilangan);

    for (int faktor = bilangan; faktor >= 1; faktor--) {
        if (bilangan % faktor == 0) {
            printf("%d\n", faktor);
        }
    }

    return 0;
}