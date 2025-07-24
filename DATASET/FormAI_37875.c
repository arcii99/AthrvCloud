//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_RECORDS 1000
#define MAX_INDEX_KEYS 50

struct record {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct indexKey {
    char key[MAX_NAME_LENGTH];
    int index;
};

struct database {
    struct record records[MAX_RECORDS];
    struct indexKey keys[MAX_INDEX_KEYS];
    int numRecords;
    int numKeys;
};

int binary_search(struct indexKey keys[], int numKeys, char searchKey[]){
    int low = 0, high = numKeys - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(strcmp(keys[mid].key, searchKey) == 0){
            return keys[mid].index;
        }
        else if(strcmp(keys[mid].key, searchKey) < 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

void add_record(struct database *db, struct record newRecord){
    db->records[db->numRecords] = newRecord;
    int newIndex = db->numRecords;
    char nameKey[MAX_NAME_LENGTH];
    strncpy(nameKey, newRecord.name, MAX_NAME_LENGTH);
    int index = binary_search(db->keys, db->numKeys, nameKey);
    if(index == -1){
        db->keys[db->numKeys].index = newIndex;
        strncpy(db->keys[db->numKeys].key, nameKey, MAX_NAME_LENGTH);
        db->numKeys++;
    }
    else{
        // Find the correct position to insert the new key
        int i;
        for(i = db->numKeys - 1; i >= index; i--){
            db->keys[i+1].index = db->keys[i].index;
            strncpy(db->keys[i+1].key, db->keys[i].key, MAX_NAME_LENGTH);
        }
        db->keys[index].index = newIndex;
        strncpy(db->keys[index].key, nameKey, MAX_NAME_LENGTH);
        db->numKeys++;
    }
    db->numRecords++;
}

struct record* find_record(struct database *db, char name[]){
    int index = binary_search(db->keys, db->numKeys, name);
    if(index == -1){
        return NULL;
    }
    else{
        return &(db->records[db->keys[index].index]);
    }
}

int main(){
    struct database db;
    db.numRecords = 0;
    db.numKeys = 0;
    
    // Add some example records
    struct record r1 = {1, "John Smith", "123 Main St", "(555) 555-1212"};
    struct record r2 = {2, "Jane Doe", "456 Oak Ave", "(555) 555-2323"};
    struct record r3 = {3, "John Johnson", "789 Maple Ln", "(555) 555-3434"};
    struct record r4 = {4, "Jane Smith", "321 Elm St", "(555) 555-4545"};
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);
    add_record(&db, r4);
    
    // Find a record by name
    char searchName[MAX_NAME_LENGTH] = "Jane Doe";
    struct record *foundRecord = find_record(&db, searchName);
    if(foundRecord == NULL){
        printf("Record not found.\n");
    }
    else{
        printf("Record found:\n");
        printf("Name: %s\n", foundRecord->name);
        printf("Address: %s\n", foundRecord->address);
        printf("Phone: %s\n", foundRecord->phone);
    }

    return 0;
}