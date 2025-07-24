//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
// Romeo and Juliet have a conversation about string manipulation

#include <stdio.h>
#include <string.h>

int main() {
    char romeo[50], juliet[50];
    int n;

    printf("Romeo: My dear Juliet, what wondrous words dost thou seekest to convey?\n");
    printf("Juliet: Romeo, my love, let us see what we shall make of these strings we hold so dear.\n");
    printf("\nEnter thy words, Romeo:\n");
    scanf("%s", romeo);

    printf("Enter thy words, Juliet:\n");
    scanf("%s", juliet);

    n = strcmp(romeo, juliet);

    if (n == 0) {
        printf("\nRomeo: Our strings, they match! Sweet harmony!\n");
    } else if (n > 0) {
        printf("\nRomeo: Ah, my fair Juliet, our strings doth differ...\n");
        printf("Juliet: But Romeo, let us not fret! Watch as I concat thy string with mine own!\n");
        strcat(juliet, romeo);
        printf("Juliet: And now, our strings align!\n");
    } else {
        printf("\nRomeo: Fair Juliet, thy string surpasses mine own...\n");
        printf("Juliet: Worry not, Romeo my love! Allow me to copy thy string into mine own...\n");
        strcpy(juliet, romeo);
        printf("Juliet: And now, our strings match!\n");
    }

    printf("\nFarewell, my dearest Romeo!\n");
    printf("Farewell, my sweet Juliet!\n");

    return 0;
}