//FormAI DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {

    printf("Let's manipulate some C strings!\n");

    // declare a string variable and initialize it
    char myString[] = "Coding is awesome!";

    // print the original string
    printf("Original string: %s\n", myString);

    // get the length of the string
    int len = strlen(myString);
    printf("Length of the string: %d\n", len);

    // change the string to all uppercase
    for (int i = 0; i < len; i++) {
        myString[i] = toupper(myString[i]);
    }
    printf("All uppercase: %s\n", myString);

    // replace the word "awesome" with "fantastic"
    char *substr = strstr(myString, "AWESOME");
    if (substr != NULL) {
        strncpy(substr, "FANTASTIC", 9);
    }
    printf("Replaced \"awesome\" with \"fantastic\": %s\n", myString);

    // reverse the string
    for (int i = 0; i < len/2; i++) {
        char temp = myString[i];
        myString[i] = myString[len - 1 - i];
        myString[len - 1 - i] = temp;
    }
    printf("Reversed string: %s\n", myString);

    // count the number of occurrences of the letter 'A'
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (myString[i] == 'A') {
            count++;
        }
    }
    printf("Number of occurrences of the letter 'A': %d\n", count);

    // remove all spaces from the string
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        if (myString[i] != ' ') {
            myString[newLen++] = myString[i];
        }
    }
    myString[newLen] = '\0';
    printf("String with no spaces: %s\n", myString);

    return 0;
}