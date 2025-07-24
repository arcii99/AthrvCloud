//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50
#define NUM_CONVEYORS 3

struct Baggage {
    int id;
    char destination[3];
};

struct Conveyor {
    int id;
    struct Baggage *baggage;
};

struct Plane {
    char id[7];
    char destination[3];
    int baggage_count;
    struct Baggage *baggage_list[MAX_BAGGAGE];
};

void generate_baggage(struct Baggage *baggage, int id, char *destination) {
    baggage->id = id;
    strcpy(baggage->destination, destination);
}

void add_to_conveyor(struct Conveyor *conveyor, struct Baggage *baggage) {
    conveyor->baggage = baggage;
    printf("Baggage with ID %d added to conveyor with ID %d\n", baggage->id, conveyor->id);
}

void remove_from_conveyor(struct Conveyor *conveyor) {
    printf("Baggage with ID %d removed from conveyor with ID %d\n", conveyor->baggage->id, conveyor->id);
    conveyor->baggage = NULL;
}

void add_to_plane(struct Plane *plane, struct Baggage *baggage) {
    plane->baggage_list[plane->baggage_count] = baggage;
    plane->baggage_count++;
    printf("Baggage with ID %d added to plane with ID %s\n", baggage->id, plane->id);
}

int main() {
    srand(time(0));
    // Generate Conveyors
    struct Conveyor conveyors[NUM_CONVEYORS];
    for(int i=0; i<NUM_CONVEYORS; i++) {
        conveyors[i].id = i+1;
        conveyors[i].baggage = NULL;
    }

    // Generate Planes
    struct Plane planes[3];
    strcpy(planes[0].id, "AA1234");
    strcpy(planes[0].destination, "NYC");
    planes[0].baggage_count = 0;

    strcpy(planes[1].id, "DL5678");
    strcpy(planes[1].destination, "LAX");
    planes[1].baggage_count = 0;

    strcpy(planes[2].id, "UA9101");
    strcpy(planes[2].destination, "SFO");
    planes[2].baggage_count = 0;

    // Generate and Handle Baggage
    for (int i=1; i<=MAX_BAGGAGE; i++) {
        struct Baggage baggage;
        int dest_plane = rand() % 3;
        strcpy(baggage.destination, planes[dest_plane].destination);
        generate_baggage(&baggage, i, baggage.destination);

        if (conveyors[dest_plane].baggage == NULL) {
            add_to_conveyor(&conveyors[dest_plane], &baggage);
        }
        else {
            for(int j=0; j<NUM_CONVEYORS; j++) {
                if (conveyors[j].baggage == NULL) {
                    add_to_conveyor(&conveyors[j], &baggage);
                    break;
                }
            }
        }

        if (planes[dest_plane].baggage_count < MAX_BAGGAGE) {
            add_to_plane(&planes[dest_plane], &baggage);
            remove_from_conveyor(&conveyors[dest_plane]);
        }
    }

    return 0;
}