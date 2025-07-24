//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include<stdio.h>
#include<string.h>

int main() {
    char str1[50], str2[50], temp[50];
    int i, j, k, len1, len2;
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Reversing the first string
    len1 = strlen(str1);
    for (i=0; i<len1/2; i++) {
        temp[i] = str1[i];
        str1[i] = str1[len1-i-1];
        str1[len1-i-1] = temp[i];
    }

    // Reversing the second string
    len2 = strlen(str2);
    for (i=0; i<len2/2; i++) {
        temp[i] = str2[i];
        str2[i] = str2[len2-i-1];
        str2[len2-i-1] = temp[i];
    }

    // Concatenating the reversed strings
    for (i=0; i<len2; i++) {
        str1[len1+i] = str2[i];
    }

    // Reversing the concatenated string
    k = strlen(str1);
    for (i=0; i<k/2; i++) {
        temp[i] = str1[i];
        str1[i] = str1[k-i-1];
        str1[k-i-1] = temp[i];
    }

    printf("Concatenated string: %s\n", str1);
    return 0;
}