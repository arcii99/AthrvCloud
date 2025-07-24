//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
/* ~~~~ The Secret Garden ~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BLUSH "\x1b[31m"
#define EARTH "\x1b[33m"
#define FERN  "\x1b[32m"
#define TEAL  "\x1b[36m"
#define RAVEN "\x1b[37m"
#define GLACIER "\x1b[34m"
#define ROSE  "\x1b[35m"
#define MOON  "\x1b[37;1m"

/* ~~~~ These are the seeds we'll use ~~~~ */

unsigned int p = 17; 
unsigned int q = 19; 
unsigned int n, phi_n, e, d;

void blossom() { 
    /* ~~~~ We'll mix the seeds here ~~~~ */

    n = p * q;
    phi_n = (p-1) * (q-1);

    /* ~~~~ Let's find an e that's relatively prime with phi_n ~~~~ */

    srand(time(0));  
    e = rand()%phi_n + 1; 
    for (; e < phi_n; e++) { 
        if (fmod(phi_n, e) == 0) continue; 
        unsigned int check = phi_n/e; 
        if (fmod(phi_n, check) == 0) continue; 
        break; 
    }

    /* ~~~~ We'll find d with a cool recursive algorithm ~~~~ */
    /* ~~~~ It's called the Extended Euclidean Algorithm ~~~~ */

    unsigned int a = phi_n, b = e, t, quotient; 
    unsigned int x = 0, y = 1, last_x = 1, last_y = 0;
    while (b != 0) {
        quotient = a / b;
        t = b; 
        b = a % b; 
        a = t; 
        t = x; 
        x = last_x - quotient * x; 
        last_x = t; 
        t = y; 
        y = last_y - quotient * y; 
        last_y = t; 
    }
    d = last_x;

    /* ~~~~ Time for the grand reveal! ~~~~ */

    printf(MOON"\n The public keys are: n=%d, e=%d\n",n,e); 
    printf(EARTH"\n The private key is: d=%d\n\n\n",d); 
}

void encrypt(char message[]) {
    printf(FERN"\n The encrypted message is: ");
    for (int i = 0; i < strlen(message); i++) { 
        printf("%d ", fmod(pow(message[i], e), n)); 
    }
    printf("\n");
}

void decrypt(int arr[], int size) { 
    printf(ROSE"\n The decrypted message is: ");
    for (int i = 0; i < size; i++) { 
        int decrypted = fmod(pow(arr[i], d), n); 
        printf("%c", decrypted); 
    } 
    printf("\n"); 
}
int main() {

    // Let the magic begin...
    printf(GLACIER"\nWelcome to The Secret Garden!\n");
    printf(RAVEN"\nIntroduce yourself and tell us your secret message: ");
    
    char message[100];
    fgets(message,100,stdin);
    printf(BLUSH"\n Lovely! Let's keep it safe from prying eyes!\n");

    blossom();

    unsigned int size = strlen(message); 
    int message_arr[size];

    for (int i = 0; i < size; i++) { 
        message_arr[i] = message[i]; 
    }

    encrypt(message);

    decrypt(message_arr, size);

    return 0;
}