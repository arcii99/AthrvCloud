//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], str3[50];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Copying the first string to the third string
    strcpy(str3, str1);
    printf("The first string is copied in the third string as: %s\n", str3);

    // Concatenating the first and second string and storing in the third string
    strcat(str3, str2);
    printf("The concatenation of first and second string is: %s\n", str3);

    // Comparing the first and second string
    int result = strcmp(str1, str2);
    if(result == 0) {
        printf("The first and second string are identical.\n");
    }
    else if(result < 0) {
        printf("The first string is smaller than the second string.\n");
    }
    else {
        printf("The first string is greater than the second string.\n");
    }

    // Reversing the third string
    int len = strlen(str3);
    int i, j;
    char temp;
    for(i=0, j=len-1; i<len/2; i++, j--) {
        temp = str3[i];
        str3[i] = str3[j];
        str3[j] = temp;
    }
    printf("The reverse of the third string is: %s\n", str3);

    return 0;
}