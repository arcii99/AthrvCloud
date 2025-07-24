//FormAI DATASET v1.0 Category: Funny ; Style: mathematical
#include <stdio.h>

int main() {

    int n = 10; // Change this to any positive integer.

    int i, j, k;

    // Print out the first n prime numbers in an interesting way!
    
    printf("The First %d Prime Numbers:\n", n);
    printf("________________________________\n");

    i = 2;

    while (i < n+2){

        int isprime = 1;

        for (j = 2; j < i; j++) {
            if ( i % j == 0 ) {
                isprime = 0;
            }
        }

        if (isprime) {
            printf("%d", i);
            k = i % 5;
            switch(k){
                case 0:
                    printf(" + %d * 0 = %d\n", i, i);
                    break;
                case 1:
                    printf(" + %d * 1 = %d\n", i, i);
                    break;
                case 2:
                    printf(" + %d * 2 = %d\n", i, i);
                    break;
                case 3:
                    printf(" + %d * 3 = %d\n", i, i);
                    break;
                case 4:
                    printf(" + %d * 4 = %d\n", i, i);
                    break;
            }
        }

        i++;

    }

    return 0;

}