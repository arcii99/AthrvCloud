//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char address[50];
    char phone[15];
} Customer;

typedef struct {
    int key;
    int offset;
} Index;

void create_index(char* filename, char* indexname) {
    FILE* fp = fopen(filename, "rb");
    FILE* ip = fopen(indexname, "wb");
    int offset = 0;
    Customer customer;

    while (fread(&customer, sizeof(Customer), 1, fp)) {
        Index index;
        index.key = customer.id;
        index.offset = offset;
        fwrite(&index, sizeof(Index), 1, ip);
        offset += sizeof(Customer);
    }

    fclose(fp);
    fclose(ip);
}

int search(char* indexname, int id) {
    FILE* ip = fopen(indexname, "rb");
    Index index;

    while (fread(&index, sizeof(Index), 1, ip)) {
        if (index.key == id) {
            fclose(ip);
            return index.offset;
        }
    }

    fclose(ip);
    return -1;
}

int main() {
    create_index("customers.bin", "index.dat");
    int id = 3;
    int offset = search("index.dat", id);

    if (offset != -1) {
        FILE* fp = fopen("customers.bin", "rb");
        Customer customer;
        fseek(fp, offset, SEEK_SET);
        fread(&customer, sizeof(Customer), 1, fp);
        fclose(fp);
        printf("Customer Details:\n");
        printf("ID: %d\n", customer.id);
        printf("Name: %s\n", customer.name);
        printf("Address: %s\n", customer.address);
        printf("Phone: %s\n", customer.phone);
    } else {
        printf("Customer not found!\n");
    }

    return 0;
}