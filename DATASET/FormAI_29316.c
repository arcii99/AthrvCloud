//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char* data;
    struct node* next;
};

struct node* head = NULL;

void insert(char* data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void display(){
    struct node* ptr = head;
    while(ptr!=NULL){
        printf("%s\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    char str[1000];
    int count = 0;
    printf("Enter your resume:\n");
    fgets(str, 1000, stdin);
    char* token = strtok(str, " ");
    while(token!=NULL){
        if(strstr(token, "C") || strstr(token, "c")){
            insert(token);
            count++;
        }
        token = strtok(NULL, " ");
    }
    if(count==0){
        printf("No instances of C found in your resume\n");
    }
    else{
        printf("%d instances of the word C found in your resume. They are:\n", count);
        display();
    }
    return 0;
}