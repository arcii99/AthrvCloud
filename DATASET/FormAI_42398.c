//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>

int main() {
    int choice;
    printf("Choose a shape:\n");
    printf("1. Triangle\n");
    printf("2. Square\n");
    printf("3. Rectangle\n");
    printf("4. Diamond\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\t   *\n");
            printf("\t  * *\n");
            printf("\t *   *\n");
            printf("\t*******\n\n");
            break;
        case 2:
            printf("\t****\n");
            printf("\t*  *\n");
            printf("\t*  *\n");
            printf("\t****\n\n");
            break;
        case 3:
            printf("\t******\n");
            printf("\t*    *\n");
            printf("\t*    *\n");
            printf("\t******\n\n");
            break;
        case 4:
            printf("\t   *\n");
            printf("\t  ***\n");
            printf("\t *****\n");
            printf("\t*******\n");
            printf("\t *****\n");
            printf("\t  ***\n");
            printf("\t   *\n\n");
            break;
        default:
            printf("Invalid input!\n\n");
            break;
    }

    return 0;
}