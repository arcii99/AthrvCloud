//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main () {
    int length, upper, lower, digits, special;
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}|[]\\:\";'<>?,./";
    char password[100];
    int charsetLength = strlen(charset);

    printf("Welcome to the Password Generator program!\n\n");

    printf("Enter the desired length of your password (8-100): ");
    scanf("%d", &length);

    printf("Enter the number of uppercase letters you would like in your password: ");
    scanf("%d", &upper);

    printf("Enter the number of lowercase letters you would like in your password: ");
    scanf("%d", &lower);

    printf("Enter the number of digits you would like in your password: ");
    scanf("%d", &digits);

    printf("Enter the number of special characters you would like in your password: ");
    scanf("%d", &special);

    // Make sure the sum of uppercase, lowercase, digits, and special characters is not greater than the password length
    if ((upper + lower + digits + special) > length) {
        printf("Error! The sum of uppercase, lowercase, digits, and special characters cannot be greater than the password length.\n");
        return 1;
    }

    // Generate the password
    srand(time(NULL));
    int i;
    for (i = 0; i < upper; i++) {
        password[i] = charset[rand() % 26];
    }
    for (i = upper; i < (upper + lower); i++) {
        password[i] = charset[26 + rand() % 26];
    }
    for (i = (upper + lower); i < (upper + lower + digits); i++) {
        password[i] = charset[52 + rand() % 10];
    }
    for (i = (upper + lower + digits); i < length; i++) {
        password[i] = charset[62 + rand() % (charsetLength - 62)];
    }
    password[length] = '\0';

    // Shuffle the password
    for (i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("\nYour password is:");
    printf("\n%s\n\n", password);

    return 0;
}