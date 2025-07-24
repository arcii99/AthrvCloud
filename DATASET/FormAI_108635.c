//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5
#define ELEVATOR_MAX_CAPACITY 7

bool is_elevator_direction_up = true;
bool is_elevator_stopped = true;
bool person_wanting_to_go_up[MAX_FLOORS] = {0}; 
bool person_wanting_to_go_down[MAX_FLOORS] = {0}; 
bool person_in_elevator_going_up[MAX_FLOORS] = {0}; 
bool person_in_elevator_going_down[MAX_FLOORS] = {0};

int num_people_waiting[MAX_FLOORS] = {0}; 
int num_people_in_elevator = 0;
int elevator_current_floor = 0; 
int elevator_target_floor = 0; 

void add_person_to_floor(int floor) {
    srand(time(0)); //to get random number
    int want_go_up = rand() % 2;
    if(want_go_up) {
        person_wanting_to_go_up[floor] = true;
    } else {
        person_wanting_to_go_down[floor] = true;
    }
    num_people_waiting[floor]++;
}

void add_persons_to_all_floors() {
    for(int floor=0; floor<MAX_FLOORS; floor++) {
        int num_people = rand() % MAX_PEOPLE;
        for(int i=0; i<num_people; i++) {
            add_person_to_floor(floor);
        }
    }
}

bool is_elevator_full() {
    return num_people_in_elevator == ELEVATOR_MAX_CAPACITY;
}

bool is_person_going_up_waiting_in_floor(int floor) {
    return person_wanting_to_go_up[floor] && !person_in_elevator_going_up[floor];
}

bool is_person_going_down_waiting_in_floor(int floor) {
    return person_wanting_to_go_down[floor] && !person_in_elevator_going_down[floor];
}

bool can_elevator_go_up(int floor) {
    if(!is_elevator_direction_up) {
        return false;
    }
    for(int i=elevator_current_floor+1; i<=floor; i++) {
        if(is_person_going_down_waiting_in_floor(i)) {
            return false;
        }
    }
    return true;
}

bool can_elevator_go_down(int floor) {
    if(is_elevator_direction_up) {
        return false;
    }
    for(int i=elevator_current_floor-1; i>=floor; i--) {
        if(is_person_going_up_waiting_in_floor(i)) {
            return false;
        }
    }
    return true;
}

bool can_elevator_stop_at_floor(int floor) {
    if(is_elevator_full()) {
        return false;
    } else if(elevator_current_floor == floor) {
        return true;
    } else if(is_elevator_direction_up) {
        return can_elevator_go_up(floor);
    } else if(!is_elevator_direction_up) {
        return can_elevator_go_down(floor);
    }
}

void pick_people_from_floor() { // entering people into elevator
    for(int floor=0; floor<MAX_FLOORS; floor++) {
        if(elevator_current_floor == floor) {
            if(is_elevator_direction_up) {
                while(is_person_going_up_waiting_in_floor(floor) && !is_elevator_full()) {
                    person_in_elevator_going_up[floor] = true;
                    num_people_in_elevator++;
                    num_people_waiting[floor]--;
                }
            } else if(!is_elevator_direction_up) {
                while(is_person_going_down_waiting_in_floor(floor) && !is_elevator_full()) {
                    person_in_elevator_going_down[floor] = true;
                    num_people_in_elevator++;
                    num_people_waiting[floor]--;
                }
            }
        }
    }
}

void update_elevator_floor() {
    if(elevator_current_floor == 0) {
        is_elevator_direction_up = true;
    } else if(elevator_current_floor == MAX_FLOORS-1) {
        is_elevator_direction_up = false;
    }
    if(can_elevator_stop_at_floor(elevator_current_floor)) {
        is_elevator_stopped = true;
    } else {
        is_elevator_stopped = false;
        if(is_elevator_direction_up) {
            elevator_target_floor++;
        } else if(!is_elevator_direction_up) {
            elevator_target_floor--;
        }
    }
    elevator_current_floor = elevator_target_floor;
}

void drop_people_to_floor() { // leaving people from elevator
    for(int floor=0; floor<MAX_FLOORS; floor++) {
        if(elevator_current_floor == floor) {
            if(is_elevator_direction_up) {
                while(person_in_elevator_going_up[floor]) {
                    person_in_elevator_going_up[floor] = false;
                    num_people_in_elevator--;
                }
            } else if(!is_elevator_direction_up) {
                while(person_in_elevator_going_down[floor]) {
                    person_in_elevator_going_down[floor] = false;
                    num_people_in_elevator--;
                }
            }
        }
    }
}

int main() {
    add_persons_to_all_floors();
    while(true) {
        printf("\nElevator Stopped at Floor %d. ", elevator_current_floor+1);
        pick_people_from_floor();
        drop_people_to_floor();

        update_elevator_floor();
        if(is_elevator_stopped) {
            printf("Elevator Opened. ");
            if(num_people_in_elevator > 0) {
                printf("Total %d People Entered. ", num_people_in_elevator);
                if(is_elevator_direction_up) {
                    printf("Going UP. ");
                } else if(!is_elevator_direction_up) {
                    printf("Going DOWN. ");
                }
            }
            if(num_people_in_elevator == 0) {
                printf("No One Entered. ");
                if(is_elevator_direction_up) {
                    printf("Going UP. ");
                } else if(!is_elevator_direction_up) {
                    printf("Going DOWN. ");
                }
            }
        } else {
            printf("Elevator is moving from Floor %d to Floor %d. ", elevator_current_floor+1, elevator_target_floor+1);
        }
        if(num_people_in_elevator > 0) {
            printf("Total %d People Inside.", num_people_in_elevator);
        } else {
            printf("Elevator is Empty.");
        }
        if(num_people_waiting[elevator_current_floor] > 0) {
            printf(" Total %d People Waiting to Enter on the Same Floor. ", num_people_waiting[elevator_current_floor]);
        } else {
            printf(" No One Waiting to Enter on the Same Floor. ");
        }
        printf("\n");
        sleep(1); //So That User Can Read Above Output Easily
    }
    return 0;
}