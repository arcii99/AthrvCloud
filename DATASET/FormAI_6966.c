//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char *);
void capitalizeString(char *);
void removeDuplicates(char *);

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Reverse the string
    printf("\n--- Reversed String ---\n");
    reverseString(str);

    // Capitalize the string
    printf("\n--- Capitalized String ---\n");
    capitalizeString(str);

    // Remove duplicates from the string
    printf("\n--- String without Duplicates ---\n");
    removeDuplicates(str);

    return 0;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char revStr[MAX_LENGTH];
    for(int i=0; i<len; i++) {
        revStr[i] = str[len-i-1];
    }
    revStr[len] = '\0';
    printf("%s", revStr);
}

// Function to capitalize the string
void capitalizeString(char *str) {
    int len = strlen(str);
    char capStr[MAX_LENGTH];
    for(int i=0; i<len; i++) {
        if(i==0 || str[i-1]==' ') {
            capStr[i] = toupper(str[i]);
        } else {
            capStr[i] = str[i];
        }
    }
    capStr[len] = '\0';
    printf("%s", capStr);
}

// Function to remove duplicates from the string
void removeDuplicates(char *str) {
    int len = strlen(str);
    char remDup[MAX_LENGTH];
    int index = 0;
    for(int i=0; i<len; i++) {
        int isDuplicate = 0;
        for(int j=0; j<i; j++) {
            if(str[i] == str[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if(!isDuplicate) {
            remDup[index++] = str[i];
        }
    }
    remDup[index] = '\0';
    printf("%s", remDup);
}