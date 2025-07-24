//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 256

int main(void) {
    srand(time(NULL));
    char secret_key[MAX_SIZE];
    int random_nums[MAX_SIZE];

    printf("Welcome to the Intrusion Detection System!\n\n");

    printf("Enter the secret key: ");
    scanf("%s", secret_key);
    fflush(stdin);

    for(int i=0; i<MAX_SIZE; i++) {
        random_nums[i] = rand() % 1000;
    }

    int key_len = strlen(secret_key);
    int sum = 0;
    for(int i=0; i<key_len; i++) {
        sum += secret_key[i];
    }

    int threshold = sum % 1000;

    printf("\nParanoid mode activated...\n");

    while(1) {
        int random_index = rand() % MAX_SIZE;
        int random_num = random_nums[random_index];

        if(random_num == threshold) {
            printf("\nINTRUSION DETECTED!\n");
            printf("Random number %d matched with threshold %d.\n", random_num, threshold);
            exit(1);
        }

        printf("Random number: %d\n", random_num);
        sleep(1);
    }

    return 0;
}