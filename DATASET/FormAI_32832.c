//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

void queryDatabase(Person* db, int size, const char* query) {
    int results[size];
    int numResults = 0;
    int queryIndex = 0;
    for(int i = 0; i < size; i++) {
        int matchCount = 0;
        if(db[i].id == query[queryIndex]) {
            matchCount++;
        }
        if(strcmp(db[i].name, &(query[queryIndex+1])) == 0) {
            matchCount++;
        }
        if(db[i].age == query[queryIndex+1+strlen(db[i].name)+1]) {
            matchCount++;
        }
        if(matchCount == strlen(query) - 2) {
            results[numResults] = i;
            numResults++;
        }
    }
    if(numResults > 0) {
        printf("%d results found:\n", numResults);
        for(int i = 0; i < numResults; i++) {
            printf("ID: %d\n", db[results[i]].id);
            printf("Name: %s\n", db[results[i]].name);
            printf("Age: %d\n", db[results[i]].age);
            printf("\n");
        }
    } else {
        printf("No results found.\n");
    }
}

int main() {
    Person db[5] = {
        {1, "Alice", 25},
        {2, "Bob", 30},
        {3, "Charlie", 40},
        {4, "Dave", 35},
        {5, "Emma", 28}
    };
    char query[100];
    printf("Enter query: ");
    fgets(query, 100, stdin);
    
    //strip newline character from query
    query[strcspn(query, "\n")] = '\0';

    //check query for possible attack vectors
    if(strstr(query, ";") != NULL) {
        printf("Query contains possible SQL injection. Aborting.\n");
        return 1;
    }
    if(strchr(query, '\'') != NULL) {
        printf("Query contains possible SQL string injection. Aborting.\n");
        return 1;
    }
    for(int i = 0; i < strlen(query); i++) {
        if(!isdigit(query[i]) && !isalpha(query[i]) && query[i] != ' ') {
            printf("Query contains possible SQL injection. Aborting.\n");
            return 1;
        }
    }
    queryDatabase(db, 5, query);
    return 0;
}