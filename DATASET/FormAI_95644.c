//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id;
   char name[50];
   char email[50];
} Person;

Person* create_person(int id, char* name, char* email) {
    Person* person = malloc(sizeof(Person));
    person->id = id;
    strcpy(person->name, name);
    strcpy(person->email, email);
    return person;
}

void print_person(Person* person) {
    printf("ID: %d\n", person->id);
    printf("Name: %s\n", person->name);
    printf("Email: %s\n", person->email);
}

typedef struct {
    char* key;
    int value;
} Index;

Index* create_index(char* key, int value) {
    Index* index = malloc(sizeof(Index));
    index->key = malloc(strlen(key)+1);
    strcpy(index->key, key);
    index->value = value;
    return index;
}

void print_index(Index* index) {
    printf("Key: %s\n", index->key);
    printf("Value: %d\n", index->value);
}

typedef struct {
    Person** data;
    int size;
    Index** indexes;
    int num_indexes;
} Database;

Database* create_database(int size) {
    Database* db = malloc(sizeof(Database));
    db->data = malloc(sizeof(Person*) * size);
    db->size = size;
    db->indexes = malloc(sizeof(Index*) * size);
    db->num_indexes = 0;
    return db;
}

void insert_person(Database* db, Person* person) {
    if(db->num_indexes > 0) {
        for(int i = 0; i < db->num_indexes; i++) {
            Index* index = db->indexes[i];
            if(strcmp(index->key, person->email) == 0) {
                printf("Error: Email already exists.\n");
                return;
            }
        }
    }
    for(int i = 0; i < db->size; i++) {
        if(db->data[i] == NULL) {
            db->data[i] = person;
            return;
        }
    }
    printf("Error: Database is full.\n");
}

void create_index_for_database(Database* db, char* key) {
    if(db->num_indexes == db->size) {
        printf("Error: Maximum number of indexes exceeded.\n");
        return;
    }
    for(int i = 0; i < db->num_indexes; i++) {
        Index* index = db->indexes[i];
        if(strcmp(index->key, key) == 0) {
            printf("Error: Index already exists.\n");
            return;
        }
    }
    Index* index = create_index(key, db->num_indexes);
    db->indexes[db->num_indexes] = index;
    db->num_indexes++;
    for(int i = 0; i < db->size; i++) {
        if(db->data[i] != NULL) {
            if(strcmp(key, "id") == 0) {
                index->value = db->data[i]->id;
            } else if(strcmp(key, "name") == 0) {
                strcpy(index->key, db->data[i]->name);
            } else if(strcmp(key, "email") == 0) {
                strcpy(index->key, db->data[i]->email);
            }
        }
    }
}

Database* load_database(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found.\n");
        return NULL;
    }
    int size;
    fscanf(fp, "%d", &size);
    Database* db = create_database(size);
    for(int i = 0; i < size; i++) {
        int id;
        char name[50];
        char email[50];
        fscanf(fp, "%d,%[^,],%s\n", &id, name, email);
        Person* person = create_person(id, name, email);
        insert_person(db, person);
    }
    fclose(fp);
    return db;
}

void save_database(Database* db, char* filename) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Could not create file.\n");
        return;
    }
    fprintf(fp, "%d\n", db->size);
    for(int i = 0; i < db->size; i++) {
        if(db->data[i] != NULL) {
            fprintf(fp, "%d,%s,%s\n", db->data[i]->id, db->data[i]->name, db->data[i]->email);
        }
    }
    fclose(fp);
}

void search_database_for(Database* db, char* key, char* value) {
    int found = 0;
    for(int i = 0; i < db->size; i++) {
        if(db->data[i] != NULL) {
            if(strcmp(key, "id") == 0) {
                if(db->data[i]->id == atoi(value)) {
                    print_person(db->data[i]);
                    found = 1;
                }
            } else if(strcmp(key, "name") == 0) {
                if(strcmp(db->data[i]->name, value) == 0) {
                    print_person(db->data[i]);
                    found = 1;
                }
            } else if(strcmp(key, "email") == 0) {
                if(strcmp(db->data[i]->email, value) == 0) {
                    print_person(db->data[i]);
                    found = 1;
                }
            }
        }
    }
    if(!found) {
        printf("No results.\n");
    }
}

void print_all_records(Database* db) {
    for(int i = 0; i < db->size; i++) {
        if(db->data[i] != NULL) {
            print_person(db->data[i]);
        }
    }
}

void print_all_indexes(Database* db) {
    for(int i = 0; i < db->num_indexes; i++) {
        print_index(db->indexes[i]);
    }
}

int main() {
    Database* db = create_database(10);
    create_index_for_database(db, "email");
    Person* p1 = create_person(1, "John", "john@example.com");
    insert_person(db, p1);
    Person* p2 = create_person(2, "Jane", "jane@example.com");
    insert_person(db, p2);
    Person* p3 = create_person(3, "Bob", "bob@example.com");
    insert_person(db, p3);
    Person* p4 = create_person(4, "Alice", "alice@example.com");
    insert_person(db, p4);
    printf("Searching for person with email alice@example.com:\n");
    search_database_for(db, "email", "alice@example.com");
    printf("\nPrinting all records:\n");
    print_all_records(db);
    printf("\nCreating a name index:\n");
    create_index_for_database(db, "name");
    printf("\nPrinting all indexes:\n");
    print_all_indexes(db);
    save_database(db, "test.txt");
    printf("\nDatabase saved to test.txt\n");
    Database* db2 = load_database("test.txt");
    printf("\nDatabase loaded from test.txt, printing all records:\n");
    print_all_records(db2);
    return 0;
}