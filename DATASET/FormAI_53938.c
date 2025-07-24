//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "programming";
    char str2[] = "language";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n\n", str2);

    // Concatenating str2 to str1
    strcat(str1, str2);
    printf("After concatenation: %s\n", str1);

    // Removing the first 4 characters from str1
    memmove(str1, str1+4, strlen(str1));
    printf("After removing first 4 chars: %s\n", str1);

    // Reversing the string
    int len = strlen(str1), i;
    char temp;
    for(i = 0; i < len/2; i++){
        temp = str1[i];
        str1[i] = str1[len-1-i];
        str1[len-1-i] = temp;
    }
    printf("After reversing: %s\n", str1);

    // Counting the number of occurrences of 'g'
    int count = 0;
    char *ptr = str1;
    while((ptr = strchr(ptr, 'g')) != NULL){
        count++;
        ptr++;
    }
    printf("Number of occurrences of 'g': %d\n", count);

    // Converting the string to uppercase
    for(i = 0; str1[i]; i++){
        str1[i] = toupper(str1[i]);
    }
    printf("After converting to uppercase: %s\n", str1);

    return 0;
}