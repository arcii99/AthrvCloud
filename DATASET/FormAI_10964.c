//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct diary_entry{
    time_t timestamp;
    char* entry;
} DiaryEntry;

int main()
{
    char filename[50];
    printf("Enter filename for the diary: ");
    scanf("%s",filename);
    
    FILE* fp;
    fp = fopen(filename,"a+");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    
    int choice = 0;
    time_t now;
    struct tm* local;
    time(&now);
    local = localtime(&now);
    
    do
    {
        printf("\n1. Add entry\n2. View entries for a date\n3. Exit\nEnter choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                DiaryEntry entry;
                entry.timestamp = time(NULL);
                entry.entry = (char*)malloc(1000*sizeof(char));
                printf("Enter your diary entry:\n");
                scanf(" %[^\n]s",entry.entry);
                fwrite(&entry,sizeof(DiaryEntry),1,fp);
                break;
                
            case 2:
                time_t search_date;
                struct tm* requested_date;
                char requested_date_str[50];
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s",requested_date_str);

                requested_date = localtime(&now);
                sscanf(requested_date_str,"%d/%d/%d",&requested_date->tm_mday,&requested_date->tm_mon,&requested_date->tm_year);
                if(requested_date->tm_mday > 31 || requested_date->tm_mon > 12)
                {
                    printf("Invalid date.\n");
                    break;
                }
                search_date = mktime(requested_date);
                
                int count = 0;
                DiaryEntry read_entry;
                fseek(fp,0,SEEK_SET); // move file pointer to the start
                while(fread(&read_entry,sizeof(DiaryEntry),1,fp))
                {
                    if(difftime(search_date,read_entry.timestamp) == 0)
                    {
                        local = localtime(&read_entry.timestamp);
                        printf("%d/%d/%d %d:%d:%d\n%s\n\n",local->tm_mday,local->tm_mon + 1,local->tm_year + 1900,
                                local->tm_hour,local->tm_min,local->tm_sec,read_entry.entry);
                        count++;
                    }
                }
                if(count == 0)
                {
                    printf("\nNo entries found for the requested date.\n");
                }
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }while(choice != 3);
    
    fclose(fp);
    return 0;
}