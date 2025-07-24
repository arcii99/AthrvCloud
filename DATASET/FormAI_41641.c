//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define CRYP_KEY 0x378
/* Level 1 Implementation (Generate Random Checksums for each word): */

char *char_checksum(char *word) {
    int i, checksum=0;
    int len = strlen(word);
    char *sum = (char*)malloc(sizeof(char)*2);
    srand(time(NULL));
    for(i=0; i<len; i++)
        checksum += (int)word[i];
    checksum = (checksum ^ CRYP_KEY) % 100;
    sprintf(sum, "%02d", checksum);
    return sum;
}

int main() {
    printf("\n\n-----------------------\n");
    printf("    Cryptic Checksum    \n");
    printf("-----------------------\n\n");
    printf("Enter a word to generate its cryptic checksum:\n");
    char word[100];
    scanf("%s", word);
    printf("\nCalculating checksum ...");
    char *checksum = char_checksum(word);
    printf("\n\nResult:\n");
    printf("%s --> %s\n\n", word, checksum);
    return 0;
}