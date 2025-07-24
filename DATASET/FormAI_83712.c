//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main(){
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy C Strings and refuse thy pointers;\n");
    printf("Or, if thou wilt not, be but sworn my love\n");
    printf("And I'll no longer be a string pointer.\n\n");

    char str1[100], str2[100];
    printf("Enter the first C string: ");
    fgets(str1, 100, stdin);

    printf("Enter the second C string: ");
    fgets(str2, 100, stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    if (len1 == len2){
        printf("O, speak again, bright angel! for thou hast code:\n");
        for (int i=0; i < len1; i++){
            printf("%c", str1[i]+str2[i]);
        }
    } else if (len1 > len2){
        printf("My bounty is boundless as the sea,\nMy C Strings as deep; the more I give to thee,\n%s", str1);
    } else {
        printf("Good night, good night! parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n%s", str2);
    }

    printf("\n\nBut soft, what light through yonder window breaks?\nIt is the east, and I'm being compared to west,\n");
    if (strcmp(str1, str2) == 0){
        printf("My heart is thine, dear C String\n");
    } else {
        printf("And for that name which is no part of thee,\nTake all myself.\n");
    }

    printf("\n\nAdieu! adieu! parting is such sweet\nsorrow, that I shall say good night till it be morrow.\n");
    return 0;
}