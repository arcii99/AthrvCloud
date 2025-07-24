//FormAI DATASET v1.0 Category: Database querying ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char name[30];
    int age;
    int salary;
} Employee;

int main(){
    int n=5;  // number of employees
    Employee emp[n];
    int i;
    
    // Initializing employee records
        
    emp[0].id=101; strcpy(emp[0].name,"John"); emp[0].age=25; emp[0].salary=32000;
    emp[1].id=102; strcpy(emp[1].name,"Sam"); emp[1].age=30; emp[1].salary=45000;
    emp[2].id=103; strcpy(emp[2].name,"Mary"); emp[2].age=27; emp[2].salary=37000;
    emp[3].id=104; strcpy(emp[3].name,"Bob"); emp[3].age=22; emp[3].salary=28500;
    emp[4].id=105; strcpy(emp[4].name,"Alice"); emp[4].age=28; emp[4].salary=40000;

    // Asking user to input the employee ID to search
    
    int searchID;
    printf("Enter the employee ID to search: ");
    scanf("%d",&searchID);

    // Searching and displaying employee record
    
    for(i=0;i<n;i++){
        if(emp[i].id==searchID){
            printf("\nEmployee ID: %d\n",emp[i].id);
            printf("Name: %s\n",emp[i].name);
            printf("Age: %d\n",emp[i].age);
            printf("Salary: %d\n",emp[i].salary);
            break;
        }
    }
    if(i==n){
        printf("\nEmployee with ID %d not found!\n",searchID);
    }
    return 0;
}