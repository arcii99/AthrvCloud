//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char name[20];
    int age;
    char gender;
    bool is_valid = true;

    printf("Welcome! Please enter your name: ");
    scanf("%s", name);

    for(int i=0; name[i]!='\0'; i++) {
        if(!isalpha(name[i])) {
            is_valid = false;
        }
    }

    if(!is_valid) {
        printf("Invalid name format! Only alphabets are allowed.\n");
        return 0;
    }

    printf("Enter your age: ");
    if(!scanf("%d", &age)) {
        printf("Invalid age format! Only numbers are allowed.\n");
        return 0;
    }

    printf("Enter your gender (M/F): ");
    if(!scanf(" %c", &gender)) {
        printf("Invalid gender format! Only 'M' or 'F' are allowed.\n");
        return 0;
    }

    gender = toupper(gender);

    if(gender!='M' && gender!='F') {
        printf("Invalid gender format! Only 'M' or 'F' are allowed.\n");
        return 0;
    }

    printf("Thank you for providing your information!\n");
    return 0;
}