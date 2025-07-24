//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include<stdio.h>
#include<string.h>
#define MAX 50

struct resume {
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char skills[MAX];
};

struct resume arr[5];   //Array of 5 resumes

void parseResume(struct resume r) {
    printf("\nName: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
}

int main() {
    int i=0, j=0, len;
    char str[100], temp[MAX];

    printf("Enter 5 resumes: \n");
    for(i=0; i<5; i++) {
        printf("\nResume %d\n", i+1);
        printf("----------------\n");
        printf("Name: ");
        fgets(arr[i].name,MAX,stdin);

        printf("Email: ");
        fgets(arr[i].email,MAX,stdin);

        printf("Phone: ");
        fgets(arr[i].phone,MAX,stdin);

        printf("Skills: ");
        fgets(arr[i].skills,MAX,stdin);
    }

    printf("\nEnter keyword to search: ");
    fgets(str, 100, stdin);
    len = strlen(str);
    if(str[len-1] == '\n') {
        str[len-1] = '\0';  //replace newline character with null character
    }

    printf("\nResult for keyword %s\n", str);
    printf("-------------------------\n");

    for(i=0; i<5; i++) {   //parse each resume for keyword search
        strcpy(temp,arr[i].skills);  //copy each resume's skills to temp array

        for(j=0; j<strlen(temp); j++) {  
            if(temp[j] == ',') {  //replace commas with spaces
                temp[j] = ' ';
            }
        }

        char *token = strtok(temp, " ");  //scan temp array for tokens using spaces as delimiter
        while(token != NULL) {
            if(strcmp(str,token) == 0) {  //compare keyword with each token
                parseResume(arr[i]);     //if found, parse the matching resume
                break;
            }
            token = strtok(NULL, " ");
        }
    }

    return 0;
}