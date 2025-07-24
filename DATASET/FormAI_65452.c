//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int id;
    char name[SIZE];
    int age;
} User;

typedef struct {
    int total_users;
    User users[SIZE];
} Database;

void initialize_database(Database* db) {
    db->total_users = 0;
}

void display_users(Database* db) {
    printf("Total users in the database: %d\n", db->total_users);
    if (db->total_users == 0) {
        printf("No users found in the database.\n");
    } else {
        for (int i = 0; i < db->total_users; i++) {
            printf("User ID: %d\n", db->users[i].id);
            printf("User Name: %s\n", db->users[i].name);
            printf("User Age: %d\n", db->users[i].age);
        }
    }
}

void add_user(Database* db, int id, char* name, int age) {
    if (db->total_users == SIZE) {
        printf("The database is full and cannot add more users.\n");
    } else {
        User new_user = {id, "", age};
        for (int i = 0; name[i] != '\0'; i++) {
            new_user.name[i] = name[i];
        }
        db->users[db->total_users] = new_user;
        db->total_users++;
        printf("User added to the database successfully.\n");
    }
}

void delete_user(Database* db, int id) {
    int user_index = -1;
    for (int i = 0; i < db->total_users; i++) {
        if (db->users[i].id == id) {
            user_index = i;
            break;
        }
    }
    if (user_index == -1) {
        printf("User with ID %d does not exist in the database.\n", id);
    } else {
        for (int i = user_index; i < db->total_users - 1; i++) {
            db->users[i] = db->users[i + 1];
        }
        db->total_users--;
        printf("User with ID %d deleted from the database successfully.\n", id);
    }
}

int main() {
    Database db;
    initialize_database(&db);

    add_user(&db, 101, "John Doe", 25);
    add_user(&db, 102, "Jane Doe", 24);
    add_user(&db, 103, "David Smith", 31);

    display_users(&db);

    delete_user(&db, 102);

    display_users(&db);

    return 0;
}