//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRY 10

typedef struct entry{
    int id;
    char ip[16];
    char time[25];
} Entry;

void report_intrusion(Entry entry);
void parse_entry(const char* str, Entry *entry);

int main(){
    char entry_str[100];
    Entry entry;
    int i;
    for(i=1; i<=MAX_ENTRY; i++){
        printf("Enter the intrusion details (ID IP time)\n");
        fgets(entry_str, 100, stdin);
        parse_entry(entry_str, &entry);
        report_intrusion(entry);
    }
    printf("Maximum allowable entries reached! Exiting\n");
}

void report_intrusion(Entry entry){
    printf("INTRUSION ALERT: ID %d from IP %s at time %s\n", entry.id, entry.ip, entry.time);
}

void parse_entry(const char* str, Entry *entry){
    char *token;
    char delim[] = " ";
    token = strtok(str, delim);
    entry->id = atoi(token);
    token = strtok(NULL, delim);
    strncpy(entry->ip, token, 16);
    token = strtok(NULL, delim);
    strncpy(entry->time, token, 25);
}