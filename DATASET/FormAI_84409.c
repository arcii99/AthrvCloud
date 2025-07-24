//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include<stdio.h>
#include<string.h>

struct Contact{
    char name[20];
    char phone[20];
};

int main(){
    int n;
    printf("How many contacts you want to add?\n");
    scanf("%d",&n);
    struct Contact phoneBook[n];
    int i,j;
    for(i=0;i<n;i++){
        printf("Enter name for contact %d:\n",i+1);
        scanf("%s",phoneBook[i].name);
        printf("Enter phone number for contact %d:\n",i+1);
        scanf("%s",phoneBook[i].phone);
    }
    printf("\nPhone Book\n==========\n");
    for(i=0;i<n;i++){
        printf("%d. %s - %s\n",i+1,phoneBook[i].name,phoneBook[i].phone);
    }
    printf("\nSearch for a contact by name\n=========================\n");
    char searchName[20];
    printf("Enter the name you want to search for:\n");
    scanf("%s",searchName);
    int found=0;
    for(i=0;i<n;i++){
        if(strcmp(phoneBook[i].name,searchName)==0){
            printf("%s - %s\n",phoneBook[i].name,phoneBook[i].phone);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Sorry, no contact found with this name.\n");
    }
    return 0;
}