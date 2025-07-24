//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define the structure to store the data in the file
struct person {
    char name[50];
    int age;
    long long int phno;
};

//define the structure for the index table 
struct index {
    char name[50];
    long long int addr;
};

//define the function to create primary index
int createPrimaryIndex(FILE *fp, FILE *ip) {
    struct person p;
    struct index i;
    int count = 0;
    //reading from the file until the end of file is reached
    while(fread(&p, sizeof(p), 1, fp) == 1) {
        //set the name and address in the index
        strcpy(i.name, p.name);
        i.addr = ftell(fp) - sizeof(p);
        //write the index to the index file
        fwrite(&i, sizeof(i), 1, ip);
        count++;
    }
    return count;
}

//function to search the primary index
long long int searchPrimaryIndex(char* name, FILE *ip) {
    struct index i;
    //reading from the index file until the end of file is reached
    while(fread(&i, sizeof(i), 1, ip) == 1) {
        //compare the search string with the name in the index
        if(strcmp(i.name, name) == 0) {
            return i.addr;
        }
    }
    //if the search string is not found return -1
    return -1;
}

//function to read the record given the address
void readRecord(long long int addr, FILE *fp) {
    struct person p;
    //move the file pointer to the specified address
    fseek(fp, addr, SEEK_SET);
    //read the record from the file
    fread(&p, sizeof(p), 1, fp);
    //print the record
    printf("Name: %s\nAge: %d\nPhone Number: %lld\n", p.name, p.age, p.phno);
}

//main function
int main() {
    FILE *fp, *ip;
    //open the data file
    fp = fopen("data.txt", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    //open the index file
    ip = fopen("index.txt", "wb");
    if(ip == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    //create the primary index
    int count = createPrimaryIndex(fp, ip);
    //close the files
    fclose(fp);
    fclose(ip);

    //open the index file for searching
    ip = fopen("index.txt", "rb");
    if(ip == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char name[50];
    printf("Enter the name to search: ");
    scanf("%s", name);
    long long int addr = searchPrimaryIndex(name, ip);
    fclose(ip);
    //open the data file for reading the record
    fp = fopen("data.txt", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    //if the address is found in the index, read the record
    if(addr != -1) {
        readRecord(addr, fp);
    }
    else {
        printf("Record not found!\n");
    }
    //close the files
    fclose(fp);
    return 0;
}