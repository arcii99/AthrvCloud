//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

void displayWelcomeMessage() {
    printf("*** Welcome to Procedural Space Adventure ***\n\n");
    printf("You are a space explorer. You have been assigned a mission\n");
    printf("to find a new habitable planet for human race as earth is\n");
    printf("getting destroyed due to pollution and climate change.\n");
    printf("You are in the spaceship and travelling through the space.\n");
    printf("You need to make some decisions to complete the mission.\n\n");
}

int main() {
    displayWelcomeMessage();
    int choice;
    printf("Press 1 to check the spaceship fuel\n");
    printf("Press 2 to check your inventory\n");
    printf("Press 3 to check the map\n");
    printf("Press 4 to view the messages from the headquarters\n");
    printf("Press 5 to continue your journey\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Fuel level: 95%%\n");
            break;
        case 2:
            printf("You have the following items in your inventory:\n");
            printf("- Oxygen Cylinders (2)\n");
            printf("- Food Packets (5)\n");
            printf("- Water Bottles (3)\n");
            break;
        case 3:
            printf("Map is not available yet.\n");
            break;
        case 4:
            printf("There are no new messages from the headquarters.\n");
            break;
        case 5:
            printf("You continue your journey through the space.\n");
            printf("As you move forward, you see a nearby planet.\n");
            printf("Do you want to land on the planet? (yes/no): ");
            char landChoice[10];
            scanf("%s", landChoice);
            if(strcmp(landChoice, "yes") == 0) {
                printf("You landed the spaceship on the planet.\n");
                printf("As you step out of the spaceship, you see that the\n");
                printf("planet is full of greenery and water bodies. You feel\n");
                printf("excited as you find the planet habitable.\n");
            } else {
                printf("You entered no. The spaceship continues\n");
                printf("its journey through the vast space.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    
    return 0;
}