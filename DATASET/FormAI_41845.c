//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <string.h>

int main() {
    char virus[10];
    char antivirus[10] = "acdfh";
    printf("Enter a word: ");
    scanf("%s", virus);

    if (strcmp(virus, antivirus) == 0) {
        printf("The word you entered contains a virus.\n");
    } else {
        printf("The word you entered is safe.\n");
    }

    return 0;
}