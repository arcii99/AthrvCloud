//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 100 // Maximum number of bags that can be processed
#define MAX_WEIGHT 30 // Max weight of each bag
#define MAX_FLIGHTS 10 // Maximum number of flights in airport
#define MAX_TERMINALS 5 // Maximum number of terminals in airport
#define MAX_EMPLOYEES 20 // Maximum number of employees that can handle baggage
#define MAX_DELAY 6 // Maximum delay time for a flight in minutes

typedef struct {
    int flight_id;
    int terminal;
    int num_bags;
    int total_weight;
    int bags_processed;
    bool is_delayed;
} Flight;

typedef struct {
    int employee_id;
    int terminal;
    int bags_handled;
    int total_weight_handled;
} Employee;

// Function prototypes
void simulate_baggage_handling(Flight flights[], Employee employees[]);
void generate_flights(Flight flights[]);
void display_flights(Flight flights[]);
void generate_employees(Employee employees[]);
void display_employees(Employee employees[]);
int get_available_employee(Employee employees[], int terminal);
int get_delay_time();
int get_baggage_weight();
void process_flight(Flight *flight, Employee employees[]);
bool is_terminal_busy(Employee employees[], int terminal);

int main() {
    srand(time(NULL));
    Flight flights[MAX_FLIGHTS];
    Employee employees[MAX_EMPLOYEES];
    generate_flights(flights);
    generate_employees(employees);
    printf("Initial flights:\n");
    display_flights(flights);
    printf("\nInitial employees:\n");
    display_employees(employees);
    printf("\nStarting simulation...\n");
    simulate_baggage_handling(flights, employees);
    printf("\nSimulation complete.\n");
    printf("\nFinal flights:\n");
    display_flights(flights);
    printf("\nFinal employees:\n");
    display_employees(employees);
    return 0;
}

void simulate_baggage_handling(Flight flights[], Employee employees[]) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        Flight *flight = &flights[i];
        if (flight->is_delayed) {
            int delay_time = get_delay_time();
            printf("Flight %d from terminal %d is delayed by %d minutes.\n", flight->flight_id, flight->terminal, delay_time);
            sleep(delay_time); // Simulate delay
        }
        int j, num_bags_total = flight->num_bags;
        int bags_processed_total = 0;
        while (bags_processed_total < num_bags_total) {
            int available_employee = get_available_employee(employees, flight->terminal);
            if (available_employee == -1) {
                printf("All employees busy in terminal %d. Waiting...\n", flight->terminal);
                sleep(1); // Hang for 1 second
                continue;
            }
            int bags_remaining = num_bags_total - bags_processed_total;
            int num_bags_to_process = (bags_remaining > 3) ? rand() % 3 + 1 : bags_remaining; // Process 1 to 3 bags
            int total_weight_to_process = 0;
            for (j = 0; j < num_bags_to_process; j++) {
                int baggage_weight = get_baggage_weight();
                total_weight_to_process += baggage_weight;
            }
            // Check if weight exceeds maximum limit
            if (total_weight_to_process + flight->total_weight > MAX_WEIGHT * num_bags_total) {
                printf("Flight %d from terminal %d exceeded maximum weight limit. Terminating...\n", flight->flight_id, flight->terminal);
                break;
            }
            // Process bags
            flight->total_weight += total_weight_to_process;
            flight->bags_processed += num_bags_to_process;
            bags_processed_total += num_bags_to_process;
            Employee *employee = &employees[available_employee];
            employee->bags_handled += num_bags_to_process;
            employee->total_weight_handled += total_weight_to_process;
            printf("Employee %d in terminal %d processed %d bags for flight %d from terminal %d.\n", 
                employee->employee_id, employee->terminal, num_bags_to_process, flight->flight_id, flight->terminal);
        }
        printf("Flight %d from terminal %d has completed processing %d bags.\n", flight->flight_id, flight->terminal, bags_processed_total);
    }
}

void generate_flights(Flight flights[]) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        Flight *flight = &flights[i];
        flight->flight_id = i + 1;
        flight->terminal = rand() % MAX_TERMINALS + 1;
        flight->num_bags = rand() % MAX_BAGGAGE + 1;
        flight->total_weight = 0;
        flight->bags_processed = 0;
        flight->is_delayed = rand() % 2;
    }
}

void display_flights(Flight flights[]) {
    printf("Flight ID\tTerminal\tNo. of Bags\tTotal Weight\tBags Processed\tDelayed?\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        Flight *flight = &flights[i];
        printf("%9d\t%7d\t%10d\t%12d\t%13d\t%7s\n", 
            flight->flight_id, flight->terminal, flight->num_bags, flight->total_weight, flight->bags_processed, 
            flight->is_delayed ? "Yes" : "No");
    }
}

void generate_employees(Employee employees[]) {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        Employee *employee = &employees[i];
        employee->employee_id = i + 1;
        employee->terminal = rand() % MAX_TERMINALS + 1;
        employee->bags_handled = 0;
        employee->total_weight_handled = 0;
    }
}

void display_employees(Employee employees[]) {
    printf("Employee ID\tTerminal\tBags Handled\tTotal Weight Handled\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        Employee *employee = &employees[i];
        printf("%11d\t%7d\t%12d\t%19d\n", 
            employee->employee_id, employee->terminal, employee->bags_handled, employee->total_weight_handled);
    }
}

int get_available_employee(Employee employees[], int terminal) {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        Employee *employee = &employees[i];
        if (employee->terminal == terminal && employee->bags_handled == 0) {
            return i;
        }
    }
    return -1;
}

int get_delay_time() {
    return rand() % MAX_DELAY + 1;
}

int get_baggage_weight() {
    return rand() % MAX_WEIGHT + 1;
}

void process_flight(Flight *flight, Employee employees[]) {
    if (is_terminal_busy(employees, flight->terminal)) {
        printf("All employees busy in terminal %d. Flight %d waiting...\n", flight->terminal, flight->flight_id);
        return;
    }
    int num_bags_to_process = rand() % flight->num_bags + 1;
    int total_weight_to_process = 0;
    for (int i = 0; i < num_bags_to_process; i++) {
        int baggage_weight = rand() % MAX_WEIGHT + 1;
        total_weight_to_process += baggage_weight;
    }
    // Check if weight exceeds maximum limit
    if (total_weight_to_process + flight->total_weight > MAX_WEIGHT * flight->num_bags) {
        printf("Flight %d exceeded maximum weight limit. Terminating...\n", flight->flight_id);
        return;
    }
    // Process bags
    flight->total_weight += total_weight_to_process;
    flight->bags_processed += num_bags_to_process;
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        Employee *employee = &employees[i];
        if (employee->terminal == flight->terminal && employee->bags_handled == 0) {
            employee->bags_handled = num_bags_to_process;
            employee->total_weight_handled += total_weight_to_process;
            printf("Employee %d processed %d bags for Flight %d from terminal %d.\n", employee->employee_id, num_bags_to_process, flight->flight_id, flight->terminal);
            break;
        }
    }
}

bool is_terminal_busy(Employee employees[], int terminal) {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        Employee *employee = &employees[i];
        if (employee->terminal == terminal && employee->bags_handled == 0) {
            return false;
        }
    }
    return true;
}