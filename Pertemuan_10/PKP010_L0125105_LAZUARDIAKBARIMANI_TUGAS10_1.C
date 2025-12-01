/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/

#include <stdio.h>

void cetakDeretMenurun(int n) {
    if (n == 0) {
        return;
    }

    printf("%d", n);
    
    if (n > 1) {
        printf(" ");
    }
    
    cetakDeretMenurun(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    cetakDeretMenurun(n);
    
    printf("\n");
    
    return 0;
}