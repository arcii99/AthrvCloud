//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
/* 
	"PRIMETIME"
	A Prime Number Generator C program with an artistic touch!
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main() {

    int num, i, counter;

    printf("\e[1;34m\n\n*** WELCOME TO PRIMETIME! ***\n\n\e[0m");
    printf("\e[1;34m*****************************************\n\e[0m");

    do {
        printf("\nPlease enter a positive integer greater than 1: ");
        scanf("%d", &num);
    } while(num <= 1); // Ensure input is valid, i.e. greater than 1

    printf("\nGenerating the prime numbers up to %d...\n", num);

    sleep(1); // Pause for dramatic effect
    printf("\e[1;33m\n>> INITIALIZING PRIMETIME SEQUENCE...<<\n\e[0m");

    for(i = 2; i <= num; i++) {

        counter = 0;

        for(int j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                counter++;
                break;
            }
        }

        if(counter == 0 && i != 1) {
            printf("\e[1;35m%d\e[0m ", i); // Print prime numbers in purple
            fflush(stdout);
            usleep(35000); // Pause slightly to create a scrolling effect
        }
    }

    printf("\n\e[1;34m*****************************************\n\e[0m");
    printf("\n\tThank you for using PRIMETIME!\n\n");

    return 0;
}