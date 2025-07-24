//FormAI DATASET v1.0 Category: Data validation ; Style: brave
#include <stdio.h>

int main() {
    int age;
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 18) {
        printf("Sorry %s, you are not eligible to enter.\n", name);
    } else if (age >= 18 && age <= 40) {
        printf("Welcome %s, enjoy your stay!\n", name);
    } else {
        printf("Hello %s, your age is above 40. Please enter a valid age.\n", name);
        return 0;
    }

    char gender;
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);
    if (gender == 'M') {
        printf("You are a male. Welcome!\n");
    } else if (gender == 'F') {
        printf("You are a female. Welcome!\n");
    } else {
        printf("Invalid gender entered.\n");
        return 0;
    }

    int phone_number;
    printf("Enter your phone number: ");
    scanf("%d", &phone_number);

    if (phone_number < 1000000000 || phone_number > 9999999999) {
        printf("Invalid phone number entered.\n");
        return 0;
    }

    printf("Thank you for entering valid information!\n");
    return 0;
}