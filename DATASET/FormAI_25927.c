//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATABASE_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_SCORE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Record;

Record database[MAX_DATABASE_SIZE];
int num_records;

bool is_database_full() {
    return num_records == MAX_DATABASE_SIZE;
}

bool add_record(char* name, int score) {
    if (is_database_full()) {
        printf("Database is full!\n");
        return false;
    }

    Record new_record;
    strcpy(new_record.name, name);
    new_record.score = score;

    database[num_records] = new_record;
    num_records++;

    printf("Added record: %s %d\n", name, score);
    return true;
}

float get_average_score() {
    int total_score = 0;
    for (int i = 0; i < num_records; i++) {
        total_score += database[i].score;
    }
    return (float) total_score / num_records;
}

void print_database() {
    printf("Database:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", database[i].name, database[i].score);
    }
}

int main() {
    // Test adding records
    add_record("Alice", 90);
    add_record("Bob", 85);
    add_record("Charlie", 95);

    // Test getting average score
    float average_score = get_average_score();
    printf("Average score: %.2f\n", average_score);

    // Test printing database
    print_database();

    return 0;
}