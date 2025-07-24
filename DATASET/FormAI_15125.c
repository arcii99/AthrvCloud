//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[50];
    char emp_id[10];
    char email[50];
    char phone[15];
} Employee;

int main()
{
    Employee emp_data[10];
    char resume[1000];
    int i=0, j=0, k=0, count=0;
    char *token;
    char *delimiter = ",\n";
    FILE *fp;
    
    fp = fopen("resume.txt", "r");
    if(fp == NULL)
    {
        printf("Error in opening the file");
        return 0;
    }
    
    fgets(resume, 1000, fp);
    token = strtok(resume, delimiter);
    
    while(token!= NULL)
    {
        switch(count)
        {
            case 0:
                strcpy(emp_data[i].name, token);
                break;
            case 1:
                strcpy(emp_data[i].emp_id, token);
                break;
            case 2:
                strcpy(emp_data[i].email, token);
                break;
            case 3:
                strcpy(emp_data[i].phone, token);
                i++;
                break;
            default:
                break;
        }
        
        token = strtok(NULL, delimiter);
        count ++;
        if(count > 3)
        {
            count = 0;
        }
    }
    
    for(j=0; j<i; j++)
    {
        printf("Employee %d\nName: %s\nEmployee ID: %s\nEmail: %s\nPhone: %s\n", j+1, emp_data[j].name, emp_data[j].emp_id, emp_data[j].email, emp_data[j].phone);
    }
    
    fclose(fp);
    return 0;
}