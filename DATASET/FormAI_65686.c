//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    char skill[200][50];
    int skillCount;
    int experience;
    struct node *next;
};

void insert(struct node** head_ref, char s[200][50], int cnt, int exp)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->skill[0], s[0]);
    new_node->skillCount = cnt;
    new_node->experience = exp;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void search(struct node* head, char s[])
{
    int found = 0;
    struct node* current = head;
    while(current != NULL){
        for(int i=0; i<current->skillCount;i++){
            if(strcmp(current->skill[i], s)==0){
                printf("Found at experience level %d\n", current->experience);
                found = 1;
            }
        }
        current = current->next;
    }
    if(found==0) printf("Skill not found\n");
}

int main()
{
    char skills[3][50] = {"C", "Java", "Python"};
    struct node* head = NULL;
    insert(&head, skills, 3, 2);
    char skill_to_search[50];
    printf("Enter skill to search: ");
    scanf("%s", skill_to_search);
    search(head, skill_to_search);
    return 0;
}