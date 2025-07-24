//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Max number of elements in the database
#define MAX_ELEMENTS 100

// Example struct for storing elements in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Element;

// Struct for storing an index entry
typedef struct {
    int value;
    int index;
} IndexEntry;

// Struct for storing an index
typedef struct {
    int size;
    IndexEntry entries[MAX_ELEMENTS];
} Index;

// Helper function for sorting index entries
int compare_entries(const void *a, const void *b) {
    IndexEntry *entry_a = (IndexEntry*)a;
    IndexEntry *entry_b = (IndexEntry*)b;
    
    if (entry_a->value < entry_b->value) {
        return -1;
    } else if (entry_a->value > entry_b->value) {
        return 1;
    } else {
        return 0;
    }
}

// Helper function to print a single element
void print_element(Element e) {
    printf("(%d, %s, %d)\n", e.id, e.name, e.age);
}

// Helper function to print an array of elements
void print_elements(Element *elements, int length) {
    printf("Database:\n");
    for (int i = 0; i < length; i++) {
        print_element(elements[i]);
    }
}

// Helper function to print an index
void print_index(Index index) {
    printf("Index:\n");
    for (int i = 0; i < index.size; i++) {
        printf("[%d]: %d\n", index.entries[i].index, index.entries[i].value);
    }
}

int main() {
    // Initialize the database with some example elements
    Element database[MAX_ELEMENTS];
    int db_size = 4;
    database[0] = (Element) {1, "John", 25};
    database[1] = (Element) {2, "Jane", 30};
    database[2] = (Element) {3, "Bob", 40};
    database[3] = (Element) {4, "Alice", 35};
    print_elements(database, db_size);
    
    // Initialize an index for age
    Index age_index;
    age_index.size = db_size;
    for (int i = 0; i < db_size; i++) {
        age_index.entries[i].value = database[i].age;
        age_index.entries[i].index = i;
    }
    qsort(age_index.entries, age_index.size, sizeof(IndexEntry), compare_entries);
    print_index(age_index);
    
    // Initialize an index for name
    Index name_index;
    name_index.size = db_size;
    for (int i = 0; i < db_size; i++) {
        name_index.entries[i].value = strlen(database[i].name);
        name_index.entries[i].index = i;
    }
    qsort(name_index.entries, name_index.size, sizeof(IndexEntry), compare_entries);
    print_index(name_index);
    
    // Example multiplayer game loop that allows querying the database by index
    int current_player_id = 1;
    while (true) {
        printf("Player %d, enter a query:\n", current_player_id);
        printf("1: Query by age\n");
        printf("2: Query by name length\n");
        printf("3: Exit\n");
        int query_type;
        scanf("%d", &query_type);
        
        if (query_type == 1) {
            printf("Enter an age: ");
            int age;
            scanf("%d", &age);
            
            // Binary search the age index
            int index = -1;
            int left = 0;
            int right = age_index.size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (age_index.entries[mid].value == age) {
                    index = age_index.entries[mid].index;
                    break;
                } else if (age_index.entries[mid].value < age) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // Print the result
            if (index == -1) {
                printf("No match found.\n");
            } else {
                printf("Match found:\n");
                print_element(database[index]);
            }
        } else if (query_type == 2) {
            printf("Enter a name length: ");
            int length;
            scanf("%d", &length);
            
            // Binary search the name index
            int index = -1;
            int left = 0;
            int right = name_index.size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (name_index.entries[mid].value == length) {
                    index = name_index.entries[mid].index;
                    break;
                } else if (name_index.entries[mid].value < length) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // Print the result
            if (index == -1) {
                printf("No match found.\n");
            } else {
                printf("Match found:\n");
                print_element(database[index]);
            }
        } else if (query_type == 3) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid input.\n");
        }
        
        // Switch to the other player
        current_player_id = 3 - current_player_id;
    }
    
    return 0;
}