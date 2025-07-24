//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 1000
#define MAX_NUM_INDEXES 5

typedef struct record {
    int id;
    char name[50];
    float score;
} Record;

typedef struct index {
    char type;
    void* data;
} Index;

Record records[MAX_NUM_RECORDS];
Index indexes[MAX_NUM_INDEXES];

// Define functions for each type of index
void* create_name_index() {
    char* names[MAX_NUM_RECORDS];
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        names[i] = records[i].name;
    }
    return (void*) names;
}

void* create_score_index() {
    float* scores[MAX_NUM_RECORDS];
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        scores[i] = &records[i].score;
    }
    return (void*) scores;
}

void* create_id_index() {
    int* ids[MAX_NUM_RECORDS];
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        ids[i] = &records[i].id;
    }
    return (void*) ids;
}

void create_indexes() {
    indexes[0].type = 'N';
    indexes[0].data = create_name_index();
    indexes[1].type = 'S';
    indexes[1].data = create_score_index();
    indexes[2].type = 'I';
    indexes[2].data = create_id_index();
}

void sort_names(char* names[], int num_records) {
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char* temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

void sort_scores(float* scores[], int num_records) {
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (*scores[i] < *scores[j]) {
                float* temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

void sort_ids(int* ids[], int num_records) {
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (*ids[i] > *ids[j]) {
                int* temp = ids[i];
                ids[i] = ids[j];
                ids[j] = temp;
            }
        }
    }
}

void sort_index(int index_num, int num_records) {
    if (indexes[index_num].type == 'N') {
        sort_names((char**)indexes[index_num].data, num_records);
    } else if (indexes[index_num].type == 'S') {
        sort_scores((float**)indexes[index_num].data, num_records);
    } else if (indexes[index_num].type == 'I') {
        sort_ids((int**)indexes[index_num].data, num_records);
    }
}

void create_database() {
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        records[i].id = rand() % 1000 + 1;
        sprintf(records[i].name, "Record %d", records[i].id);
        records[i].score = (float) rand() / RAND_MAX;
    }
}

void print_records() {
    printf("ID\tNAME\t\t\t\tSCORE\n");
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        printf("%d\t%-24s\t%.2f\n", records[i].id, records[i].name, records[i].score);
    }
}

int main() {
    create_database();
    printf("Original database:\n");
    print_records();
    create_indexes();
    printf("\nName index:\n");
    sort_index(0, MAX_NUM_RECORDS);
    char** names = (char**) indexes[0].data;
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        printf("%s\n", names[i]);
    }
    printf("\nScore index:\n");
    sort_index(1, MAX_NUM_RECORDS);
    float** scores = (float**) indexes[1].data;
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        printf("%.2f\n", *scores[i]);
    }
    printf("\nID index:\n");
    sort_index(2, MAX_NUM_RECORDS);
    int** ids = (int**) indexes[2].data;
    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        printf("%d\n", *ids[i]);
    }
    return 0;
}