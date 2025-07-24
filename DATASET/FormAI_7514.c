//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function prototypes
void initialize();
void displayIntro();
void choiceOne();
void choiceTwo();
void choiceThree();
void choiceFour();
void choiceFive();
void choiceSix();
void endGame();

// global variables
int health = 100;
char planet[20];
char enemy[20];
int enemyHealth;
int item = 0;

int main() {
    srand(time(NULL));
    initialize();
    displayIntro();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            choiceOne();
            break;
        case 2:
            choiceTwo();
            break;
        case 3:
            choiceThree();
            break;
        case 4:
            choiceFour();
            break;
        case 5:
            choiceFive();
            break;
        case 6:
            choiceSix();
            break;
        default:
            printf("Invalid Choice! Please try again.\n");
            main();
    }
    return 0;
}

void initialize() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    char name[10];
    scanf("%s", name);
    printf("\nHello, %s! Your mission is to explore the space and collect valuable items.\n", name);
    printf("You have been given a spaceship with full fuel.\n");
}

void displayIntro() {
    printf("\n**************************************************************\n");
    printf("Choose your adventure: \n");
    printf("\t1. Explore the nearest planet\n");
    printf("\t2. Fight the enemy spaceship\n");
    printf("\t3. Travel long distances to find rare resources\n");
    printf("\t4. Search for abandoned ships\n");
    printf("\t5. Trade resources with other planets\n");
    printf("\t6. Quit the game\n");
    printf("**************************************************************\n\n");
}

void choiceOne() {
    printf("You have chosen to explore the nearest planet. Buckle up and prepare for landing!\n");
    int oxygen = rand() % 50 + 50;
    int mineral = rand() % 3;
    switch(mineral) {
        case 0:
            item = 1;
            strcpy(planet, "Mars");
            printf("You have found a valuable mineral on %s. You now have %d health and %d oxygen.\n", planet, health, oxygen);
            break;
        case 1:
            item = 2;
            strcpy(planet, "Venus");
            printf("You have found a rare resource on %s. You now have %d health and %d oxygen.\n", planet, health, oxygen);
            break;
        case 2:
            item = 3;
            strcpy(planet, "Mercury");
            printf("You have found a precious metal on %s. You now have %d health and %d oxygen.\n", planet, health, oxygen);
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
    displayIntro();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            choiceOne();
            break;
        case 2:
            choiceTwo();
            break;
        case 3:
            choiceThree();
            break;
        case 4:
            choiceFour();
            break;
        case 5:
            choiceFive();
            break;
        case 6:
            endGame();
            break;
        default:
            printf("Invalid Choice! Please try again.\n");
            choiceOne();
    }
}

void choiceTwo() {
    printf("You have chosen to fight the enemy spaceship. Brace yourself!\n");
    int enemyLevel = rand() % 5 + 1;
    switch(enemyLevel) {
        case 1:
            enemyHealth = 50;
            strcpy(enemy, "Small enemy spaceship");
            break;
        case 2:
            enemyHealth = 70;
            strcpy(enemy, "Average enemy spaceship");
            break;
        case 3:
            enemyHealth = 90;
            strcpy(enemy, "Big enemy spaceship");
            break;
        case 4:
            enemyHealth = 110;
            strcpy(enemy, "Giant enemy spaceship");
            break;
        case 5:
            enemyHealth = 130;
            strcpy(enemy, "Legendary enemy spaceship");
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
    int playerDamage = rand() % 20 + 10;
    int enemyDamage = rand() % 20 + 5;
    printf("You are facing a %s with %d health.\n", enemy, enemyHealth);
    while(health > 0 && enemyHealth > 0) {
        int hit = rand() % 2;
        if(hit == 0) {
            enemyHealth -= playerDamage;
            printf("You hit the %s and dealt %d damage. It now has %d health left.\n", enemy, playerDamage, enemyHealth);
        } else {
            health -= enemyDamage;
            printf("The %s hit you and dealt %d damage. You now have %d health left.\n", enemy, enemyDamage, health);
        }
    }
    if(health > 0) {
        printf("You have defeated the %s. You now have %d health left.\n", enemy, health);
        displayIntro();
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                choiceOne();
                break;
            case 2:
                choiceTwo();
                break;
            case 3:
                choiceThree();
                break;
            case 4:
                choiceFour();
                break;
            case 5:
                choiceFive();
                break;
            case 6:
                endGame();
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
                choiceTwo();
        }
    } else {
        printf("You have lost the battle! GAME OVER\n");
        endGame();
    }
}

void choiceThree() {
    printf("You have chosen to travel long distances to find rare resources. Good Luck!\n");
    int fuel1 = rand() % 50 + 50;
    int fuel2 = rand() % 50 + 50;
    int mineral1 = rand() % 3;
    int mineral2 = rand() % 3;
    switch(mineral1) {
        case 0:
            item = 1;
            printf("You found a valuable mineral\n");
            break;
        case 1:
            item = 2;
            printf("You found a rare resource\n");
            break;
        case 2:
            item = 3;
            printf("You found a precious metal\n");
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
    printf("You used %d fuel to travel to the first location. You now have %d fuel and %d health.\n", fuel1, fuel2, health);
    switch(mineral2) {
        case 0:
            item = 1;
            printf("You found a valuable mineral\n");
            break;
        case 1:
            item = 2;
            printf("You found a rare resource\n");
            break;
        case 2:
            item = 3;
            printf("You found a precious metal\n");
            break;
        default:
            printf("Something went wrong!\n");
            break;
    }
    printf("You used %d fuel to travel to the second location. You now have %d fuel and %d health.\n", fuel2, 0, health);
    displayIntro();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            choiceOne();
            break;
        case 2:
            choiceTwo();
            break;
        case 3:
            choiceThree();
            break;
        case 4:
            choiceFour();
            break;
        case 5:
            choiceFive();
            break;
        case 6:
            endGame();
            break;
        default:
            printf("Invalid Choice! Please try again.\n");
            choiceThree();
    }
}

void choiceFour() {
    printf("You have chosen to search for abandoned ships. Be careful!\n");
    int abandoned = rand() % 2;
    if(abandoned == 1) {
        printf("You have found an abandoned spaceship with valuable items!\n");
        int healthBonus = rand() % 20 + 10;
        int fuelBonus = rand() % 20 + 10;
        int itemBonus = rand() % 2 + 1;
        health += healthBonus;
        fuelBonus += fuelBonus;
        switch(itemBonus) {
            case 1:
                item = 2;
                printf("You have found a rare resource. You now have %d health, %d fuel and the rare resource.\n", health, fuelBonus, item);
                break;
            case 2:
                item = 3;
                printf("You have found a precious metal. You now have %d health, %d fuel and the precious metal.\n", health, fuelBonus, item);
                break;
            default:
                printf("Something went wrong!\n");
                break;
        }
    } else {
        printf("You did not find anything valuable. You now have %d health and full fuel.\n", health);
    }
    displayIntro();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            choiceOne();
            break;
        case 2:
            choiceTwo();
            break;
        case 3:
            choiceThree();
            break;
        case 4:
            choiceFour();
            break;
        case 5:
            choiceFive();
            break;
        case 6:
            endGame();
            break;
        default:
            printf("Invalid Choice! Please try again.\n");
            choiceFour();
    }
}

void choiceFive() {
    printf("You have chosen to trade resources with other planets. This could be risky!\n");
    int friendliness = rand() % 10 + 1;
    int itemPrice = rand() % 100 + 1;
    int trade = rand() % 2;
    if(friendliness <= 5) {
        printf("The planet is not friendly. They do not want to trade with you.\n");
    } else {
        if(trade == 1) {
            printf("You have successfully traded your %d item for %d units of fuel.\n", item, itemPrice);
            health -= 10;
        } else {
            printf("The trade did not go well. You lost your %d item.\n", item);
            health -= 20;
        }
        item = 0;
    }
    printf("You now have %d health and full fuel.\n", health);
    displayIntro();
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            choiceOne();
            break;
        case 2:
            choiceTwo();
            break;
        case 3:
            choiceThree();
            break;
        case 4:
            choiceFour();
            break;
        case 5:
            choiceFive();
            break;
        case 6:
            endGame();
            break;
        default:
            printf("Invalid Choice! Please try again.\n");
            choiceFive();
    }
}

void choiceSix() {
    printf("Thank you for playing Procedural Space Adventure! Goodbye :)\n");
}

void endGame() {
    printf("GAME OVER\n");
    main();
}