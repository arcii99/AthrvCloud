//FormAI DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// function to handle potential buffer overflows
void secureStrncat(char* dest, const char* src, size_t dest_size) {
    strncat(dest, src, dest_size - strlen(dest) - 1);
}

int main() {
    char name[BUFFER_SIZE];
    char address[BUFFER_SIZE];
    char occupation[BUFFER_SIZE];
    char full_profile[BUFFER_SIZE];

    printf("Enter your full name: ");
    fgets(name, BUFFER_SIZE, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline character

    printf("Enter your address: ");
    fgets(address, BUFFER_SIZE, stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("Enter your occupation: ");
    fgets(occupation, BUFFER_SIZE, stdin);
    occupation[strcspn(occupation, "\n")] = '\0';

    // concatenate all information into a single string
    secureStrncat(full_profile, "Name: ", BUFFER_SIZE);
    secureStrncat(full_profile, name, BUFFER_SIZE);
    secureStrncat(full_profile, "\nAddress: ", BUFFER_SIZE);
    secureStrncat(full_profile, address, BUFFER_SIZE);
    secureStrncat(full_profile, "\nOccupation: ", BUFFER_SIZE);
    secureStrncat(full_profile, occupation, BUFFER_SIZE);

    // print out the full profile
    printf("Your profile:\n%s\n", full_profile);

    return 0;
}