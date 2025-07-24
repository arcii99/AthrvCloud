//FormAI DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], s3[100];
    
    printf("Enter string 1: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter string 2: ");
    fgets(s2, sizeof(s2), stdin);

    printf("The length of string 1 is %d\n", strlen(s1)-1);
    printf("The length of string 2 is %d\n", strlen(s2)-1);

    strcpy(s3, s1);
    strcat(s3, s2);

    printf("String 1: %s", s1);
    printf("String 2: %s", s2);
    printf("Combined string: %s", s3);

    printf("String 1 in uppercase: ");
    for (int i=0; s1[i]; i++){
        putchar(toupper(s1[i]));
    }
    
    printf("String 2 in lowercase: ");
    for (int i=0; s2[i]; i++){
        putchar(tolower(s2[i]));
    }

    printf("String 3 in reverse: ");
    for (int i=strlen(s3)-1; i>=0; i--){
        putchar(s3[i]);
    }

    return 0;
}