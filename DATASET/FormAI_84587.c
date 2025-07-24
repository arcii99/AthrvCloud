//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50 //maximum size of database

int main(){
    int choice, emp_id, i;
    char emp_name[20], emp_email[30], emp_contact[15];
    int emp_salary;

    struct Employee {
        int id;
        char name[20];
        char email[30];
        char contact[15];
        int salary;
    };

    struct Employee database[SIZE];

    //initializing the database
    for(i=0; i<SIZE; i++){
        database[i].id = 0;
        strcpy(database[i].name, "");
        strcpy(database[i].email, "");
        strcpy(database[i].contact, "");
        database[i].salary = 0;
    }

    while(1){
        printf("\n--------------------------");
        printf("\n     Database Menu");
        printf("\n--------------------------");
        printf("\n1. Add Employee");
        printf("\n2. View All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Remove Employee by ID");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            // Adding an employee to the database

                //Checking if the database is already full
                for(i=0; i<SIZE; i++){
                    if(database[i].id == 0){
                        break;
                    }
                }
                if(i == SIZE) {
                    printf("\nDatabase is full.\n");
                    break;
                }

                printf("\nEnter Employee ID: ");
                scanf("%d", &emp_id);

                //Checking if the ID already exists in the database
                for(int j=0; j<i; j++){
                    if(database[j].id == emp_id){
                        printf("\nEmployee with ID '%d' already exists in the database.\n", emp_id);
                        goto end;
                    }
                }

                printf("Enter Employee Name: ");
                scanf("%s", emp_name);

                printf("Enter Employee Email: ");
                scanf("%s", emp_email);

                printf("Enter Employee Contact: ");
                scanf("%s", emp_contact);

                printf("Enter Employee Salary: ");
                scanf("%d", &emp_salary);

                //Adding the employee to the database
                database[i].id = emp_id;
                strcpy(database[i].name, emp_name);
                strcpy(database[i].email, emp_email);
                strcpy(database[i].contact, emp_contact);
                database[i].salary = emp_salary;

                printf("\nEmployee added to the database successfully.\n");

                end:
                break;

            case 2:
            //Displaying all employees in the database
                printf("\n-------------------------------------");
                printf("\n| ID\t|\tName\t|\tSalary   |");
                printf("\n-------------------------------------");
                for(i=0; i<SIZE; i++){
                    if(database[i].id != 0){
                        printf("\n| %d\t|\t%s\t|\t%d |", database[i].id, database[i].name, database[i].salary);
                    }
                }
                printf("\n-------------------------------------");
                break;

            case 3:
            //Searching an employee by ID
                printf("Enter Employee ID to search: ");
                scanf("%d", &emp_id);
                for(i=0; i<SIZE; i++){
                    if(database[i].id == emp_id){
                        printf("\n| ID\t|\tName\t|\tEmail\t\t|   Contact   |\tSalary   |");
                        printf("\n------------------------------------------------------------------------------");
                        printf("\n| %d\t|\t%s\t|\t%s\t|   %s   |\t%d |", database[i].id, database[i].name, database[i].email, database[i].contact, database[i].salary);
                        printf("\n------------------------------------------------------------------------------");
                        break;
                    }
                }
                if(i == SIZE){
                    printf("\nEmployee with ID '%d' not found in the database.\n", emp_id);
                }
                break;

            case 4:
            //Removing an employee by ID
                printf("Enter Employee ID to remove: ");
                scanf("%d", &emp_id);
                for(i=0; i<SIZE; i++){
                    if(database[i].id == emp_id){
                        database[i].id = 0;
                        strcpy(database[i].name, "");
                        strcpy(database[i].email, "");
                        strcpy(database[i].contact, "");
                        database[i].salary = 0;
                        printf("\nEmployee with ID '%d' removed from the database.\n", emp_id);
                        break;
                    }
                }
                if(i == SIZE){
                    printf("\nEmployee with ID '%d' not found in the database.\n", emp_id);
                }
                break;

            case 5:
            //Exiting the menu
                printf("\nExiting...");
                exit(0);

            default:
            //Invalid choice
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}