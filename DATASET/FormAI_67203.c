//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include<stdio.h>

int main() {
    char str[1000];
    int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); /*read input string*/
    /*iterate through the string*/
    for(int i = 0; str[i] != '\0'; i++) {
        /*if current character is whitespace*/
        if(str[i] == ' ') {
            count++; /*increment the word count*/
            while(str[i] == ' ') {
                i++; /*continuously skip whitespace*/
            }
        }
    }
    /*increment the count for the last word*/
    if(count > 0) {
        count++;
    }
    printf("Total number of words in the given string: %d\n", count);
    return 0;
}