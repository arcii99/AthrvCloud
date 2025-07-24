//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define MAX_THREADS 4
#define MAX_SESSIONS 5
#define MAX_EXERCISES 3

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    int sets;
    int reps;
    int weight;
} Exercise;

typedef struct {
    Time start_time;
    Time end_time;
    Exercise exercises[MAX_EXERCISES];
} Session;

typedef struct {
    int id;
    char name[20];
    int age;
    char gender[10];
    float weight;
    float height;
    Session sessions[MAX_SESSIONS];
} User;

typedef struct {
    int count;
    User users[MAX_THREADS];
} FitnessTracker;

void print_exercise(Exercise exercise) {
    printf("Sets: %d\n", exercise.sets);
    printf("Reps: %d\n", exercise.reps);
    printf("Weight: %d\n", exercise.weight);
}

void print_session(Session session) {
    printf("Start Time: %d:%02d\n", session.start_time.hour, session.start_time.minute);
    printf("End Time: %d:%02d\n", session.end_time.hour, session.end_time.minute);
    for (int i = 0; i < MAX_EXERCISES; i++) {
        printf("\tExercise %d:\n", i+1);
        print_exercise(session.exercises[i]);
    }
}

void print_user(User user) {
    printf("ID: %d\n", user.id);
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Gender: %s\n", user.gender);
    printf("Weight: %f\n", user.weight);
    printf("Height: %f\n", user.height);
    printf("Sessions:\n");
    for (int i = 0; i < MAX_SESSIONS; i++) {
        printf("\tSession %d:\n", i+1);
        print_session(user.sessions[i]);
    }
}

void print_fitness_tracker(FitnessTracker tracker) {
    printf("Total Users: %d\n", tracker.count);
    for (int i = 0; i < tracker.count; i++) {
        printf("User %d:\n", i+1);
        print_user(tracker.users[i]);
    }
}

int add_user(FitnessTracker* tracker, User user) {
    if (tracker->count >= MAX_THREADS) {
        return -1; // Error: No more space in tracker
    }
    tracker->users[tracker->count] = user;
    tracker->count++;
    return 0; // Success
}

int main() {
    
    FitnessTracker tracker = {0}; // Initialize fitness tracker to empty

    User user1 = {1, "John", 25, "Male", 175.0f, 6.0f, {
        {{8, 30}, {10, 0}, {{3, 10, 100}, {3, 8, 120}, {3, 6, 130}}}, // Session 1
        {{15, 0}, {16, 0}, {{3, 12, 100}, {3, 10, 120}, {3, 8, 130}}}, // Session 2
        {{10, 0}, {12, 0}, {{3, 8, 100}, {3, 6, 120}, {3, 4, 130}}},   // Session 3
        {{18, 0}, {19, 0}, {{3, 6, 100}, {3, 4, 120}, {3, 2, 130}}},   // Session 4
        {{13, 0}, {14, 0}, {{3, 4, 100}, {3, 2, 120}, {3, 1, 130}}},   // Session 5
    }};

    User user2 = {2, "Jane", 30, "Female", 135.0f, 5.5f, {
        {{7, 30}, {9, 0}, {{3, 10, 50}, {3, 8, 60}, {3, 6, 70}}},   // Session 1
        {{18, 0}, {19, 0}, {{3, 12, 50}, {3, 10, 60}, {3, 8, 70}}},  // Session 2
        {{10, 0}, {11, 0}, {{3, 8, 50}, {3, 6, 60}, {3, 4, 70}}},    // Session 3
        {{14, 0}, {15, 0}, {{3, 6, 50}, {3, 4, 60}, {3, 2, 70}}},    // Session 4
        {{12, 0}, {13, 0}, {{3, 4, 50}, {3, 2, 60}, {3, 1, 70}}},    // Session 5
    }};

    User user3 = {3, "Bob", 35, "Male", 200.0f, 6.5f, {
        {{9, 0}, {10, 0}, {{3, 10, 150}, {3, 8, 160}, {3, 6, 170}}},  // Session 1
        {{16, 0}, {17, 0}, {{3, 12, 150}, {3, 10, 160}, {3, 8, 170}}}, // Session 2
        {{11, 0}, {12, 0}, {{3, 8, 150}, {3, 6, 160}, {3, 4, 170}}},   // Session 3
        {{19, 0}, {20, 0}, {{3, 6, 150}, {3, 4, 160}, {3, 2, 170}}},   // Session 4
        {{14, 0}, {15, 0}, {{3, 4, 150}, {3, 2, 160}, {3, 1, 170}}},   // Session 5
    }};

    int result1 = add_user(&tracker, user1);
    if (result1 == -1) {
        printf("Error: Fitness tracker is full!\n");
    } else {
        printf("Success: User added to fitness tracker.\n");
    }

    int result2 = add_user(&tracker, user2);
    if (result2 == -1) {
        printf("Error: Fitness tracker is full!\n");
    } else {
        printf("Success: User added to fitness tracker.\n");
    }

    int result3 = add_user(&tracker, user3);
    if (result3 == -1) {
        printf("Error: Fitness tracker is full!\n");
    } else {
        printf("Success: User added to fitness tracker.\n");
    }

    print_fitness_tracker(tracker);

    return 0;
}