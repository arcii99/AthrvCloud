//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MEDICINE 100
#define MAX_SALES 100

typedef struct {
    int id;
    char name[50];
    int stock_quantity;
    float unit_price;
} medicine;

typedef struct {
    int id;
    int medicine_id;
    float unit_price;
    int quantity;
} sale;

medicine medicines[MAX_MEDICINE];
int medicine_count = 0;

sale sales[MAX_SALES];
int sales_count = 0;

pthread_mutex_t medicine_mutex;
pthread_mutex_t sales_mutex;

void add_medicine(medicine new_medicine) {
    pthread_mutex_lock(&medicine_mutex);
    if (medicine_count < MAX_MEDICINE) {
        medicines[medicine_count++] = new_medicine;
    }
    pthread_mutex_unlock(&medicine_mutex);
}

int remove_medicine(int medicine_id) {
    int found = 0;
    pthread_mutex_lock(&medicine_mutex);
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == medicine_id) {
            medicines[i] = medicines[--medicine_count];
            found = 1;
            break;
        }
    }
    pthread_mutex_unlock(&medicine_mutex);
    return found;
}

void make_sale(sale new_sale) {
    pthread_mutex_lock(&sales_mutex);
    if (sales_count < MAX_SALES) {
        sales[sales_count++] = new_sale;
    }
    pthread_mutex_unlock(&sales_mutex);
}

void* add_medicine_thread(void* arg) {
    medicine new_medicine;
    new_medicine.id = 1;
    strcpy(new_medicine.name, "Paracetamol");
    new_medicine.stock_quantity = 100;
    new_medicine.unit_price = 2.5;
    add_medicine(new_medicine);
    printf("Added Paracetamol to the list of medicines.\n");
    return NULL;
}

void* remove_medicine_thread(void* arg) {
    int medicine_id = *((int*) arg);
    if (remove_medicine(medicine_id)) {
        printf("Removed medicine with id %d from the list.\n", medicine_id);
    } else {
        printf("Medicine with id %d not found.\n", medicine_id);
    }
    return NULL;
}

void* make_sale_thread(void* arg) {
    sale new_sale;
    new_sale.id = 1;
    new_sale.medicine_id = 1;
    new_sale.unit_price = 2.5;
    new_sale.quantity = 10;
    make_sale(new_sale);
    printf("Sale of 10 units of Paracetamol made.\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, add_medicine_thread, NULL);
    pthread_join(tid, NULL);

    int remove_medicine_id = 1;
    pthread_create(&tid, NULL, remove_medicine_thread, &remove_medicine_id);
    pthread_join(tid, NULL);

    pthread_create(&tid, NULL, make_sale_thread, NULL);
    pthread_join(tid, NULL);

    return 0;
}