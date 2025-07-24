//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[50], email[50], phone[20], address[100];
    int age;
    
    FILE *fp;
    fp = fopen("contacts.txt", "a");
    
    if(fp == NULL){
        printf("Error: unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("======================\n");
    printf("Enter Contact Details:\n");
    printf("======================\n");
    printf("Full Name: ");
    fgets(name, 50, stdin);
    printf("Email: ");
    fgets(email, 50, stdin);
    printf("Phone Number: ");
    fgets(phone, 20, stdin);
    printf("Address: ");
    fgets(address, 100, stdin);
    printf("Age: ");
    scanf("%d", &age);
    
    fprintf(fp, "Name: %sEmail: %sPhone: %sAddress: %sAge: %d\n", name, email, phone, address, age);
    
    printf("\nContact added to file successfully.\n");
    printf("======================\n");
    
    fclose(fp);
    return 0;
}