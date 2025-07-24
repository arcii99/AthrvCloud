//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: genious
#include <stdio.h>

int main() {

    int n, t1 = 0, t2 = 1, nextTerm = 0;
    char* title = "Fibonacci Sequence Visualizer";
    printf("%s\n", title);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("=====================================\n");
    printf("|       Term       |    Sequence    |\n");
    printf("=====================================\n");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("|         %d         |        %d        |\n", i, t1);
        } else if (i == 2) {
            printf("|         %d         |        %d        |\n", i, t2);
        } else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("|         %d         |        %d        |\n", i, nextTerm);
        }
    }

    printf("=====================================\n");
    return 0;
}