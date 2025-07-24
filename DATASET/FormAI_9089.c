//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", A, C);
        return;
    }
    TowerOfHanoi(n - 1, A, C, B);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    TowerOfHanoi(n - 1, B, A, C);
}

int main() {
    int n = 4;
    printf("The Tower of Hanoi problem in C\n");
    printf("-------------------------------\n\n");
    printf("The initial configuration is as follows:\n\n");
    printf("         |         |         |\n");
    printf("        +++        |         |\n");
    printf("       +++++       |         |\n");
    printf("      +++++++      |         |\n");
    printf("     +++++++++     |         |\n");
    printf("    +++++++++++    |         |\n");
    printf("   +++++++++++++   |         |\n");
    printf("         A         B         C\n\n");
    TowerOfHanoi(n, 'A', 'B', 'C');
    printf("\nThe final configuration is as follows:\n\n");
    printf("         |         |         |\n");
    printf("         |         |        +++\n");
    printf("         |         |       +++++\n");
    printf("         |         |      +++++++\n");
    printf("         |         |     +++++++++\n");
    printf("         |         |    +++++++++++\n");
    printf("         |         |   +++++++++++++\n");
    printf("         A         B         C\n");
    return 0;
}