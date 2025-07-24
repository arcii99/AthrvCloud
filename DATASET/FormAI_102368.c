//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"
#define SYMBOLS "!@#$%^&*()_-+={}[]|;:',.<>/?~"

char *generate_password(int length);

int main()
{
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    char *password = generate_password(length);

    printf("Your secure password is: %s\n", password);
    free(password);

    return 0;
}

char *generate_password(int length)
{
    srand(time(NULL));
    char *pw = (char*) malloc(length+1); //+1 for terminating null character
    char charset[94]; //We'll use all printable ASCII characters between 33 and 126
    strcpy(charset, UPPER LOWER NUMBERS SYMBOLS);
    int i;

    for (i = 0; i < length; i++) {
        int index = rand() % 94; //Number of characters in charset
        pw[i] = charset[index];
    }
    pw[length] = '\0';

    return pw;
}