//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_COMMANDS 10

typedef struct user {
    char name[20];
    int age;
    int hunger;
    int thirst;
    int morale;
    int strength;
    int intelligence;
} User;

typedef struct command {
    char name[20];
    void (*execute)(User*);
} Command;

User users[MAX_USERS];
Command commands[MAX_COMMANDS];

void initialize_users() {
    for (int i = 0; i < MAX_USERS; i++) {
        User u;
        sprintf(u.name, "User %d", i+1);
        u.age = rand() % 50 + 16;
        u.hunger = rand() % 100;
        u.thirst = rand() % 100;
        u.morale = rand() % 100;
        u.strength = rand() % 100;
        u.intelligence = rand() % 100;
        users[i] = u;
    }
}

void print_user(User* u) {
    printf("Name: %s\n", u->name);
    printf("Age: %d\n", u->age);
    printf("Hunger: %d\n", u->hunger);
    printf("Thirst: %d\n", u->thirst);
    printf("Morale: %d\n", u->morale);
    printf("Strength: %d\n", u->strength);
    printf("Intelligence: %d\n", u->intelligence);
    printf("\n");
}

void status(User* user) {
    printf("===== STATUS =====\n\n");
    print_user(user);
}

void feed(User* user) {
    printf("You found some canned beans and water.\n");
    user->hunger += 25;
    user->thirst += 50;
    user->morale += 10;
    printf("Your hunger is now %d.\n", user->hunger);
    printf("Your thirst is now %d.\n", user->thirst);
    printf("Your morale is now %d.\n", user->morale);
}

void scavenge(User* user) {
    printf("You found a gun and some bullets.\n");
    user->strength += 5;
    user->intelligence += 5;
    user->morale += 10;
    printf("Your strength is now %d.\n", user->strength);
    printf("Your intelligence is now %d.\n", user->intelligence);
    printf("Your morale is now %d.\n", user->morale);
}

void rest(User* user) {
    printf("You found a safe spot to rest for a while.\n");
    user->morale += 20;
    printf("Your morale is now %d.\n", user->morale);
}

void setup_commands() {
    Command cmd1;
    strcpy(cmd1.name, "status");
    cmd1.execute = status;
    commands[0] = cmd1;

    Command cmd2;
    strcpy(cmd2.name, "feed");
    cmd2.execute = feed;
    commands[1] = cmd2;

    Command cmd3;
    strcpy(cmd3.name, "scavenge");
    cmd3.execute = scavenge;
    commands[2] = cmd3;

    Command cmd4;
    strcpy(cmd4.name, "rest");
    cmd4.execute = rest;
    commands[3] = cmd4;
}

int get_user_input(char* buf, int buf_size) {
    printf("> ");
    fgets(buf, buf_size, stdin);
    int len = strlen(buf);
    if (buf[len-1] == '\n') {
        buf[len-1] = '\0';
        len--;
    }
    return len;
}

void execute_command(User* cur_user, char* command_name) {
    for (int i = 0; i < MAX_COMMANDS; i++) {
        if (strcmp(command_name, commands[i].name) == 0) {
            (*commands[i].execute)(cur_user);
            return;
        }
    }
    printf("Unknown command: %s\n", command_name);
}

int main() {
    srand(time(NULL));

    initialize_users();
    setup_commands();

    User cur_user = users[rand() % MAX_USERS];
    printf("Welcome to the post-apocalyptic system console, %s.\n", cur_user.name);

    while (1) {
        char buf[50];
        int len = get_user_input(buf, sizeof(buf));
        if (len > 0) {
            execute_command(&cur_user, buf);
        }
    }

    return 0;
}