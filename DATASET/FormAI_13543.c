//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

int main(){
    int steps;
    int heart_rate;
    int calories_burnt;
    char *username = (char*)malloc(sizeof(char)*50);
    char decision;

    printf("Welcome to the Paranoid Fitness Tracker! Please enter your username: ");
    scanf("%s", username);
    printf("Hello %s, today could be your last day on this planet. Let's make sure you are getting enough exercise to keep your heart strong and healthy.\n", username);
    printf("Do you want to continue with the paranoia tracking? (y/n)\n");
    scanf(" %c", &decision);
    
    if(decision == 'y' || decision == 'Y'){
        printf("\nGreat! Keep in mind that the government is always watching and tracking your every move. But with this fitness tracker, you can outsmart them and stay in control.\n");
        printf("Let's start by inputting your daily stats:\n");
        printf("How many steps did you take today?: ");
        scanf("%d", &steps);
        printf("Remember to always look over your shoulder and avoid danger if you are walking too much. Your step count for today is: %d\n", steps);
        printf("What was your average heart rate today?: ");
        scanf("%d", &heart_rate);
        printf("Good job monitoring your heart rate. Remember, the higher your heart rate, the more likely it is the government is monitoring you. Your heart rate for today is: %d\n", heart_rate);
        calories_burnt = steps*0.04; // assume calories burnt is 0.04 * steps taken
        printf("You burnt approximately %d calories today.\n", calories_burnt);
        printf("Stay vigilant and keep exercising. You never know who is watching.\n");
    }
    else{
        printf("No problem! Just remember, even if you don't want to track your fitness, the government is always watching you.\n");
        printf("Goodbye %s,\n", username);
    }

    free(username);
    return 0;
}