//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include<stdio.h>
#include<string.h>

//function to convert date from natural language to numerical
void dateConverter(char dateString[]){
    char *month_dict[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year, month, day;

    //splitting the input string to get individual values
    char *day_str = strtok(dateString, " ");
    char *month_str = strtok(NULL, " ");
    char *year_str = strtok(NULL, " ");

    //converting month string to month index
    for(int i=0; i<12; i++){
        if(strcmp(month_str, month_dict[i]) == 0){
            month = i + 1;
            break;
        }
    }

    year = atoi(year_str);
    day = atoi(day_str);

    //printing the numerical date
    printf("Numerical date: %02d/%02d/%d\n", month, day, year);
}

int main(){
    char dateString[100];

    //asking the user to input the natural language date
    printf("Enter the date in natural language (Example: Twentieth June Two Thousand and Twenty One): ");
    fgets(dateString, sizeof(dateString), stdin);

    //converting the date to numerical format
    dateConverter(dateString);

    return 0;
}