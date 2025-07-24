//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Enter the number of base pairs to sequence: ");
    int num_bp;
    scanf("%d", &num_bp);

    printf("\nSequencing in progress...\n\n");

    srand(time(NULL));

    char base[] = {'A', 'C', 'G', 'T'};
    int i;

    for (i = 0; i < num_bp; i++) {
        printf("%c", base[rand() % 4]);
    }

    printf("\n\nSequencing complete. Do you accept this DNA sample?\n");
    char answer[10];
    scanf("%s", answer);

    if (strcmp(answer, "Yes") == 0) {
        printf("\nMontague House accepts this sample. Capulet House also accepts this sample.\n");
    } else {
        printf("\nMontague House rejects this sample. Capulet House also rejects this sample.\n");
    }

    return 0;
}