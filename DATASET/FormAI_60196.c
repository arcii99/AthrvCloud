//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int magic;
    int potion;
} Character;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Monster;

void delay(unsigned int ms) {
    clock_t goal = ms + clock();
    while(goal > clock());
}

void clear() {
    system("clear || cls");
}

void intro() {
    printf("\n\n");
    printf(" _______  _______  _        _______  _______           \n");
    printf("(  ____ )(  ___  )( (    /|(  ____ )(  ____ )|\\     /|\n");
    printf("| (    )|| (   ) ||  \\  ( || (    )|| (    )|( \\   / )\n");
    printf("| (____)|| (___) ||   \\ | || (____)|| (____)| \\ (_) / \n");
    printf("|  _____)|  ___  || (\\ \\) ||     __)|     __)  \\   /  \n");
    printf("| (      | (   ) || | \\   || (\\ (   | (\\ (      ) (   \n");
    printf("| )      | )   ( || )  \\  || ) \\ \\__| ) \\ \\__   | |   \n");
    printf("|/       |/     \\||/    )_)|/   \\__/|/   \\__/   \\_/   \n");
    printf("\n");
    printf("\t\t\t\tBy: Your Name\n\n");
}

void menu(Character player) {
    printf("\n\n");
    printf("Welcome %s\n\n", player.name);
    printf("Health: %d\tAttack: %d\tDefense: %d\tMagic:%d\tPotion:%d\n\n", player.health, player.attack, player.defense, player.magic, player.potion);
    printf("1. Play\n");
    printf("2. Save\n");
    printf("3. Load\n");
    printf("4. Quit\n\n");
    printf("Enter your choice: ");
}

void save(Character player) {
    FILE *fp;
    fp = fopen("save.txt", "w");

    if(fp == NULL) {
        printf("Error: could not open save file.\n");
    } else {
        fprintf(fp, "%s\n%d\n%d\n%d\n%d\n%d\n", player.name, player.health, player.attack, player.defense, player.magic, player.potion);
        fclose(fp);
        printf("\nSaved game successfully!\n");
    }
}

void load(Character *player) {
    FILE *fp;
    fp = fopen("save.txt", "r");

    if(fp == NULL) {
        printf("Error: could not open save file.\n");
    } else {
        fscanf(fp, "%s\n%d\n%d\n%d\n%d\n%d\n", (*player).name, &(*player).health, &(*player).attack, &(*player).defense, &(*player).magic, &(*player).potion);
        fclose(fp);
        printf("\nLoaded game successfully!\n");
    }
}

void battle(Character *player, Monster *monster) {
    clear();
    printf("%s appeared!\n\n", (*monster).name);
    delay(2000);

    while((*player).health > 0 && (*monster).health > 0) {
        clear();
        printf("%s\n\n", (*monster).name);
        printf("Health: %d\n", (*monster).health);
        printf("Attack: %d\n", (*monster).attack);
        printf("Defense: %d\n\n", (*monster).defense);
        printf("%s\n\n", (*player).name);
        printf("Health: %d\n", (*player).health);
        printf("Attack: %d\n", (*player).attack);
        printf("Defense: %d\n", (*player).defense);
        printf("Potion: %d\n\n", (*player).potion);

        int choice;
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Cast Magic\n");
        printf("4. Use Potion\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Attack
                (*monster).health -= (*player).attack;
                printf("\nYou dealt %d damage!\n", (*player).attack);
                delay(1000);
                (*player).health -= (*monster).attack;
                printf("%s dealt %d damage!\n", (*monster).name, (*monster).attack);
                delay(1000);
                break;
            case 2: // Defend
                (*player).defense += 2;
                printf("\nYou are defending!\n");
                delay(1000);
                (*player).health -= ((*monster).attack / ((*player).defense / 2));
                printf("%s dealt %d damage!\n", (*monster).name, ((*monster).attack / ((*player).defense / 2)));
                delay(1000);
                (*player).defense -= 2;
                break;
            case 3: // Cast Magic
                if((*player).magic < 5) {
                    printf("\nYou do not have enough magic!\n");
                    delay(1000);
                    break;
                } else {
                    (*player).magic -= 5;
                    (*monster).health -= (*player).magic;
                    printf("\nYou dealt %d magic damage!\n", (*player).magic);
                    delay(1000);
                    (*player).health -= (*monster).attack;
                    printf("%s dealt %d damage!\n", (*monster).name, (*monster).attack);
                    delay(1000);
                    break;
                }
            case 4: // Use Potion
                if((*player).potion < 1) {
                    printf("\nYou do not have any potions!\n");
                    delay(1000);
                    break;
                } else {
                    (*player).health += 10;
                    (*player).potion--;
                    printf("\nYou used a potion and gained 10 health!\n");
                    delay(1000);
                    (*player).health -= ((*monster).attack / (*player).defense);
                    printf("%s dealt %d damage!\n", (*monster).name, ((*monster).attack / (*player).defense));
                    delay(1000);
                    break;
                }
            default:
                printf("\nInvalid choice, try again!\n");
                delay(1000);
                break;
        }

        if((*monster).health <= 0) {
            printf("\nYou defeated %s!\n", (*monster).name);
            printf("You gained 25 experience and 5 gold!\n");
            delay(2000);
            (*player).health = 100;
            (*player).potion += 1;
            return;
        } else if((*player).health <= 0) {
            printf("\nYou were defeated by %s!\n", (*monster).name);
            delay(2000);
            exit(0);
        }
    }
}

void play(Character *player) {
    Monster a = {"Goblin", 50, 10, 5};
    Monster b = {"Skeleton", 75, 15, 10};
    Monster c = {"Troll", 100, 20, 15};
    Monster d = {"Dragon", 200, 50, 30};

    printf("\n\n");
    printf("Welcome to the world of adventure, %s! You find yourself in a dark and unfamiliar forest.\n", (*player).name);
    delay(5000);
    printf("Be on your guard as danger lurks around every corner. You have been equipped with a sword to defend yourself.\n");
    delay(5000);
    printf("Your quest is to defeat the creatures of the forest and uncover the secrets of this ancient land.\n");
    delay(5000);
    printf("Good luck, adventurer!\n\n");
    delay(2000);

    while(1) {
        clear();
        int choice;
        printf("Choose your next move, %s\n\n", (*player).name);
        printf("1. Fight Goblin\n");
        printf("2. Fight Skeleton\n");
        printf("3. Fight Troll\n");
        printf("4. Fight Dragon\n");
        printf("5. Return to town\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Fight Goblin
                battle(player, &a);
                break;
            case 2: // Fight Skeleton
                if((*player).health < 50) {
                    printf("\nYou do not have enough health to fight the Skeleton!\n");
                    delay(2000);
                    break;
                } else {
                    battle(player, &b);
                    break;
                }
            case 3: // Fight Troll
                if((*player).potion < 1) {
                    printf("\nYou do not have any potions to fight the Troll!\n");
                    delay(2000);
                    break;
                } else {
                    battle(player, &c);
                    break;
                }
            case 4: // Fight Dragon
                if((*player).magic < 10) {
                    printf("\nYou do not have enough magic to fight the Dragon!\n");
                    delay(2000);
                    break;
                } else {
                    battle(player, &d);
                    break;
                }
            case 5: // Return to town
                printf("\nYou returned to town and lived the rest of your days as a hero.\n");
                delay(2000);
                exit(0);
            default:
                printf("\nInvalid choice, try again!\n");
                delay(1000);
                break;
        }
    }
}

int main() {
    clear();
    intro();

    Character player;
    printf("Enter your name: ");
    scanf("%s", player.name);
    player.health = 100;
    player.attack = 25;
    player.defense = 10;
    player.magic = 0;
    player.potion = 0;

    while(1) {
        clear();
        menu(player);

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Play
                play(&player);
                break;
            case 2: // Save
                save(player);
                delay(2000);
                break;
            case 3: // Load
                load(&player);
                delay(2000);
                break;
            case 4: // Quit
                printf("\nGoodbye %s!\n", player.name);
                delay(2000);
                exit(0);
            default:
                printf("\nInvalid choice, try again!\n");
                delay(1000);
                break;
        }
    }

    return 0;
}