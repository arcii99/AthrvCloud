//FormAI DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <string.h>

// function to count the number of vowels in a string
void count_vowels(char* str) {
    int count = 0;
    int len = strlen(str);

    // loop through each character in the string
    for(int i=0; i<len; i++) {
        // if the character is a vowel, increment the count
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
           str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }

    // print the number of vowels in the string
    printf("Number of vowels: %d\n", count);
}

int main() {
    // initialize a string
    char str[] = "This is a sample string";

    // call the function to count the number of vowels in the string
    count_vowels(str);

    return 0;
}