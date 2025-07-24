//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASS_LENGTH 25

int main()
{
    char password[MAX_PASS_LENGTH];
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~`|}{[]:;?><,./-=";
    int length, i;

    // Prometheus
    printf("\nC Secure Password Generator\n");
    printf("===========================\n\n");

    srand(time(NULL));

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    // Validation Check
    if (length > MAX_PASS_LENGTH) {
        printf("\nError: Maximum length allowed is %d characters.\n", MAX_PASS_LENGTH);
        exit(1);
    }

    // Generating the random password
    for(i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';

    printf("\nYour Password is: %s\n", password);

    return 0;
}