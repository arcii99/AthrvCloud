//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char favorite_color[10];
    int lucky_number;
} person;

int main() {
    // Create a database of surreal people
    person surreal_people[5];
    surreal_people[0].id = 1;
    sprintf(surreal_people[0].name, "Salvador Dali");
    sprintf(surreal_people[0].favorite_color, "melting gold");
    surreal_people[0].lucky_number = 666;

    surreal_people[1].id = 2;
    sprintf(surreal_people[1].name, "René Magritte");
    sprintf(surreal_people[1].favorite_color, "invisible pink");
    surreal_people[1].lucky_number = 13;

    surreal_people[2].id = 3;
    sprintf(surreal_people[2].name, "Max Ernst");
    sprintf(surreal_people[2].favorite_color, "mystic blue");
    surreal_people[2].lucky_number = 7;

    surreal_people[3].id = 4;
    sprintf(surreal_people[3].name, "Frida Kahlo");
    sprintf(surreal_people[3].favorite_color, "bloody red");
    surreal_people[3].lucky_number = 3;

    surreal_people[4].id = 5;
    sprintf(surreal_people[4].name, "Yayoi Kusama");
    sprintf(surreal_people[4].favorite_color, "dotted yellow");
    surreal_people[4].lucky_number = 8;

    // Query the database to find people whose lucky number is odd and favorite color is a surreal shade of green
    for (int i = 0; i < 5; i++) {
        if (surreal_people[i].lucky_number % 2 != 0 && strcmp(surreal_people[i].favorite_color, "enigmatic green") == 0) {
            printf("%s's ID is %d.\n", surreal_people[i].name, surreal_people[i].id);
        }
    }

    return 0;
}