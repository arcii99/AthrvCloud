//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct candidate{
    char name[30];
    int count;
};

void addCandidate(struct candidate c[], int n);
void castVote(struct candidate c[], int n);
void displayResult(struct candidate c[], int n);
int validateInput(char input[]);

int main(){
    int n, option;
    char input[10];
    printf("\t\tWELCOME TO THE ELECTRONIC VOTING SYSTEM\n\n");
    while(1){
        printf("Enter the number of candidates: ");
        fgets(input, sizeof(input), stdin);
        n = validateInput(input);
        if(n > 0){
            break;
        }
        printf("Invalid input! Please try again.\n\n");
    }
    struct candidate c[n];

    printf("Candidate Registration:\n");
    addCandidate(c, n);

    while(1){
        printf("\n");
        printf("1. Cast Vote\n");
        printf("2. Display Result\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        option = validateInput(input);
        
        switch(option){
            case 1:
                castVote(c, n);
                break;
            case 2:
                displayResult(c, n);
                break;
            case 3:
                printf("\nThank you for using the electronic voting system.\n\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}

void addCandidate(struct candidate c[], int n){
    for(int i=0; i<n; i++){
        printf("Enter the name of candidate %d: ", i+1);
        fgets(c[i].name, sizeof(c[i].name), stdin);
        c[i].count = 0;
    }
    printf("Registration Successful!\n\n");
}

void castVote(struct candidate c[], int n){
    int choice;
    char input[10];
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d. %s", i+1, c[i].name);
    }
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    choice = validateInput(input);
    if(choice >= 1 && choice <= n){
        c[choice-1].count++;
        printf("\nThank you for casting your vote!\n\n");
    }
    else{
        printf("\nInvalid input! Please try again.\n\n");
    }
}

void displayResult(struct candidate c[], int n){
    struct candidate temp;
    printf("\nThe election results:\n");
    printf("Name\t\tNumber of Votes\n");
    printf("-------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%d\n", c[i].name, c[i].count);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(c[j].count < c[j+1].count){
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
    printf("\nThe winner of the election is: %s\n\n", c[0].name);
}

int validateInput(char input[]){
    int valid = 1;
    int len = strlen(input);
    for(int i=0; i<len-1; i++){
        if(!isdigit(input[i])){
            valid = 0;
            break;
        }
    }
    if(valid){
        return atoi(input);
    }
    else{
        return -1;
    }
}