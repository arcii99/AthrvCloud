//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

/* function prototypes */
char* removeChar(char*, char);
char* reverseString(char*);
int countVowels(char*);
char* toUpperCase(char*);
char* toLowerCase(char*);

int main() {
    char name[20], choice;
    int len, vowels;

    /* read input string */
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n*****************************************\n");
    printf("***** Welcome to String Manipulation *****\n");
    printf("*****************************************\n");

    do {
        /* display menu */
        printf("\nMenu:\n");
        printf("1. Remove a character\n");
        printf("2. Reverse the string\n");
        printf("3. Count the number of vowels\n");
        printf("4. Convert to upper case\n");
        printf("5. Convert to lower case\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                /* remove a character */
                char c;
                printf("\nEnter the character you want to remove: ");
                scanf(" %c", &c);
                removeChar(name, c);
                printf("Result: %s", name);
                break;

            case '2':
                /* reverse the string */
                reverseString(name);
                printf("Result: %s", name);
                break;

            case '3':
                /* count number of vowels */
                vowels = countVowels(name);
                printf("\nNumber of vowels in the string: %d", vowels);
                break;

            case '4':
                /* convert to upper case */
                toUpperCase(name);
                printf("Result: %s", name);
                break;

            case '5':
                /* convert to lower case */
                toLowerCase(name);
                printf("Result: %s", name);
                break;

            case '0':
                /* exit the program */
                printf("\nExiting the program...");
                break;

            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != '0');

    return 0;
}

/* function to remove a character from a string */
char* removeChar(char* str, char c) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    return str;
}

/* function to reverse a string */
char* reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}

/* function to count number of vowels in a string */
int countVowels(char* str) {
    int i = 0, count = 0;
    while (str[i]) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
            || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
        i++;
    }

    return count;
}

/* function to convert a string to upper case */
char* toUpperCase(char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }

    return str;
}

/* function to convert a string to lower case */
char* toLowerCase(char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }

    return str;
}