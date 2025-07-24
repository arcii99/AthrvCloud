//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printAlien(int currentShape);

int main() {
    int currentShape = 0;
    int destination = 0;
    srand(time(NULL));
    
    // Intro
    printf("Welcome to Procedural Space Adventure: Shape Shifting Style!\n\n");
    printf("You are an alien on a mission to save your home planet from destruction.\n");
    printf("You must travel through space, shapeshift into new forms, and complete various tasks to save your planet.\n");
    printf("Good luck on your journey!\n\n");
    
    // Game loop
    while(1) {
        printf("You are currently in shape %d.\n", currentShape);
        
        // Determine next destination
        do {
            destination = rand() % 4;
        } while(destination == currentShape);
        
        // Travel to destination
        printf("You shape shift into a new form and travel to shape %d.\n\n", destination);
        currentShape = destination;
        
        // Perform task based on current shape
        switch(currentShape) {
            case 0:
                printf("You are a blob and must absorb smaller creatures. Press enter to continue.\n");
                getchar();
                break;
            case 1:
                printf("You are a crystal and must reflect beams of light. Press enter to continue.\n");
                getchar();
                break;
            case 2:
                printf("You are a plant and must generate oxygen. Press enter to continue.\n");
                getchar();
                break;
            case 3:
                printf("You are a creature and must navigate through a maze. Press enter to continue.\n");
                getchar();
                break;
        }
        
        // Print current alien shape
        printAlien(currentShape);
        
        // Check win condition
        if(currentShape == 2) {
            printf("Congratulations! You have saved your home planet.\n");
            break;
        }
    }
    
    return 0;
}

void printAlien(int currentShape) {
    switch(currentShape) {
        case 0:
            printf("   ___\n");
            printf(" /  O  \\\n");
            printf("/_______\\\n");
            break;
        case 1:
            printf("   / \\\n");
            printf("  /   \\\n");
            printf(" /     \\\n");
            printf("<------->\n");
            printf(" \\     /\n");
            printf("  \\   /\n");
            printf("   \\ /\n");
            break;
        case 2:
            printf("   /\\ \n");
            printf("  /  \\ \n");
            printf(" /____\\ \n");
            printf(" |    | \n");
            printf(" |    | \n");
            printf(" |    | \n");
            break;
        case 3:
            printf("     ___  \n");
            printf(" ___/   \\__\n");
            printf("/           \n");
            printf("\\_____|____/\n");
            break;
    }
}