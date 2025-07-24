//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Thank you";
    char str2[50] = " for using this chatbot!";
    char str3[50] = "We appreciate your gratitude!";

    // Concatenating two strings
    strcat(str1, str2);
    
    // Comparing two strings
    if (strcmp(str1, str3) == 0) {
        printf("Your gratitude is overwhelming!\n");
    } else {
        printf("Please say thank you first\n");
    }

    // Getting the length of a string
    int length = strlen(str1);
    printf("Your gratitude message is %d characters long\n", length);

    // Converting string to uppercase
    for (int i = 0; str1[i]!='\0'; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
    }
    printf("%s\n", str1);

    // Converting string to lowercase
    for (int i = 0; str2[i]!='\0'; i++) {
        if(str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = str2[i] + 32;
        }
    }
    printf("%s\n", str2);

    return 0;
}