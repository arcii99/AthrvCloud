//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 1000
 
void count_freq(char *str) {
    int freq[26] = {0}; //initialize frequency array to 0 for all alphabets
    int len = strlen(str), i, pos;
 
    // Determine the frequency of each character
    for (i = 0; i < len; i++) {
        pos = str[i] - 'a';
        freq[pos]++;
    }
 
    // display character and frequency of each character
    printf("The Frequency of Characters = \n");
    for (i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("%c = %d\n", i + 'a', freq[i]);
        }
    }
}
 
int main() {
    char str[MAX_LEN];
    printf("Enter the string to count frequency of characters in it: ");
    fgets(str, MAX_LEN, stdin);
    count_freq(str);
    return 0;
}