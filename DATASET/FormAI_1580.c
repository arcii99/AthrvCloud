//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define PIN_LENGTH 6
#define MAX_ACC_NO 9999

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_no[11];
    char acc_no[5];
    char pin[PIN_LENGTH];
} Record;

int num_records = 0;
Record records[MAX_RECORDS];

void prompt() {
    printf("Enter option:\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Delete Record\n");
    printf("4. View All Records\n");
    printf("5. Exit\n");
}

int validate_acc_no(char* acc_no) {
    if (strlen(acc_no) != 4) {
        return 0;
    }
    for (int i = 0; i < strlen(acc_no); i++) {
        if (acc_no[i] < '0' || acc_no[i] > '9') {
            return 0;
        }
    }
    int int_acc_no = atoi(acc_no);
    if (int_acc_no < 0 || int_acc_no > MAX_ACC_NO) {
        return 0;
    }
    return 1;
}

int validate_pin(char* pin) {
    if (strlen(pin) != PIN_LENGTH) {
        return 0;
    }
    for (int i = 0; i < strlen(pin); i++) {
        if (pin[i] < '0' || pin[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void add_record() {
    printf("Enter name:\n");
    Record new_record;
    fgets(new_record.name, MAX_NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0;
    printf("Enter address:\n");
    fgets(new_record.address, MAX_ADDRESS_LENGTH, stdin);
    new_record.address[strcspn(new_record.address, "\n")] = 0;
    printf("Enter phone number:\n");
    fgets(new_record.phone_no, 11, stdin);
    new_record.phone_no[strcspn(new_record.phone_no, "\n")] = 0;
    printf("Enter account number:\n");
    fgets(new_record.acc_no, 5, stdin);
    new_record.acc_no[strcspn(new_record.acc_no, "\n")] = 0;
    while (!validate_acc_no(new_record.acc_no)) {
        printf("Invalid account number. Enter a valid 4 digit account number:\n");
        fgets(new_record.acc_no, 5, stdin);
        new_record.acc_no[strcspn(new_record.acc_no, "\n")] = 0;
    }
    printf("Enter PIN:\n");
    fgets(new_record.pin, PIN_LENGTH, stdin);
    new_record.pin[strcspn(new_record.pin, "\n")] = 0;
    while (!validate_pin(new_record.pin)) {
        printf("Invalid PIN. Enter a valid 6 digit PIN:\n");
        fgets(new_record.pin, PIN_LENGTH, stdin);
        new_record.pin[strcspn(new_record.pin, "\n")] = 0;
    }
    records[num_records++] = new_record;
    printf("Record added successfully.\n");
}

void search_record() {
    printf("Enter account number to search:\n");
    char acc_no[5];
    fgets(acc_no, 5, stdin);
    acc_no[strcspn(acc_no, "\n")] = 0;
    while (!validate_acc_no(acc_no)) {
        printf("Invalid account number. Enter a valid 4 digit account number:\n");
        fgets(acc_no, 5, stdin);
        acc_no[strcspn(acc_no, "\n")] = 0;
    }
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].acc_no, acc_no) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Phone Number: %s\n", records[i].phone_no);
            printf("Account Number: %s\n", records[i].acc_no);
            printf("PIN: %s\n", records[i].pin);
            return;
        }
    }
    printf("Record not found for account number %s\n", acc_no);
}

void delete_record() {
    printf("Enter account number to delete:\n");
    char acc_no[5];
    fgets(acc_no, 5, stdin);
    acc_no[strcspn(acc_no, "\n")] = 0;
    while (!validate_acc_no(acc_no)) {
        printf("Invalid account number. Enter a valid 4 digit account number:\n");
        fgets(acc_no, 5, stdin);
        acc_no[strcspn(acc_no, "\n")] = 0;
    }
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].acc_no, acc_no) == 0) {
            for (int j = i; j < num_records-1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Record for account number %s deleted successfully.\n", acc_no);
            return;
        }
    }
    printf("Record not found for account number %s\n", acc_no);
}

void view_all_records() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    printf("Total records: %d\n", num_records);
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d:\n", i+1);
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone Number: %s\n", records[i].phone_no);
        printf("Account Number: %s\n", records[i].acc_no);
        printf("PIN: %s\n", records[i].pin);
    }
}

int main() {
    char secret_code[] = "secret";
    char input_code[10];
    printf("Enter secret code to access banking record system:\n");
    fgets(input_code, 10, stdin);
    input_code[strcspn(input_code, "\n")] = 0;
    if (strcmp(input_code, secret_code) != 0) {
        printf("Access denied.\n");
        exit(0);
    }
    printf("Access granted.\n");
    while (1) {
        prompt();
        int option;
        scanf("%d", &option);
        getchar();
        switch(option) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                view_all_records();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}