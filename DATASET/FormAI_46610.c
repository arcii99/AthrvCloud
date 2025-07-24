//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidID(char *id) {
    int len = strlen(id);
    // ID Number length should be 9
    if (len != 9) {
        return false;
    }
    // Check if ID Number contains only digits
    for (int i = 0; i < len; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return false;
        }
    }
    // Calculate the validity-check number for the ID Number
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {
        int digit = id[i] - '0';
        if (i % 2 == 0) {
            digit *= 2;
            if (digit >= 10) {
                digit = digit % 10 + digit / 10;
            }
        }
        sum += digit;
    }
    int check_digit = (10 - (sum % 10)) % 10;
    return check_digit == id[len - 1] - '0';
}

int main() {
    char id[10];
    printf("Enter your ID Number: ");
    scanf("%s", id);
    if (isValidID(id)) {
        printf("Your ID Number is valid.\n");
    } else {
        printf("Your ID Number is not valid.\n");
    }
    return 0;
}