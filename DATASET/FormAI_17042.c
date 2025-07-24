//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Employee
{
    int empID;
    char empName[50];
    int salary;
};

struct Index
{
    int empID;      
    int offset;     
};

void create_data()
{
    struct Employee empArr[10] = {
        {201, "John Doe", 45000},
        {202, "Ella Smith", 58000},
        {203, "Mike Williams", 67000},
        {204, "Olivia Lee", 52000},
        {205, "Hannah Brown", 48000},
        {206, "Jacob Johnson", 60000},
        {207, "Sophie Davis", 52000},
        {208, "Emily White", 71000},
        {209, "Ryan Wilson", 53000},
        {210, "Aiden Greene", 65000}
    };

    FILE *fp = fopen("employeeData.dat", "wb");
    fwrite(empArr, sizeof(struct Employee), 10, fp);
    fclose(fp);
}

void create_index()
{
    FILE *fpData = fopen("employeeData.dat", "rb");
    FILE *fpIndex = fopen("employeeIndex.dat", "wb");

    struct Employee emp;
    struct Index idx;

    while(fread(&emp, sizeof(struct Employee), 1, fpData) > 0)
    {
        idx.empID = emp.empID;
        idx.offset = ftell(fpData) - sizeof(struct Employee);
        fwrite(&idx, sizeof(struct Index), 1, fpIndex);
    }

    fclose(fpData);
    fclose(fpIndex);
}

void display_data()
{
    FILE *fpData = fopen("employeeData.dat", "rb");

    struct Employee emp;

    printf("Displaying Employee data:\n");
    while(fread(&emp, sizeof(struct Employee), 1, fpData) > 0)
    {
        printf("Employee ID: %d, Name: %s, Salary: %d\n", emp.empID, emp.empName, emp.salary);
    }

    fclose(fpData);
}

void display_index()
{
    FILE *fpIndex = fopen("employeeIndex.dat", "rb");

    struct Index idx;

    printf("Displaying Index data:\n");
    while(fread(&idx, sizeof(struct Index), 1, fpIndex) > 0)
    {
        printf("Employee ID: %d, Offset: %d\n", idx.empID, idx.offset);
    }

    fclose(fpIndex);
}

void read_data(int empID)
{
    FILE *fpIndex = fopen("employeeIndex.dat", "rb");
    FILE *fpData = fopen("employeeData.dat", "rb");

    struct Index idx;
    struct Employee emp;

    int found = 0;

    while(fread(&idx, sizeof(struct Index), 1, fpIndex) > 0)
    {
        if(idx.empID == empID)
        {
            found = 1;
            fseek(fpData, idx.offset, SEEK_SET);
            fread(&emp, sizeof(struct Employee), 1, fpData);
            printf("Employee ID: %d, Name: %s, Salary: %d\n", emp.empID, emp.empName, emp.salary);
            break;
        }
    }

    if(!found)
    {
        printf("Employee data not found.\n");
    }

    fclose(fpIndex);
    fclose(fpData);
}

int main()
{
    printf("Creating Employee data...\n");
    create_data();

    printf("Creating Index...\n");
    create_index();

    printf("Displaying Employee data...\n");
    display_data();

    printf("Displaying Index data...\n");
    display_index();

    printf("Reading Employee data for ID 203...\n");
    read_data(203);

    return 0;
}