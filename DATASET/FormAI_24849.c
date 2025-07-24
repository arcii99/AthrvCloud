//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct workout{
    char name[20];
    int sets;
    int reps;
} Workout;

typedef struct exercise{
    int id;
    char name[20];
    Workout workouts[5];
} Exercise;

typedef struct day{
    int id;
    char date[11];
    Exercise exercises[5];
} Day;

typedef struct tracker{
    Day days[7];
} Tracker;

void set_workout(Workout *w, char name[], int sets, int reps){
    strcpy(w->name, name);
    w->sets = sets;
    w->reps = reps;
}

void set_exercise(Exercise *e, int id, char name[]){
    e->id = id;
    strcpy(e->name, name);

    // set default workouts
    set_workout(&e->workouts[0], "Push-ups", 3, 10);
    set_workout(&e->workouts[1], "Squats", 3, 15);
}

void set_day(Day *d, int id, char date[]){
    d->id = id;
    strcpy(d->date, date);

    // set default exercises
    set_exercise(&d->exercises[0], 1, "Chest");
    set_exercise(&d->exercises[1], 2, "Legs");
}

void set_tracker(Tracker *t){
    // set default days
    set_day(&t->days[0], 1, "01/01/2022");
    set_day(&t->days[1], 2, "01/02/2022");
    set_day(&t->days[2], 3, "01/03/2022");
    set_day(&t->days[3], 4, "01/04/2022");
    set_day(&t->days[4], 5, "01/05/2022");
    set_day(&t->days[5], 6, "01/06/2022");
    set_day(&t->days[6], 7, "01/07/2022");
}

void print_workout(Workout w){
    printf("\n%s:\n", w.name);
    printf("Sets: %d\n", w.sets);
    printf("Reps: %d\n", w.reps);
}

void print_exercise(Exercise e){
    printf("\n%s:\n", e.name);

    for(int i = 0; i < 2; i++){
        print_workout(e.workouts[i]);
    }
}

void print_day(Day d){
    printf("\nDay %d - %s:\n", d.id, d.date);

    for(int i = 0; i < 2; i++){
        print_exercise(d.exercises[i]);
    }
}

void print_tracker(Tracker t){
    for(int i = 0; i < 7; i++){
        print_day(t.days[i]);
    }
}

int main(){
    Tracker t;

    // set tracker defaults
    set_tracker(&t);

    // print tracker
    print_tracker(t);

    return 0;
}