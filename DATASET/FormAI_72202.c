//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
/* Manipulating C strings the Linus Torvalds way */

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, j, len1, len2;
    
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    /* Concatenate strings */
    printf("\nConcatenating strings: ");
    for (i=0; i<len1; i++) {
        putchar(str1[i]);
    }
    for (j=0; j<len2; j++) {
        putchar(str2[j]);
    }
    
    /* Compare strings */
    printf("\nComparing strings: ");
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal");
    } else {
        printf("Strings are not equal");
    }
    
    /* Copy strings */
    printf("\nCopying strings: ");
    strcpy(str1, str2);
    printf("String 2 copied to String 1: %s", str1);
    
    /* Reverse strings */
    printf("\nReversing strings: ");
    for (i=len1-1; i>=0; i--) {
        putchar(str1[i]);
    }
    for (j=len2-1; j>=0; j--) {
        putchar(str2[j]);
    }
    
    printf("\n");

    return 0;
}