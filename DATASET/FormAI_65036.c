//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50 // maximum number of bags that can be handled
#define MAX_EMPLOYEES 5 // maximum number of employees that can handle bags

typedef struct {
    int flightNumber;
    int numBags;
} Flight;

typedef struct {
    int id;
    int capacity;
    int numBags;
    int flightNumbers[MAX_BAGS];
} Employee;

void assignBags(Employee *employeeArr, Flight *flightArr, int numEmployees, int numFlights) {
    int i, j, k;
    srand(time(NULL)); //seed random number generator
    for (i = 0; i < numFlights; i++) {
        printf("\n\nAssigning baggage for Flight %d with %d bags:\n", flightArr[i].flightNumber, flightArr[i].numBags);
        int bagsLeft = flightArr[i].numBags; // initialize bags left to be processed
        k = 0; // index of currently assigned flight number for employee

        while (bagsLeft > 0) {
            // loop through employees and assign bags
            for (j = 0; j < numEmployees; j++) {
                // check if employee is available and has capacity for another bag
                if (employeeArr[j].numBags < employeeArr[j].capacity) {
                    // randomly assign between 1 and 3 bags to employee
                    int numBagsAssign = (rand() % 3) + 1;
                    if (numBagsAssign > bagsLeft) numBagsAssign = bagsLeft;

                    printf("Employee %d assigned %d bags from Flight %d\n", employeeArr[j].id, numBagsAssign, flightArr[i].flightNumber);

                    // update employee and flight bag information
                    employeeArr[j].numBags += numBagsAssign;
                    bagsLeft -= numBagsAssign;
                    while (numBagsAssign > 0) {
                        employeeArr[j].flightNumbers[k++] = flightArr[i].flightNumber;
                        numBagsAssign--;
                    }
                }
            }
        }
    }
}

int main() {
    Flight flights[] = {{1001, 17}, {1015, 25}, {1023, 32}, {1037, 12}, {1049, 22}};
    int numFlights = sizeof(flights) / sizeof(flights[0]);

    Employee employees[] = {{1, 10}, {2, 8}, {3, 12}, {4, 9}, {5, 7}};
    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    assignBags(employees, flights, numEmployees, numFlights);

    // print out final assigned flight numbers for each employee
    printf("\n\nFinal assigned flight numbers per employee:\n");
    int i, j;
    for (i = 0; i < numEmployees; i++) {
        printf("Employee %d assigned bags for Flights: ", employees[i].id);
        for (j = 0; j < employees[i].numBags; j++) {
            printf("%d ", employees[i].flightNumbers[j]);
        }
        printf("\n");
    }

    return 0;
}