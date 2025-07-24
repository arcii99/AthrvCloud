//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Database structure */
struct Database {
    int id;
    char name[50];
    int age;
    float salary;
};

int main() {
    int option, i;
    struct Database employee[10]; //Can store upto 10 employees

    printf("Welcome to Employee Database Simulation Program!\n");

    while(1) { //Loop until program ends
        //Print the options
        printf("Choose an option: \n");
        printf("1. Add Employee Details\n");
        printf("2. Show All Employee Details\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit Program\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                //Add employee details
                for(i=0;i<10;i++) { //Check for the empty space in the database
                    if(employee[i].id==0) { //If empty found
                        printf("Enter Employee ID: ");
                        scanf("%d",&employee[i].id);
                        printf("Enter Employee Name: ");
                        scanf("%s",employee[i].name);
                        printf("Enter Employee Age: ");
                        scanf("%d",&employee[i].age);
                        printf("Enter Employee Salary: ");
                        scanf("%f",&employee[i].salary);
                        printf("\nEmployee Details Added Successfully!\n\n");
                        break;
                    }
                }
                if(i==10) {
                    printf("Database is full!! Please delete some employee details to add new details.\n\n");
                }
                break;

            case 2:
                //Show all employee details
                printf("\n******************* Employee Details - Database *******************\n");
                printf("|-------------|------------------|---------|------------|\n");
                printf("| Employee ID |    Employee Name |   Age   |    Salary  |\n");
                printf("|-------------|------------------|---------|------------|\n");
                for(i=0;i<10;i++) { //Check for the empty space in the database
                    if(employee[i].id!=0) { //If not empty
                        printf("|    %-8d |    %-14s |  %-6d | $%-9.2f |\n",employee[i].id,employee[i].name,employee[i].age,employee[i].salary);
                        printf("|-------------|------------------|---------|------------|\n");
                    }
                }
                printf("\n");

                break;

            case 3:
                //Search employee by ID
                int id,flag=0;
                printf("Enter the Employee ID you want to search: ");
                scanf("%d",&id);
                for(i=0;i<10;i++) { //Loop through database
                    if(employee[i].id==id) { //If found the requested ID
                        printf("Employee Details: \n");
                        printf("Employee ID: %d\nEmployee Name: %s\nEmployee Age: %d\nEmployee Salary: $%.2f\n",employee[i].id,employee[i].name,employee[i].age,employee[i].salary);
                        printf("\n");
                        flag=1; //Set the flag as 1 (employee found)
                        break;
                    }
                }
                if(flag==0)
                    printf("Employee with ID %d not found.\n\n",id);

                break;

            case 4:
                //Exit the program
                printf("Thank you for using the Employee Database Simulation Program!\n");
                exit(0);

            default:
                //Invalid input
                printf("Invalid input, Please try again!\n\n");
                break;
        }
    }
    return 0;
}