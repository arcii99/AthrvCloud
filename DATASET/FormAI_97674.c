//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUERY_LENGTH 1000

int main() {
    char query[MAX_QUERY_LENGTH];
    char name[20];
    int age;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);

    sprintf(query, "SELECT * FROM people WHERE name='%s' AND age=%d", name, age);

    printf("Executing query: %s\n", query);

    // Database code goes here
    // ...

    return 0;
}