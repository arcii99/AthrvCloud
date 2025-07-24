//FormAI DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct weapon {
    char name[50];
    int damage;
};

struct armor {
    char name[50];
    int defense;
};

struct unit {
    char name[50];
    int health;
    int num_weapons;
    struct weapon *weapons;
    struct armor *armor;
};

void initialize_weapons(struct weapon *w1, struct weapon *w2, struct weapon *w3) {
    // sword
    strcpy(w1->name, "Sword of the Dragon Slayer");
    w1->damage = 50;
    // mace
    strcpy(w2->name, "Mace of the Ogre Crusher");
    w2->damage = 35;
    // bow
    strcpy(w3->name, "Bow of the Elven Archer");
    w3->damage = 45;
}

void initialize_armor(struct armor *a1, struct armor *a2, struct armor *a3) {
    // plate armor
    strcpy(a1->name, "Platinum Plate Armor");
    a1->defense = 40;
    // chainmail
    strcpy(a2->name, "Chainmail of the Crusader");
    a2->defense = 30;
    // leather armor
    strcpy(a3->name, "Leather Armor of the Hunter");
    a3->defense = 20;
}

void add_unit(struct unit *u, char name[], int health, struct weapon *weapons, struct armor *armor, int num_weapons) {
    strcpy(u->name, name);
    u->health = health;
    u->num_weapons = num_weapons;
    u->weapons = weapons;
    u->armor = armor;
}

void print_weapons(struct weapon *weapons, int num_weapons) {
    printf("Weapons: \n");
    for (int i = 0; i < num_weapons; i++) {
        printf("Name: %s\nDamage: %d\n", weapons[i].name, weapons[i].damage);
    }
}

void print_armor(struct armor *armor) {
    printf("Armor:\nName: %s\nDefense: %d\n", armor->name, armor->defense);
}

void print_unit(struct unit *unit) {
    printf("Name: %s\nHealth: %d\n", unit->name, unit->health);
    print_weapons(unit->weapons, unit->num_weapons);
    print_armor(unit->armor);
}

int main() {
    struct weapon w1, w2, w3;
    initialize_weapons(&w1, &w2, &w3);

    struct armor a1, a2, a3;
    initialize_armor(&a1, &a2, &a3);

    struct unit u1, u2, u3;
    add_unit(&u1, "Warrior of Thor", 100, &w1, &a1, 1);
    add_unit(&u2, "Knight of the Land", 150, &w2, &a2, 1);
    add_unit(&u3, "Ranger of the Woodland", 120, &w3, &a3, 1);

    printf("Unit 1:\n");
    print_unit(&u1);
    printf("\nUnit 2:\n");
    print_unit(&u2);
    printf("\nUnit 3:\n");
    print_unit(&u3);

    return 0;
}