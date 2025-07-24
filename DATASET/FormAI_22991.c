//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILENAME "passwords.txt"

void read_from_file(char* file_name, char passwords[][MAX], int* num_passwords) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: File not found");
        exit(EXIT_FAILURE);
    }
    char password[MAX];
    *num_passwords = 0;
    while (fgets(password, MAX, fp) != NULL) {
        password[strcspn(password, "\n")] = 0;
        strcpy(passwords[*num_passwords], password);
        (*num_passwords)++;
    }
    fclose(fp);
}

void write_to_file(char* file_name, char passwords[][MAX], int num_passwords) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: File not found");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_passwords; i++) {
        fprintf(fp, "%s\n", passwords[i]);
    }
    fclose(fp);
}

void print_passwords(char passwords[][MAX], int num_passwords) {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i + 1, passwords[i]);
    }
    printf("\n");
}

void add_password(char passwords[][MAX], int* num_passwords) {
    char password[MAX];
    printf("Enter new password: ");
    scanf("%s", password);
    strcpy(passwords[*num_passwords], password);
    (*num_passwords)++;
}

void remove_password(char passwords[][MAX], int* num_passwords) {
    int index;
    printf("Enter index of password to remove: ");
    scanf("%d", &index);
    if (index <= 0 || index > *num_passwords) {
        printf("Error: Invalid index\n");
        return;
    }
    for (int i = index - 1; i < *num_passwords - 1; i++) {
        strcpy(passwords[i], passwords[i + 1]);
    }
    (*num_passwords)--;
}

int main() {
    char passwords[MAX][MAX];
    int num_passwords = 0;
    read_from_file(FILENAME, passwords, &num_passwords);
    char input;
    do {
        printf("Enter a to add a new password\n");
        printf("Enter r to remove a password\n");
        printf("Enter p to print all passwords\n");
        printf("Enter q to quit\n");
        scanf(" %c", &input);
        switch (input) {
            case 'a':
                add_password(passwords, &num_passwords);
                break;
            case 'r':
                remove_password(passwords, &num_passwords);
                break;
            case 'p':
                print_passwords(passwords, num_passwords);
                break;
        }
    } while (input != 'q');
    write_to_file(FILENAME, passwords, num_passwords);
    return 0;
}