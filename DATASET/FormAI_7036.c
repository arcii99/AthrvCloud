//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void introduction();
void game_start();
void room1();
void room2();
void room3();
void room4();
void victory();

int main() {
    introduction();
    game_start();
    return 0;
}

void introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a young adventurer on a mission to find the legendary treasure hidden deep in the forest.\n");
    printf("Your goal is to navigate through four rooms, each with its own unique challenges and obstacles.\n");
    printf("Good luck on your adventure!\n");
}

void game_start() {
    printf("\nYou find yourself at the entrance of the forest. There are four paths in front of you.\n");
    printf("Which path do you choose?\n");
    printf("1. Path of the Mage\n");
    printf("2. Path of the Warrior\n");
    printf("3. Path of the Rogue\n");
    printf("4. Path of the Monk\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nYou have chosen the Path of the Mage. Good choice!\n");
            room1();
            break;
        case 2:
            printf("\nYou have chosen the Path of the Warrior. Fight well!\n");
            room1();
            break;
        case 3:
            printf("\nYou have chosen the Path of the Rogue. Sneaky choice!\n");
            room1();
            break;
        case 4:
            printf("\nYou have chosen the Path of the Monk. Peaceful choice!\n");
            room1();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            game_start();
            break;
    }
}

void room1() {
    printf("\nYou enter the first room, and see a chest in the center of the room.\n");
    printf("Do you open the chest?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\nThe chest is locked. You need to find a key.\n");
        printf("You notice a key-shaped hole in the wall.\n");
        printf("Do you approach the wall?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        int choice2;
        scanf("%d", &choice2);
        if (choice2 == 1) {
            printf("\nYou find a loose brick in the wall, and a key falls out.\n");
            printf("You grab the key, and use it to open the chest.\n");
            printf("Inside the chest, you find a map to the next room!\n");
            room2();
        }
        else if (choice2 == 2) {
            printf("\nYou decide not to approach the wall, and look around the room.\n");
            printf("After searching for a while, you find a key under a loose floorboard.\n");
            printf("You use the key to open the chest, and find a map to the next room!\n");
            room2();
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
            room1();
        }
    }
    else if (choice == 2) {
        printf("\nYou decide not to open the chest, and look around the room.\n");
        printf("After searching for a while, you find a map to the next room!\n");
        room2();
    }
    else {
        printf("\nInvalid choice. Please try again.\n");
        room1();
    }
}

void room2() {
    printf("\nYou enter the second room, and see a puzzle on the wall.\n");
    printf("There are six symbols on the wall, and six buttons beneath them.\n");
    printf("Which symbol do you press?\n");
    printf("1. Star\n");
    printf("2. Crescent\n");
    printf("3. Triangle\n");
    printf("4. Square\n");
    printf("5. Circle\n");
    printf("6. Diamond\n");
    int answer = 2; // Random number between 1 and 6
    srand(time(0)); // Seed for random number generator
    int guess = 0;
    scanf("%d", &guess);
    if (guess == answer) {
        printf("\nYou press the correct symbol, and the puzzle unlocks!\n");
        printf("You find a map to the next room!\n");
        room3();
    }
    else {
        printf("\nYou press the wrong symbol, and the puzzle shakes.\n");
        printf("You hear a rumble, and see a boulder falling toward you!\n");
        printf("Do you:\n");
        printf("1. Try to dodge the boulder.\n");
        printf("2. Try to push the boulder out of the way.\n");
        printf("3. Let the boulder hit you, and hope for the best.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou try to dodge the boulder, but it hits you!\n");
                printf("You lose 10 health.\n");
                printf("You try again...\n");
                room2();
                break;
            case 2:
                printf("\nYou try to push the boulder out of the way, but it's too heavy!\n");
                printf("You lose 10 health.\n");
                printf("You try again...\n");
                room2();
                break;
            case 3:
                printf("\nYou let the boulder hit you, and somehow survive!\n");
                printf("You have 10 health remaining.\n");
                printf("You crawl out from under the boulder, and find a map to the next room!\n");
                room3();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                room2();
                break;
        }
    }
}

void room3() {
    printf("\nYou enter the third room, and see a monster blocking your path!\n");
    printf("The monster looks dangerous. What do you do?\n");
    printf("1. Fight the monster.\n");
    printf("2. Try to sneak past the monster.\n");
    printf("3. Bribe the monster with gold.\n");
    int choice;
    bool success = false; // Whether the action succeeds or not
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nYou decide to fight the monster!\n");
            int your_health = 50;
            int monster_health = 80;
            while (true) {
                int your_damage = rand() % 10 + 1; // Random damage between 1 and 10
                int monster_damage = rand() % 15 + 1; // Random damage between 1 and 15
                printf("You attack the monster for %d damage.\n", your_damage);
                monster_health -= your_damage;
                if (monster_health <= 0) {
                    success = true;
                    break; // Monster defeated!
                }
                printf("The monster attacks you for %d damage.\n", monster_damage);
                your_health -= monster_damage;
                if (your_health <= 0) {
                    success = false;
                    break; // You lose :(
                }
                printf("You have %d health remaining.\n", your_health);
            }
            if (success) {
                printf("\nYou defeated the monster, and find a key to the next room!\n");
                room4();
            }
            else {
                printf("\nYou were defeated by the monster.\n");
                printf("GAME OVER\n");
            }
            break;
        case 2:
            printf("\nYou try to sneak past the monster.\n");
            int sneak = rand() % 10 + 1; // Random number between 1 and 10
            if (sneak >= 7) {
                success = true;
            }
            if (success) {
                printf("\nYou successfully sneak past the monster, and find a key to the next room!\n");
                room4();
            }
            else {
                printf("\nThe monster spots you, and attacks you!\n");
                int your_health = 50;
                int monster_health = 80;
                while (true) {
                    int your_damage = rand() % 10 + 1; // Random damage between 1 and 10
                    int monster_damage = rand() % 15 + 1; // Random damage between 1 and 15
                    printf("You attack the monster for %d damage.\n", your_damage);
                    monster_health -= your_damage;
                    if (monster_health <= 0) {
                        success = true;
                        break; // Monster defeated!
                    }
                    printf("The monster attacks you for %d damage.\n", monster_damage);
                    your_health -= monster_damage;
                    if (your_health <= 0) {
                        success = false;
                        break; // You lose :(
                    }
                    printf("You have %d health remaining.\n", your_health);
                }
                if (success) {
                    printf("\nYou defeated the monster, and find a key to the next room!\n");
                    room4();
                }
                else {
                    printf("\nYou were defeated by the monster.\n");
                    printf("GAME OVER\n");
                }
            }
            break;
        case 3:
            printf("\nYou try to bribe the monster with gold.\n");
            int gold = rand() % 100 + 1; // Random amount of gold between 1 and 100
            printf("You offer the monster %d gold.\n", gold);
            if (gold >= 50) {
                success = true;
            }
            if (success) {
                printf("\nThe monster accepts your bribe, and lets you pass!\n");
                printf("You find a key to the next room!\n");
                room4();
            }
            else {
                printf("\nThe monster doesn't accept your bribe, and attacks you!\n");
                int your_health = 50;
                int monster_health = 80;
                while (true) {
                    int your_damage = rand() % 10 + 1; // Random damage between 1 and 10
                    int monster_damage = rand() % 15 + 1; // Random damage between 1 and 15
                    printf("You attack the monster for %d damage.\n", your_damage);
                    monster_health -= your_damage;
                    if (monster_health <= 0) {
                        success = true;
                        break; // Monster defeated!
                    }
                    printf("The monster attacks you for %d damage.\n", monster_damage);
                    your_health -= monster_damage;
                    if (your_health <= 0) {
                        success = false;
                        break; // You lose :(
                    }
                    printf("You have %d health remaining.\n", your_health);
                }
                if (success) {
                    printf("\nYou defeated the monster, and find a key to the next room!\n");
                    room4();
                }
                else {
                    printf("\nYou were defeated by the monster.\n");
                    printf("GAME OVER\n");
                }
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            room3();
            break;
    }
}

void room4() {
    printf("\nYou enter the fourth and final room.\n");
    printf("You see the treasure chest in front of you, but also a guardian dragon!\n");
    printf("What do you do?\n");
    printf("1. Fight the dragon.\n");
    printf("2. Try to sneak past the dragon.\n");
    printf("3. Use a special spell to freeze the dragon.\n");
    bool success = false; // Whether the action succeeds or not
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nYou decide to fight the dragon!\n");
            int your_health = 70;
            int dragon_health = 150;
            while (true) {
                int your_damage = rand() % 20 + 1; // Random damage between 1 and 20
                int dragon_damage = rand() % 25 + 1; // Random damage between 1 and 25
                printf("You attack the dragon for %d damage.\n", your_damage);
                dragon_health -= your_damage;
                if (dragon_health <= 0) {
                    success = true;
                    break; // Dragon defeated!
                }
                printf("The dragon attacks you for %d damage.\n", dragon_damage);
                your_health -= dragon_damage;
                if (your_health <= 0) {
                    success = false;
                    break; // You lose :(
                }
                printf("You have %d health remaining.\n", your_health);
            }
            if (success) {
                printf("\nYou defeated the dragon, and unlocked the treasure chest!\n");
                victory();
            }
            else {
                printf("\nYou were defeated by the dragon.\n");
                printf("GAME OVER\n");
            }
            break;
        case 2:
            printf("\nYou try to sneak past the dragon.\n");
            int sneak = rand() % 10 + 1; // Random number between 1 and 10
            if (sneak >= 9) {
                success = true;
            }
            if (success) {
                printf("\nYou successfully sneak past the dragon, and unlock the treasure chest!\n");
                victory();
            }
            else {
                printf("\nThe dragon spots you, and attacks you!\n");
                int your_health = 70;
                int dragon_health = 150;
                while (true) {
                    int your_damage = rand() % 20 + 1; // Random damage between 1 and 20
                    int dragon_damage = rand() % 25 + 1; // Random damage between 1 and 25
                    printf("You attack the dragon for %d damage.\n", your_damage);
                    dragon_health -= your_damage;
                    if (dragon_health <= 0) {
                        success = true;
                        break; // Dragon defeated!
                    }
                    printf("The dragon attacks you for %d damage.\n", dragon_damage);
                    your_health -= dragon_damage;
                    if (your_health <= 0) {
                        success = false;
                        break; // You lose :(
                    }
                    printf("You have %d health remaining.\n", your_health);
                }
                if (success) {
                    printf("\nYou defeated the dragon, and unlocked the treasure chest!\n");
                    victory();
                }
                else {
                    printf("\nYou were defeated by the dragon.\n");
                    printf("GAME OVER\n");
                }
            }
            break;
        case 3:
            printf("\nYou use a special spell to freeze the dragon!\n");
            int spell = rand() % 10 + 1; // Random number between 1 and 10
            if (spell >= 7) {
                success = true;
            }
            if (success) {
                printf("\nYou successfully freeze the dragon, and unlock the treasure chest!\n");
                victory();
            }
            else {
                printf("\nThe dragon breaks free of the ice, and attacks you!\n");
                int your_health = 70;
                int dragon_health = 150;
                while (true) {
                    int your_damage = rand() % 20 + 1; // Random damage between 1 and 20
                    int dragon_damage = rand() % 25 + 1; // Random damage between 1 and 25
                    printf("You attack the dragon for %d damage.\n", your_damage);
                    dragon_health -= your_damage;
                    if (dragon_health <= 0) {
                        success = true;
                        break; // Dragon defeated!
                    }
                    printf("The dragon attacks you for %d damage.\n", dragon_damage);
                    your_health -= dragon_damage;
                    if (your_health <= 0) {
                        success = false;
                        break; // You lose :(
                    }
                    printf("You have %d health remaining.\n", your_health);
                }
                if (success) {
                    printf("\nYou defeated the dragon, and unlocked the treasure chest!\n");
                    victory();
                }
                else {
                    printf("\nYou were defeated by the dragon.\n");
                    printf("GAME OVER\n");
                }
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            room4();
            break;
    }
}

void victory() {
    printf("\nCongratulations, you have completed the Text-Based Adventure Game!\n");
    printf("You have found the legendary treasure, and are considered a hero in the land!\n");
    printf("Thanks for playing!\n");
}