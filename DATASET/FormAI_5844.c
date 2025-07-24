//FormAI DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>

struct Employee {
   char name[30];
   int age;
   float salary;
};

void bubbleSort(struct Employee employeeArr[], int n){
    struct Employee temp;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(employeeArr[j].salary > employeeArr[j+1].salary){
                temp = employeeArr[j];
                employeeArr[j] = employeeArr[j+1];
                employeeArr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    printf("Enter the number of employees:\n");
    scanf("%d", &n);

    struct Employee employeeArr[n];
    for(i = 0; i < n; i++){
        printf("Enter the name, age and salary for employee %d: ", i+1);
        scanf("%s %d %f", employeeArr[i].name, &employeeArr[i].age, &employeeArr[i].salary);
    }

    printf("Before sorting:\n");
    for(i = 0; i < n; i++){
        printf("Employee %d - Name: %s, Age: %d, Salary: %f\n",i+1, employeeArr[i].name, employeeArr[i].age, employeeArr[i].salary);
    }
  
    bubbleSort(employeeArr, n);
  
    printf("\nAfter sorting based on salary:\n");
    for(i = 0; i < n; i++){
        printf("Employee %d - Name: %s, Age: %d, Salary: %f\n",i+1, employeeArr[i].name, employeeArr[i].age, employeeArr[i].salary);
    }

    return 0;
}