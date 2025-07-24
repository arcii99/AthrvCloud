//FormAI DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

int main() {
    User u1 = {1, "John Smith", "john.smith@email.com"};
    User u2 = {2, "Jane Doe", "jane.doe@email.com"};
    
    // Writing to the database file
    FILE *db = fopen("users.db", "wb");
    fwrite(&u1, sizeof(User), 1, db);
    fwrite(&u2, sizeof(User), 1, db);
    fclose(db);

    // Reading from the database file
    db = fopen("users.db", "rb");
    if (db == NULL) {
        printf("Error: could not open database file!\n");
        exit(EXIT_FAILURE);
    }

    User read_user;
    fread(&read_user, sizeof(User), 1, db);
    while (!feof(db)) {
        printf("%d %s %s\n", read_user.id, read_user.name, read_user.email);
        fread(&read_user, sizeof(User), 1, db);
    }

    fclose(db);
    return 0;
}