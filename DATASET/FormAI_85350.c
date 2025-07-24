//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct resume{
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char experience[500];
    struct resume* next;
};

struct resume* createNode(char* name, char* email, char* phone, char* education, char* experience){
    struct resume* new_node = (struct resume*)malloc(sizeof(struct resume));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    strcpy(new_node->phone, phone);
    strcpy(new_node->education, education);
    strcpy(new_node->experience, experience);
    new_node->next = NULL;
    return new_node;
}

void insertNode(struct resume** head, struct resume* new_node){
    if(*head == NULL){
        *head = new_node;
    }else{
        insertNode(&((*head)->next), new_node);
    }
}

void freeList(struct resume* head){
    if(head == NULL) return;
    freeList(head->next);
    free(head);
}

void parseResume(char* resumeString, struct resume** head){
    char* token;
    char* delimiter = "\n";
    char* resumeCopy = strdup(resumeString);
    while((token = strtok_r(resumeCopy, delimiter, &resumeCopy))){
        char* key = strtok(token, ":");
        char* value = strtok(NULL, ":");
        if(strcmp(key, "Name")==0){
            char* name = strtok(value, "\n");
            insertNode(head, createNode(name, "", "", "", ""));
        }else if(strcmp(key, "Email")==0){
            strcpy((*head)->email, value);
        }else if(strcmp(key, "Phone")==0){
            strcpy((*head)->phone, value);
        }else if(strcmp(key, "Education")==0){
            strcpy((*head)->education, value);
        }else if(strcmp(key, "Experience")==0){
            strcpy((*head)->experience, value);
        }
    }
    free(resumeCopy);
}

int main(){
    char* resumeString = "Name: Jane Doe\nEmail: jane@example.com\nPhone: 123-456-7890\nEducation: Bachelor of Science in Computer Science\nExperience: Software Engineer for 3 years\n";
    struct resume* head = NULL;
    parseResume(resumeString, &head);
    printf("Name: %s\nEmail: %s\nPhone: %s\nEducation: %s\nExperience: %s\n", head->name, head->email, head->phone, head->education, head->experience);
    freeList(head);
    return 0;
}