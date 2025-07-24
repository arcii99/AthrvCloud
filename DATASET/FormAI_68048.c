//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 10

typedef struct {
    int id;
    char name[30];
    float score[MAX_FIELDS];
} Record;

int main() {
    // open dataset file
    FILE* dataset = fopen("data.csv", "r");
    if (!dataset) {
        printf("Dataset file could not be opened. Exiting...\n");
        return 1;
    }

    // read dataset records
    Record records[MAX_RECORDS];
    int num_records = 0;
    char line[100];
    fgets(line, 100, dataset); // skip header
    while (fgets(line, 100, dataset) && num_records < MAX_RECORDS) {
        sscanf(line, "%d,%[^,],%f,%f,%f,%f\n", &records[num_records].id, records[num_records].name,
               &records[num_records].score[0], &records[num_records].score[1],
               &records[num_records].score[2], &records[num_records].score[3]);
        num_records++;
    }

    // calculate average score for each record
    for (int i = 0; i < num_records; i++) {
        float sum = 0;
        for (int j = 0; j < MAX_FIELDS; j++) {
            sum += records[i].score[j];
        }
        float average = sum / MAX_FIELDS;
        printf("%s's average score is %.2f\n", records[i].name, average);
    }

    // close dataset file
    fclose(dataset);

    return 0;
}