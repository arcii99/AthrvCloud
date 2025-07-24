//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include<stdio.h>

void hanoi(int num_discs, char source_pole, char destination_pole, char auxiliary_pole) {
    if(num_discs > 0) {
        hanoi(num_discs-1, source_pole, auxiliary_pole, destination_pole);
        printf("Move disc %d from %c to %c\n", num_discs, source_pole, destination_pole);
        hanoi(num_discs-1, auxiliary_pole, destination_pole, source_pole);
    }
}

int main() {
    int num_discs;
    printf("Enter the number of discs: ");
    scanf("%d", &num_discs);
    hanoi(num_discs, 'A', 'C', 'B');
    return 0;
}