//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // surrealism meets data validation
    printf("Enter a value between 1 and 100 to calculate the checksum: ");
    int input;
    scanf("%d", &input);
    if (input < 1 || input > 100) {
        printf("Error: Invalid input. Program will now self-destruct.\n");
        return 1;
    }

    // randomize checksum calculation
    srand(time(NULL));
    int checksum = rand() % input + input / 2;

    // surrealist display of checksum
    printf("\nCalculating checksum...\n\n");
    printf("        _______\n");
    printf("  ____/      /\\\n");
    printf(" /          /  \\\n");
    printf("/_________/____\\\n");
    printf("|         |     |\n");
    printf("| CHECKSUM | %03d |\n", checksum);
    printf("|_________|_____|");

    return 0;
}