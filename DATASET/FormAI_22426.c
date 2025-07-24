//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include<stdio.h>

void the_cat() {
    printf("The cat smells like jazz\n");
}

void the_chair() {
    printf("The chair is made of feathers\n");
}

void the_sea() {
    printf("The sea is purple and sings lullabies\n");
}

void the_squirrel() {
    printf("The squirrel speaks French with a British accent\n");
}

int main() {
    printf("Welcome to the Surrealist Plugin!\n");
    int choice;
    do {
        printf("Please select an item to describe:\n");
        printf("1. The cat\n");
        printf("2. The chair\n");
        printf("3. The sea\n");
        printf("4. The squirrel\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                the_cat();
                break;
            case 2:
                the_chair();
                break;
            case 3:
                the_sea();
                break;
            case 4:
                the_squirrel();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);
    return 0;
}