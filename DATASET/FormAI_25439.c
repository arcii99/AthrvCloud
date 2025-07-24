//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int gcd(int a, int b){
    int temp;
    while(1){
        temp = a % b;
        if(temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int main(){
    srand(time(NULL));

    int p = 47; // Replace with your prime number
    int q = 71; // Replace with your prime number

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 2; // Choose any number greater than 1 and less than phi
    while(e < phi){
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    int d;

    for(int i = 1; i < phi; i++){
        if((i * e) % phi == 1){
            d = i;
            break;
        }
    }

    int message[MAX];
    printf("Enter your message (letters only, max %d characters): ", MAX);
    fgets(message, MAX, stdin);

    int encrypted[MAX], decrypted[MAX];
    for(int i = 0; message[i] != '\0'; i++){
        if(message[i] == ' ')
            continue;

        int m = message[i] - 'a';
        encrypted[i] = (int) pow(m, e) % n;
        decrypted[i] = (int) pow(encrypted[i], d) % n;
    }

    printf("Encrypted message: ");
    for(int i = 0; message[i] != '\0'; i++){
        if(message[i] == ' ')
            continue;

        printf("%d ", encrypted[i]);
    }
    printf("\n");

    printf("Decrypted message: ");
    for(int i = 0; message[i] != '\0'; i++){
        if(message[i] == ' ')
            continue;

        printf("%c", (char)(decrypted[i] + 'a'));
    }
    printf("\n");

    return 0;
}