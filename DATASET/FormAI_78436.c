//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
// Romeo and Juliet - Binary Converter

#include <stdio.h>

int main() {
    int input, binary[100], i = 0, j;
    char answer;
    printf("Romeo: Oh my Juliet, let me help thee with thy binary conversion!\n");
    do {
        printf("Romeo: Tell me, what integer doth thee desire to convert into binary? : ");
        scanf("%d", &input);
        while (input > 0) {
            binary[i] = input % 2;
            input /= 2;
            i++;
        }
        printf("Romeo: The binary equivalent of thy integer is: ");
        for (j = i - 1; j >= 0; j--)
            printf("%d", binary[j]);
        printf("\nJuliet: Oh my dearest Romeo, how thou dost impress me with thy programming skills!\n");
        printf("Romeo: Anything for thee, my love.\n");
        printf("Romeo: Would thee like to try another integer? (Y/N) : ");
        scanf(" %c", &answer);
        i = 0;
    } while (answer == 'Y' || answer == 'y');
    printf("Romeo: Farewell, my love. Until we meet again.\n");
    return 0;
}