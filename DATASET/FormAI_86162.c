//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {

    char str1[50] = "Welcome to the future";
    char str2[50] = "future is cool";
    char str3[50];
    int len;

    // Copying str1 to str3
    strcpy(str3, str1);
    printf("After copying str1: %s\n", str3);

    // Concatenating str1 and str2
    strcat(str1, str2);
    printf("After concatenating str1 and str2: %s\n", str1);

    // Finding the length of str1
    len = strlen(str1);
    printf("Length of str1: %d\n", len);

    // Comparing str1 and str2
    if (strcmp(str1, str2) == 0)
        printf("Both strings are equal\n");
    else
        printf("Both strings are not equal\n");

    // Converting all characters in str1 to uppercase
    for (int i = 0; str1[i]!='\0'; i++){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            str1[i] = str1[i] - 32;
        }
    }
    printf("After converting str1 to uppercase: %s\n", str1);

    // Reversing str1
    int j = 0;
    for (int i = len - 1; i >= 0; i--){
        str3[j++] = str1[i];
    }
    str3[j] = '\0';
    printf("After reversing str1: %s\n", str3);

    return 0;
}