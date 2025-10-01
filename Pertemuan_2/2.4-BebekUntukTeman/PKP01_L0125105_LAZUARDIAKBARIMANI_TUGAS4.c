/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int perteman = N / M;
    int sisa = N % M;

    printf("masing-masing %d\n", perteman);
    printf("bersisa %d\n", sisa);

    return 0;
}