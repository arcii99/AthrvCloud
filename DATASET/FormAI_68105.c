//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_number;
    int check_in_day;
    int check_out_day;
};

void print_guest_info(struct guest* g) {
    printf("%s is staying in room number %d from day %d to day %d.\n", g->name, g->room_number, g->check_in_day, g->check_out_day);
}

int main() {
    struct guest romeo;
    struct guest juliet;
    strcpy(romeo.name, "Romeo");
    romeo.room_number = 101;
    romeo.check_in_day = 1;
    romeo.check_out_day = 3;
    strcpy(juliet.name, "Juliet");
    juliet.room_number = 102;
    juliet.check_in_day = 1;
    juliet.check_out_day = 3;

    printf("%s and %s fell in love at first sight.\n", romeo.name, juliet.name);
    printf("%s decided to book a room at the C Hotel in room number %d from day %d to day %d.\n", romeo.name, romeo.room_number, romeo.check_in_day, romeo.check_out_day);
    printf("%s also booked a room at the C Hotel in room number %d from day %d to day %d.\n", juliet.name, juliet.room_number, juliet.check_in_day, juliet.check_out_day);
    printf("%s and %s could not wait to see each other during their stay at the C Hotel.\n\n", romeo.name, juliet.name);

    printf("On day %d, %s arrived at the C Hotel.\n", romeo.check_in_day, romeo.name);
    printf("The receptionist checked %s into room number %d.\n", romeo.name, romeo.room_number);
    print_guest_info(&romeo);
    printf("\n");

    printf("On day %d, %s arrived at the C Hotel.\n", juliet.check_in_day, juliet.name);
    printf("The receptionist checked %s into room number %d.\n", juliet.name, juliet.room_number);
    print_guest_info(&juliet);
    printf("\n");

    printf("On day %d, %s could not contain his excitement any longer and decided to visit %s in her room.\n", romeo.check_in_day, romeo.name, juliet.name);
    printf("Unfortunately, %s was out exploring the city and was not in her room.\n", juliet.name);
    printf("%s left a note for %s and left her room.\n\n", romeo.name, juliet.name);

    printf("On day %d, %s returned to her room and found the note from %s.\n", juliet.check_in_day, juliet.name, romeo.name);
    printf("The note read: 'My dearest %s, I cannot wait to see you. Meet me at the hotel restaurant at 7pm tonight.'\n", juliet.name);
    printf("%s blushed with excitement and immediately got ready for her dinner with %s.\n\n", juliet.name, romeo.name);

    printf("On day %d, %s and %s had the most enchanting dinner at the C Hotel restaurant.\n", romeo.check_out_day, romeo.name, juliet.name);
    printf("Their love for each other grew stronger every moment they spent together at the C Hotel.\n");
    printf("They both decided to extend their stay at the C Hotel for a few more days.\n\n");

    printf("On day %d, %s and %s finally checked out of their rooms at the C Hotel.\n", romeo.check_out_day, romeo.name, juliet.name);
    printf("They both knew that they would never forget their magical experience at the C Hotel.\n");

    return 0;
}