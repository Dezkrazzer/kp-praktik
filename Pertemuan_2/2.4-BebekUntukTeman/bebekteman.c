// Program untuk menghitung bebek

/*
    WM:
    Lazuardi Akbar Imani (105)
    https://github.com/Dezkrazzer
*/

/*
    SOAL: 2.4-BebekUntukTeman

    Deskripsi:
    Pak Dengklek memiliki N ekor bebek. Ia ingin membagi-bagikan bebek-bebeknya tersebut sama rata kepada M orang temannya. Pak Dengklek
    juga menyadari bahwa bisa saja terdapat sisa bebek karena banyaknya bebek tidak habis dibagi banyaknya temannya.
    Bantulah Pak Dengklek untuk menentukan berapa ekor bebek yang harus dia berikan kepada masing-masing temannya, dan berapa sisaya.

    Format Input:
    Sebuah baris berisi dua buah bilangan bulat N dan M

    Format Output:
    Baris pertama berisi masing-masing A, dengan A adalah banyaknya bebek yang diberikan kepada masing-masing temannya. Baris kedua
    berisi bersisa B, dengan B adalah banyaknya sisa bebek Pak Dengklek

    Contoh Input 1:
    15 3

    Contoh Output 1:
    masing-masing 5
    bersisa 0

    Contoh Input 2:
    20 3

    Contoh Output 2:
    masing-masing 6
    bersisa 2
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