//FormAI DATASET v1.0 Category: Digital Diary ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Diary{
    char title[50];
    char date[20];
    char entry[1000];
} Diary;

int main(){
    int numEntries=0;
    printf("How many entries would you like to make today?\n");
    scanf("%d",&numEntries);
    
    Diary entries[numEntries];
    for(int i=0;i<numEntries;i++){
        printf("Enter the title for entry %d:\n",i+1);
        scanf("%s",entries[i].title);
        printf("Enter the date for entry %d (dd/mm/yyyy):\n",i+1);
        scanf("%s",entries[i].date);
        printf("Enter the entry for %s:\n",entries[i].date);
        scanf(" %[^\n]s",entries[i].entry);
    }
    
    printf("Your entries for today are:\n");
    for(int i=0;i<numEntries;i++){
        printf("Title: %s\nDate: %s\nEntry: %s\n",entries[i].title,entries[i].date,entries[i].entry);
    }
    
    return 0;
}