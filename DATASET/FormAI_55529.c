//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>

// define a struct to hold user information
struct user_info{
    char name[20];
    int age;
    char gender[10];
    float weight;
    float height;
};

// function prototypes
float calculate_bmi(float weight, float height);
void display_bmi(float bmi);
void log_data(struct user_info user, float bmi);

int main(){
    // declare a user_info variable to hold user data and initialize it
    struct user_info user = {"John", 25, "Male", 80, 1.8};

    // calculate the user's BMI
    float bmi = calculate_bmi(user.weight, user.height);

    // display the user's BMI
    display_bmi(bmi);

    // log the user's data
    log_data(user, bmi);

    return 0;
}

// function to calculate the user's BMI
float calculate_bmi(float weight, float height){
    return weight / (height * height);
}

// function to display the user's BMI
void display_bmi(float bmi){
    printf("Your BMI is: %.2f\n", bmi);
    if(bmi < 18.5){
        printf("You are underweight.\n");
    } else if(bmi >= 18.5 && bmi < 25){
        printf("You are normal weight.\n");
    } else if(bmi >= 25 && bmi < 30){
        printf("You are overweight.\n");
    } else{
        printf("You are obese.\n");
    }
}

// function to log the user's data
void log_data(struct user_info user, float bmi){
    // open the log file in append mode
    FILE *log_file = fopen("user_log.txt", "a");

    // write the user's data to the log file
    fprintf(log_file, "Name: %s, Age: %d, Gender: %s, Weight: %.2f kg, Height: %.2f m, BMI: %.2f\n", user.name, user.age, user.gender, user.weight, user.height, bmi);

    // close the log file
    fclose(log_file);
}