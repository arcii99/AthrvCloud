//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char first_name[20];
    char last_name[20];
} Person;

typedef struct {
    int id;
    long int offset;
} Index;

void display_menu() {
    printf("1. Add Person\n");
    printf("2. Delete Person\n");
    printf("3. Search Person\n");
    printf("4. Display All Persons\n");
    printf("5. Exit\n");
}

int main() {
    FILE *fp;
    int choice;
    int id;
    char first_name[20];
    char last_name[20];
    int size_person = sizeof(Person);
    int size_index = sizeof(Index);
    int num_records = 0;
    int i, j;
    long int offset;
    Person new_person;

    // Create an array to hold indexes
    const int MAX_RECORDS = 100;
    Index index_array[MAX_RECORDS];

    // Initialize the index array with invalid values    
    for (i = 0; i < MAX_RECORDS; i++) {
        index_array[i].id = -1;
        index_array[i].offset = -1;
    }

    fp = fopen("persons.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("persons.dat", "wb");
    }

    // Read the file and populate the index array
    while (fread(&new_person, size_person, 1, fp)) {
        if (num_records < MAX_RECORDS) {
            index_array[num_records].id = new_person.id;
            index_array[num_records].offset = ftell(fp) - size_person;
        }
        num_records++;
    }

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a Person
                printf("Enter Person ID: ");
                scanf("%d", &id);
                printf("Enter Person First Name: ");
                scanf("%s", first_name);
                printf("Enter Person Last Name: ");
                scanf("%s", last_name);

                new_person.id = id;
                strcpy(new_person.first_name, first_name);
                strcpy(new_person.last_name, last_name);

                // Write the new Person record to file
                fseek(fp, 0, SEEK_END);
                fwrite(&new_person, size_person, 1, fp);

                // Add the new index to the index array
                if (num_records < MAX_RECORDS) {
                    index_array[num_records].id = id;
                    index_array[num_records].offset = ftell(fp) - size_person;
                } else {
                    printf("Maximum number of records reached!\n");
                }
                num_records++;
                break;
            case 2:
                // Delete a Person
                printf("Enter ID of Person to delete: ");
                scanf("%d", &id);

                // Find the index of the Person to delete
                for (i = 0; i < num_records; i++) {
                    if (index_array[i].id == id) {
                        break;
                    }
                }

                if (i == num_records) {
                    printf("Person not found!\n");
                }

                // Shift all the remaining indexes and write them to file
                for (j = i; j < num_records - 1; j++) {
                    index_array[j] = index_array[j + 1];
                }

                // Truncate the file to delete the record
                fseek(fp, index_array[i].offset, SEEK_SET);
                ftruncate(fileno(fp), index_array[i + 1].offset);
                num_records--;
                break;
            case 3:
                // Search for a Person
                printf("Enter ID of Person to search: ");
                scanf("%d", &id);

                // Binary search to find the index of the Person
                int low = 0;
                int high = num_records - 1;
                int mid, person_id;
                while (low <= high) {
                    mid = (low + high) / 2;
                    fseek(fp, index_array[mid].offset, SEEK_SET);
                    fread(&new_person, size_person, 1, fp);

                    person_id = new_person.id;
                    if (person_id == id) {
                        printf("ID: %d\tFirst Name: %s\tLast Name: %s\n",
                                new_person.id, new_person.first_name, new_person.last_name);
                        break;
                    } else if (person_id < id) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                if (low > high) {
                    printf("Person not found!\n");
                }
                break;
            case 4:
                // Display all Persons
                fseek(fp, 0, SEEK_SET);
                while (fread(&new_person, size_person, 1, fp)) {
                    printf("ID: %d\tFirst Name: %s\tLast Name: %s\n",
                            new_person.id, new_person.first_name, new_person.last_name);
                }
                break;
            case 5:
                // Exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    // Write the final index array to a separate index file
    FILE *index_fp;
    index_fp = fopen("index.dat", "wb");
    fwrite(&num_records, sizeof(int), 1, index_fp);
    fwrite(index_array, size_index, num_records, index_fp);

    fclose(fp);
    fclose(index_fp);
    return 0;
}