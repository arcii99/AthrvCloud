//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num = rand() % 1000 + 1;

    printf("Let the surrealism begin!\n\n");
    printf("Behold, I present to you the prime numbers:\n");
    printf("1 is an interesting number, but too normal for surrealism.\n");

    for(int i = 2; i <= num; i++) {
        int isPrime = 1;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            printf("%d is as prime as a bird flying through a Salvador Dali landscape.\n", i);
            sleep(1);

            int random = rand() % i + 1;
            switch(random) {
                case 1:
                    printf("If a prime number could dream, %d would dream of electric sheep.\n", i);
                    break;
                case 2:
                    printf("The prime number %d hides secret messages for the surrealists to decipher.\n", i);
                    break;
                case 3:
                    printf("If %d were a color, it would be a shade of yellowish surrealism.\n", i);
                    break;
                case 4:
                    printf("The sound of %d is like a symphony of surrealism in the air.\n", i);
                    break;
                case 5: 
                    printf("When an abstract artist paints %d, it comes out as the purest form of surrealism.\n", i);
                    break;
                default:
                    printf("There is no way to describe the surrealism of %d in mere human language.\n", i);
                    break;
            }
        }
    }
    printf("\nMay the surrealism continue!\n");
    return 0;
}