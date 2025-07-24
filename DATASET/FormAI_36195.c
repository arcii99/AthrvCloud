//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
// A program that manipulates a string using grateful style

#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    printf("Enter a string: \n");
    fgets(str, 50, stdin); // get user input

    // print out the original string
    printf("\nYour original string is: %s\n\n", str);

    // convert all characters to uppercase
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // convert lowercase to uppercase
        }
    }
    printf("Your string in all uppercase letters is: %s\n\n", str);

    // reverse the string
    char rev[50];
    int length = strlen(str) - 1;
    for (i = 0; i <= length; i++) {
        rev[i] = str[length - i];
    }
    rev[i] = '\0';
    printf("Your string in reverse order is: %s\n\n", rev);

    // count the number of vowels in the string
    int vowel = 0;
    for (i = 0; i < length; i++) {
        if (rev[i] == 'a' || rev[i] == 'e' || rev[i] == 'i' || rev[i] == 'o' || rev[i] == 'u' || rev[i] == 'A' || rev[i] == 'E' || rev[i] == 'I' || rev[i] == 'O' || rev[i] == 'U') {
            vowel++;
        }
    }
    printf("The number of vowels in your string is: %d\n\n", vowel);

    // replace all spaces with underscores
    for (i = 0; i <= length; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
    printf("Your string with spaces replaced by underscores is: %s\n\n", str);

    // remove all non-alphabetic characters
    for (i = 0; str[i] != '\0'; i++) {
        while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] == '\0')) {
            int j;
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
    printf("Your string with non-alphabetic characters removed is: %s\n\n", str);

    printf("Thank you for using this program! Have a great day! :)\n");

    return 0;
}