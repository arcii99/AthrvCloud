//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ADDRESS_LEN 50
#define MAX_PHONE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
    int age;
} record;

int main() {
    FILE *in_file;
    record rec;
    char name[MAX_NAME_LEN];

    // open file
    if ((in_file = fopen("data.bin", "rb")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // prompt user for name search
    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // strip newline

    // read records and search for name
    while (fread(&rec, sizeof(record), 1, in_file)) {
        if (strcmp(rec.name, name) == 0) {
            printf("\nRecord Found!\n");
            printf("Name: %s\nAddress: %s\nPhone: %s\nAge: %d\n",
                    rec.name, rec.address, rec.phone, rec.age);
            return 0; // exit program
        }
    }
    // if name not found
    printf("Name not found!\n");

    // close file
    fclose(in_file);

    return 0;
}