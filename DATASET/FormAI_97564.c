//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 100

int main(void) {
    int length, i, j, loop_count;
    char special[MAX_LEN] = {'!', '@', '#', '$', '%', '^', '&', '*'};
    char upper[MAX_LEN] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lower[MAX_LEN] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char number[MAX_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char password[MAX_LEN];
    srand(time(NULL));

    printf("Enter the password length: ");
    scanf("%d", &length);
    if (length < 8) {
        printf("Password length should be at least 8 characters\n");
        return 0;
    }

    loop_count = length / 4 + 1;
    j = 0;
    for (i = 0; i < loop_count; i++) {
        password[j++] = special[rand() % 8];
        password[j++] = upper[rand() % 26];
        password[j++] = lower[rand() % 26];
        password[j++] = number[rand() % 10];
    }
    password[length] = '\0';

    // Randomize the password array
    for (i = 0; i < length; i++) {
        j = rand() % length;
        char c = password[i];
        password[i] = password[j];
        password[j] = c;
    }
    printf("Generated Password is : %s\n", password);

    return 0;
}