//FormAI DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
  int id;
  char* name;
  int age;
  char* address;
  char* email;
} User;

void printUser(User u) {
  printf("ID: %d\nName: %s\nAge: %d\nAddress: %s\nEmail: %s\n\n", u.id, u.name, u.age, u.address, u.email);
}

int queryCallback(void* data, int argc, char** argv, char** columns) {
  User* u = (User*) data;

  u->id = atoi(argv[0]);
  u->name = argv[1];
  u->age = atoi(argv[2]);
  u->address = argv[3];
  u->email = argv[4];

  return 0;
}

int main() {
  sqlite3* db;
  char* err;
  int rc = sqlite3_open("mydb.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return EXIT_FAILURE;
  }

  char* query = "SELECT * FROM Users WHERE id = 1;";
  User u = { 0 };

  rc = sqlite3_exec(db, query, queryCallback, &u, &err);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error querying database: %s\n", err);
    sqlite3_free(err);
    sqlite3_close(db);
    return EXIT_FAILURE;
  }

  printUser(u);

  sqlite3_close(db);
  return EXIT_SUCCESS;
}