//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_MEDICINES 100
#define MED_NAME_LEN 50

typedef struct {
    char name[MED_NAME_LEN];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int total_medicines = 0;

pthread_mutex_t mutex;

bool add_medicine(char name[], int quantity, float price) {
    if(total_medicines == MAX_MEDICINES) {
        return false;
    }
    
    strcpy(medicines[total_medicines].name, name);
    medicines[total_medicines].quantity = quantity;
    medicines[total_medicines].price = price;
    total_medicines++;
    
    return true;
}

bool remove_medicine(char name[]) {
    int i;
    for(i=0; i<total_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            break;
        }
    }
    if(i == total_medicines) { // medicine not found
        return false;
    }
    
    memmove(medicines+i, medicines+i+1, (total_medicines-i-1)*sizeof(Medicine));
    total_medicines--;
    
    return true;
}

void* sell_medicine(void* data) {
    char name[MED_NAME_LEN];
    int quantity;
    float total_price = 0.0;
    
    printf("Enter medicine name and quantity separated by a space: ");
    scanf("%s %d", name, &quantity);
    
    pthread_mutex_lock(&mutex);
    
    int i;
    for(i=0; i<total_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            if(medicines[i].quantity < quantity) {
                printf("Cannot sell. Required quantity of %s is not available.\n", name);
                pthread_mutex_unlock(&mutex);
                return NULL;
            }
            
            medicines[i].quantity -= quantity;
            total_price = quantity * medicines[i].price;
            break;
        }
    }
    
    if(i == total_medicines) { // medicine not found
        printf("Cannot sell. Medicine %s not found.\n", name);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    
    printf("Sold %s %d for a total of %.2f\n", name, quantity, total_price);
    
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void print_medicines() {
    printf("Medicine Name\tQuantity\tPrice\n");
    int i;
    for(i=0; i<total_medicines; i++) {
        printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    char name[MED_NAME_LEN];
    int quantity;
    float price;
    
    bool added;
    added = add_medicine("Paracetamol", 100, 2.0);
    if(added) {
        printf("Added medicine %s successfully.\n", "Paracetamol");
    }
    added = add_medicine("Ibuprofen", 60, 3.5);
    if(added) {
        printf("Added medicine %s successfully.\n", "Ibuprofen");
    }
    added = add_medicine("Amoxicillin", 80, 5.0);
    if(added) {
        printf("Added medicine %s successfully.\n", "Amoxicillin");
    }
    added = add_medicine("Pantoprazole", 50, 4.0);
    if(added) {
        printf("Added medicine %s successfully.\n", "Pantoprazole");
    }
    
    printf("\n");
    print_medicines();
    printf("\n");
    
    int option;
    do {
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Print All Medicines\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: // Add Medicine
                printf("Enter medicine name, quantity and price separated by spaces: ");
                scanf("%s %d %f", name, &quantity, &price);
                
                pthread_mutex_lock(&mutex);
                added = add_medicine(name, quantity, price);
                pthread_mutex_unlock(&mutex);
                
                if(added) {
                    printf("Added medicine %s successfully.\n", name);
                } else {
                    printf("Cannot add medicine %s. Maximum medicine limit reached.\n", name);
                }
                break;
                
            case 2: // Remove Medicine
                printf("Enter medicine name to remove: ");
                scanf("%s", name);
                
                pthread_mutex_lock(&mutex);
                bool removed = remove_medicine(name);
                pthread_mutex_unlock(&mutex);
                
                if(removed) {
                    printf("Removed medicine %s successfully.\n", name);
                } else {
                    printf("Cannot remove medicine %s. Medicine not found.\n", name);
                }
                break;
                
            case 3: // Sell Medicine
                pthread_t thread;
                pthread_create(&thread, NULL, sell_medicine, NULL);
                pthread_join(thread, NULL);
                break;
                
            case 4: // Print All Medicines
                pthread_mutex_lock(&mutex);
                print_medicines();
                pthread_mutex_unlock(&mutex);
                break;
                
            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid Option. Please try again.\n");
        }
        
        printf("\n");
    } while(option != 5);
    
    return 0;
}