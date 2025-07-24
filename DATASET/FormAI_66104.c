//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[50];
    int age;
    char cyberware[50];
} Record;

int main() {
    Record data[MAX_RECORDS];

    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Failed to open file.");
        return 0;
    }

    char buffer[255];
    int count = 0;

    while (fgets(buffer, 255, fp) != NULL) {
        char *token = strtok(buffer, ",");
        int field_count = 0;

        while (token != NULL) {
            if (field_count == 0) {
                data[count].id = atoi(token);
            } else if (field_count == 1) {
                strcpy(data[count].name, token);
            } else if (field_count == 2) {
                data[count].age = atoi(token);
            } else {
                strcpy(data[count].cyberware, token);
            }

            token = strtok(NULL, ",");
            field_count++;
        }

        count++;

        if (count >= MAX_RECORDS) {
            printf("Maximum record limit reached.");
            break;
        }
    }

    fclose(fp);

    for (int i = 0; i < count; i++) {
        if (strcmp(data[i].cyberware, "Neural Interface") == 0) {
            printf("%d | %s | %d | %s\n", data[i].id, data[i].name, data[i].age, data[i].cyberware);
        }
    }

    return 0;
}