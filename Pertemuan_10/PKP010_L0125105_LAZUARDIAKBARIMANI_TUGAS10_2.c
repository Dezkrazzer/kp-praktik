/*
    WM:
    L0125105_LAZUARDI AKBAR IMANI
    https://github.com/Dezkrazzer
*/

#include <stdio.h>
#include <ctype.h>

int isVokal(char c) {
    c = tolower(c);
    
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    {
        return 1;
    }

    return 0;
}

int main() {
    FILE *file;
    char karakter;
    int jumlahVokal = 0;
    
    file = fopen("text.txt", "r");
    
    if (file == NULL)
    {
        printf("Error: File text.txt not found!\n");
        return 1;
    }
    
    while ((karakter = fgetc(file)) != EOF)
    {
        if (isVokal(karakter)) {
            jumlahVokal++;
        }
    }
    
    fclose(file);
    printf("Jumlah huruf vokal = %d\n", jumlahVokal);
    
    return 0;
}