//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_heading(){
    printf("\n\t\t\tC Random Conspiracy Theory Generator\n\n");
}

char* get_subject(){
    char *subjects[]={"Aliens", "Illuminati", "Deep State", "Free Masons", \
    "Reptilians", "New World Order", "Area 51", "Chemtrails", "Big Pharma", "Bill Gates"};
    return subjects[rand()%10];
}

char* get_verbs(){
    char *verbs[]={"are controlling", "are manipulating", "are brainwashing", \
    "are stealing", "are hiding", "are poisoning", "are surveilling", "are testing", "are implanting", "are infiltrating"};
    return verbs[rand()%10];
}

char* get_objects(){
    char *objects[]={"our minds", "our bodies", "our society", \
    "our elections", "our media", "our food", "our water", "our air", "our weather", "our technology"};
    return objects[rand()%10];
}

void print_conspiracy(){
    char *subject=get_subject();
    char *verb=get_verbs();
    char *object=get_objects();
    printf("%s %s %s.\n", subject, verb, object);
}

int main(){
    srand(time(NULL));
    char user_answer;
    print_heading();
    do {
        print_conspiracy();
        printf("Do you want to know more conspiracies? (y/n): ");
        scanf(" %c", &user_answer);
    }while(user_answer=='y' || user_answer=='Y');
    printf("\n\t\t\tThank you for using C Random Conspiracy Theory Generator.\n\n");
    return 0;
}