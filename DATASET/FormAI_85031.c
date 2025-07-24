//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

int main() {
    int i, j;
    int elevators[NUM_ELEVATORS];
    int floors[NUM_FLOORS];
    int current_floor[NUM_ELEVATORS] = { 0 };
    int current_direction[NUM_ELEVATORS] = { 1 };
    char name[NUM_ELEVATORS] = { 'A', 'B', 'C' };
    int destination[NUM_ELEVATORS] = { -1 };

    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i] = 1;
    }

    for (i = 0; i < NUM_FLOORS; i++) {
        floors[i] = 0;
    }

    for (i = 0; i < NUM_ELEVATORS; i++) {
        destination[i] = -1;
    }

    while (1) {
        for (i = 0; i < NUM_ELEVATORS; i++) {
            if (destination[i] == -1) {
                printf("Elevator %c is idle\n", name[i]);
                continue;
            }

            if (destination[i] == current_floor[i]) {
                printf("Elevator %c has reached the destination floor %d\n", name[i], current_floor[i]);
                destination[i] = -1;
                elevators[i] = 1;
            }
            else {
                printf("Elevator %c going to floor %d\n", name[i], destination[i]);
                elevators[i] = 0;
                if (destination[i] > current_floor[i]) {
                    current_direction[i] = 1;
                    current_floor[i]++;
                }
                else {
                    current_direction[i] = -1;
                    current_floor[i]--;
                }
                printf("Elevator %c is now at floor %d\n", name[i], current_floor[i]);
            }
        }

        for (i = 0; i < NUM_ELEVATORS; i++) {
            if (elevators[i]) {
                int closest_floor = -1;
                int closest_distance = NUM_FLOORS;
                for (j = 0; j < NUM_FLOORS; j++) {
                    if (floors[j]) {
                        int distance = abs(current_floor[i] - j);
                        if (distance < closest_distance) {
                            closest_floor = j;
                            closest_distance = distance;
                        }
                    }
                }
                if (closest_floor != -1) {
                    printf("Sending elevator %c to floor %d\n", name[i], closest_floor);
                    destination[i] = closest_floor;
                    floors[closest_floor] = 0;
                }
            }
        }

        if (rand() % 10 == 0) {
            int floor = rand() % NUM_FLOORS;
            printf("Someone is waiting on floor %d\n", floor);
            floors[floor] = 1;
        }

        sleep(1);
    }

    return 0;
}