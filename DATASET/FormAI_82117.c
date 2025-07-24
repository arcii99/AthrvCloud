//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 1000

struct Person{
    char name[50];
    int age;
    char address[100];
};

struct IndexNode{
    char indexing_string[50];
    int index_location;
};

struct Index{
    int size;
    struct IndexNode data[MAX_RECORDS];
};

struct PersonDatabase{
    int size;
    struct Person data[MAX_RECORDS];
    struct Index index;
};

void add_record(struct PersonDatabase *db, struct Person p){
    int index_location = db->size;
    db->data[db->size] = p;
    db->size++;

    for(int i=0;i<strlen(p.name);i++){
        char temp_index_str[50];
        strncpy(temp_index_str, &p.name[i], 2);
        temp_index_str[2]='\0';

        int index_location_exists = -1;
        for(int j=0;j<db->index.size;j++){
            if(strcmp(db->index.data[j].indexing_string, temp_index_str)==0){
                index_location_exists = db->index.data[j].index_location;
            }
        }

        if(index_location_exists!=-1){
            struct Person temp = db->data[index_location_exists];
            db->data[index_location_exists] = p;
            db->data[index_location] = temp;
            index_location = index_location_exists;              
        }
    }
    strcpy(db->index.data[db->index.size].indexing_string, &p.name[0]);     
   
    db->index.data[db->index.size].index_location = index_location;
    db->index.size++;
}

void search_person(struct PersonDatabase *db, char *name){
    int person_present = 0;
    int index_location = -1;
    for(int i=0;i<db->index.size;i++){
        if(strcmp(db->index.data[i].indexing_string, name)==0){
            index_location = db->index.data[i].index_location;
            break;
        }
    }
    if(index_location!=-1){
        printf("Person found: %s, %d years old, residing at %s\n", db->data[index_location].name, db->data[index_location].age, db->data[index_location].address);
    }
    else{
        printf("Person not found in database.\n");
    }
}

int main(){
    struct PersonDatabase db;
    db.size = 0;
    db.index.size = 0;

    struct Person p1 = {"John Doe", 25, "123 Main St"};
    struct Person p2 = {"Jane Smith", 30, "456 Elm St"};
    struct Person p3 = {"Jake Johnson", 40, "789 Oak St"};
    struct Person p4 = {"Jenny Williams", 50, "1011 Pine St"};
    add_record(&db, p1);
    add_record(&db, p2);
    add_record(&db, p3);
    add_record(&db, p4);

    search_person(&db, "John");
    search_person(&db, "Smith");
    search_person(&db, "Jake");
    search_person(&db, "Williams");

    return 0;
}