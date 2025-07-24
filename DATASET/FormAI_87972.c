//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void navigate() {
    printf("Captain, where should we go now?\n");
    printf("1. Planet Zog\n");
    printf("2. Moon Korg\n");
    printf("3. Asteroid Belt\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Planet Zog it is. Buckle up!\n");
            break;
        case 2:
            printf("Moon Korg, here we come!\n");
            break;
        case 3:
            printf("Asteroid Belt, let's hope we don't crash!\n");
            break;
        default:
            printf("Sorry, I didn't understand that. Let's try again.\n");
            navigate();
    }
}

void interact() {
    printf("Captain, someone is trying to contact us.\n");
    printf("1. Answer the transmission.\n");
    printf("2. Ignore the transmission.\n");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Greetings, this is Captain %s of the SS Enterprise.\n", getenv("USER"));
        printf("Who am I speaking with?\n");
        printf("...\n");
        printf("Captain, there's no response.\n");
        printf("1. Try to establish communication again.\n");
        printf("2. End the transmission.\n");

        int subChoice;
        scanf("%d", &subChoice);

        if(subChoice == 1) {
            printf("Attempting to communicate again.\n");
            interact();
        } else if(subChoice == 2) {
            printf("Ending transmission.\n");
        } else {
            printf("Sorry, I didn't understand that. Let's try again.\n");
            interact();
        }
    } else if(choice == 2) {
        printf("Ignoring transmission.\n");
    } else {
        printf("Sorry, I didn't understand that. Let's try again.\n");
        interact();
    }
}

void battle() {
    printf("Captain, we're being attacked!\n");
    printf("1. Return fire.\n");
    printf("2. Try to flee.\n");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Engaging enemy.\n");
        srand(time(NULL));
        int enemyHP = 10 + rand() % 20;
        while(enemyHP > 0) {
            int damage = 5 + rand() % 10;
            enemyHP -= damage;
            printf("Enemy takes %d damage. Enemy health: %d\n", damage, enemyHP);
        }
        printf("Enemy destroyed. Good job, crew!\n");
    } else if(choice == 2) {
        printf("Initiating evasive maneuvers.\n");
    } else {
        printf("Sorry, I didn't understand that. Let's try again.\n");
        battle();
    }
}

int main() {
    printf("Welcome aboard the SS Enterprise, Captain %s.\n", getenv("USER"));
    printf("Initializing systems...\n");
    printf("Systems online. All systems nominal.\n");
    printf("Captain, what is our mission for today?\n");
    printf("1. Explore a new planet.\n");
    printf("2. Investigate a transmission.\n");
    printf("3. Battle enemy forces.\n");

    int choice;

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            navigate();
            printf("Mission complete. Returning to base.\n");
            break;
        case 2:
            interact();
            printf("Mission complete. Returning to base.\n");
            break;
        case 3:
            battle();
            printf("Mission complete. Returning to base.\n");
            break;
        default:
            printf("Invalid choice. Mission aborted.\n");
            break;
    }

    return 0;
}