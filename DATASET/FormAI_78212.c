//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include<stdio.h>
#include<string.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    int i, sum = 0;
    
    printf("Enter a string to calculate checksum: ");
    fgets(str, MAX_LEN, stdin);

    // remove newline character
    str[strcspn(str, "\n")] = 0;

    printf("String entered: %s\n", str);

    for(i = 0; i < strlen(str); i++) {
        sum += str[i];
    }

    printf("Checksum: %d\n", sum);

    return 0;
}