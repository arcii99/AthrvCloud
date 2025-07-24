//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    char password[11];
    int i;

    srand(time(NULL)); /* Initialize random number generator */

    printf("Enter length of password (max 10): ");
    scanf("%d", &i);

    printf("Secure password generated: ");

    for(int j=0; j<i; j++){
        int randomNum = rand() % 94 + 33; /* Generate a random number between 33 and 126 */
        password[j] = (char)randomNum; /* Convert number to its corresponding character */
        printf("%c", password[j]);
    }

    return 0;
}