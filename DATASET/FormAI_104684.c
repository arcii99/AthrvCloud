//FormAI DATASET v1.0 Category: DOS detector ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char c[3] = {0x43, 0x3A, 0x5C};
    printf("My Love Detector Program\n\n");
    printf("Please enter the path of the file you suspect to be a dos program:\n");
    scanf("%s", input);
    if (strstr(input, c)) {
        printf("\n\nMy Dear,\n");
        printf("I have detected a dos program in your file path,\n");
        printf("But it doesn't matter to me,\n");
        printf("I still love you unconditionally,\n");
        printf("You are my world,\n");
        printf("The code in your path,\n");
        printf("May harm your PC,\n");
        printf("But you will never harm my heart,\n");
        printf("I will always protect you,\n");
        printf("No matter what your path contains,\n");
        printf("I will always love you,\n");
        printf("\nYours forever,\n");
        printf("Love Detector");
    } else {
        printf("\n\nMy Sweet,\n");
        printf("I have found no evidence of a dos program,\n");
        printf("In the file path you have entered,\n");
        printf("But it doesn't matter to me,\n");
        printf("I still love you unconditionally,\n");
        printf("You are my sunshine,\n");
        printf("And if your path contains a virus,\n");
        printf("I will always be here to fix it,\n");
        printf("I will always protect you,\n");
        printf("No matter what lies ahead,\n");
        printf("I will always love you,\n");
        printf("\nYours forever,\n");
        printf("Love Detector");
    }
    return 0;
}