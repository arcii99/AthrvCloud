//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 500
#define MAX_NAME_LENGTH 20
#define MAX_DESC_LENGTH 50

typedef struct _item {
  int id;
  char name[MAX_NAME_LENGTH];
  char desc[MAX_DESC_LENGTH];
  int quantity;
} item;

typedef struct _database {
  item items[MAX_DB_SIZE];
  int num_items;
} database;

void print_menu();
void print_items(database db);
void add_item(database *db);
void remove_item(database *db, int id);
void search_item(database db, char query[]);
void update_item(database *db, int id);

int main() {
  database db;
  db.num_items = 0;

  int choice;
  do {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        print_items(db);
        break;

      case 2:
        add_item(&db);
        break;

      case 3: {
        int id;
        printf("Enter item ID: ");
        scanf("%d", &id);
        remove_item(&db, id);
        break;
      }

      case 4: {
        char query[MAX_NAME_LENGTH];
        printf("Enter search query: ");
        scanf("%s", query);
        search_item(db, query);
        break;
      }

      case 5: {
        int id;
        printf("Enter item ID: ");
        scanf("%d", &id);
        update_item(&db, id);
        break;
      }

      case 6:
        break;

      default:
        printf("Invalid Choice!\n");
        break;
    }
  } while (choice != 6);

  printf("Goodbye!\n");

  return 0;
}

void print_menu() {
  printf("\n");
  printf("1. List items\n");
  printf("2. Add item\n");
  printf("3. Remove item\n");
  printf("4. Search item\n");
  printf("5. Update item\n");
  printf("6. Exit\n");
  printf("Enter your choice: ");
}

void print_items(database db) {
  printf("\n");
  printf("ID\tName\tQuantity\tDescription\n");
  printf("---------------------------------------------------------\n");

  if (db.num_items == 0) {
    printf("No Items Found!\n");
    return;
  }

  for (int i = 0; i < db.num_items; i++) {
    printf("%d\t%s\t%d\t%s\n", db.items[i].id, db.items[i].name,
           db.items[i].quantity, db.items[i].desc);
  }
}

void add_item(database *db) {
  printf("Enter item name: ");
  scanf("%s", db->items[db->num_items].name);

  printf("Enter item description: ");
  scanf("%s", db->items[db->num_items].desc);

  printf("Enter item quantity: ");
  scanf("%d", &db->items[db->num_items].quantity);

  db->items[db->num_items].id = db->num_items + 1;

  db->num_items++;
}

void remove_item(database *db, int id) {
  int index = -1;
  for (int i = 0; i < db->num_items; i++) {
    if (db->items[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Item not found!\n");
    return;
  }

  for (int i = index; i < db->num_items - 1; i++) {
    strcpy(db->items[i].name, db->items[i + 1].name);
    strcpy(db->items[i].desc, db->items[i + 1].desc);
    db->items[i].quantity = db->items[i + 1].quantity;
    db->items[i].id = db->items[i + 1].id;
  }

  db->num_items--;
  printf("Item removed successfully!\n");
}

void search_item(database db, char query[]) {
  printf("\n");
  printf("ID\tName\tQuantity\tDescription\n");
  printf("---------------------------------------------------------\n");

  int num_matches = 0;
  for (int i = 0; i < db.num_items; i++) {
    if (strstr(db.items[i].name, query) != NULL ||
        strstr(db.items[i].desc, query) != NULL) {
      printf("%d\t%s\t%d\t%s\n", db.items[i].id, db.items[i].name,
             db.items[i].quantity, db.items[i].desc);
      num_matches++;
    }
  }

  if (num_matches == 0) {
    printf("No Matches Found!\n");
  }
}

void update_item(database *db, int id) {
  int index = -1;
  for (int i = 0; i < db->num_items; i++) {
    if (db->items[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Item not found!\n");
    return;
  }

  printf("Enter new item name: ");
  scanf("%s", db->items[index].name);

  printf("Enter new item description: ");
  scanf("%s", db->items[index].desc);

  printf("Enter new item quantity: ");
  scanf("%d", &db->items[index].quantity);

  printf("Item updated successfully!\n");
}