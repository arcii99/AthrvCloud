//FormAI DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <string.h>

struct record {
    char name[100];
    int age;
    char address[100];
    long int phone_no;
};

struct index {
    char name[100];
    int position;
};

int main() {
    struct record database [100] = {{"Tony Stark", 35, "Stark Tower", 9841098410},
                                    {"Natasha Romanoff", 28, "Avengers HQ", 8976897689},
                                    {"Steve Rogers", 100, "Retired", 7845678456},
                                    {"Bruce Banner", 49, "Unknown", 9834783478},
                                    {"Thor Odinson", 1500, "Asgard", 6745674567}};
    int n_records = 5, i, j;
    struct index index_list [100];
    for (i=0; i<n_records; i++) {
        strcpy(index_list[i].name, database[i].name);
        index_list[i].position = i;
    } 
    for (i=0; i<n_records; i++) {
        for (j=0; j<i; j++) {
            if (strcmp(index_list[i].name, index_list[j].name) < 0) {
                // swap the positions
                struct index temp;
                temp = index_list[i];
                index_list[i] = index_list[j];
                index_list[j] = temp;
            }
        }
    }
    char search_name[100];
    printf("Enter the name you want to search for: ");
    scanf("%s", search_name);
    int found = 0;
    for (i=0; i<n_records; i++) {
        if (strcmp(search_name, index_list[i].name) == 0) {
            found = 1;
            printf("Name: %s\n", database[index_list[i].position].name);
            printf("Age: %d\n", database[index_list[i].position].age);
            printf("Address: %s\n", database[index_list[i].position].address);
            printf("Phone Number: %ld\n", database[index_list[i].position].phone_no);
            break;
        }
    }
    if (found == 0) {
        printf("No record found!\n");
    }
    return 0;
}