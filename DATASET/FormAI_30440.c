//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the puzzling unit converter!\n");
    printf("Please choose the unit you wish to convert:\n");
    printf("1. Inconvertible units\n");
    printf("2. Baffling units\n");
    printf("3. Confusing units\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Sorry, these units cannot be converted.\n");
            break;
        case 2:
            printf("Please enter the number of baffles:\n");
            int baffles = 0;
            scanf("%d", &baffles);
            printf("%d baffles converted to bewilders is equal to %d.\n", baffles, (baffles * 3) - 2);
            break;
        case 3:
            printf("Please enter the number of confusions:\n");
            int confusions = 0;
            scanf("%d", &confusions);
            printf("%d confusions converted to conundrums is equal to %d.\n", confusions, (confusions / 2) * 3);
            break;
        default:
            printf("That is not a valid choice.\n");
    }

    return 0;
}