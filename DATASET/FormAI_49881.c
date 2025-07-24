//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_NAME_LENGTH 20   // Maximum allowed length of wifi name
#define MAX_RECORDS 200            // Maximum number of records allowed in wifi signal strength analysis

typedef struct{
    char wifi_name[MAX_WIFI_NAME_LENGTH];
    int signal_strength;
} wifi_data;

int main(){
    int num_records = 0;
    wifi_data records[MAX_RECORDS];
    char user_input[MAX_WIFI_NAME_LENGTH + 2];  // Adding two extra spaces for input formatting

    printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");

    while(num_records < MAX_RECORDS){
        printf("Please enter the name of the Wi-Fi network followed by comma and signal strength (0-100): \n");

        // Getting user input and parsing wifi name & signal strength.
        fgets(user_input, MAX_WIFI_NAME_LENGTH + 2, stdin);
        sscanf(user_input, "%[^,],%d", records[num_records].wifi_name, &records[num_records].signal_strength);

        if(records[num_records].signal_strength < 0 || records[num_records].signal_strength > 100){
            printf("Invalid signal strength value entered. Please enter valid signal strength (0-100)\n");
        }
        else{
            num_records++;
            printf("Record added successfully. Total records: %d\n", num_records);
        }

        printf("Enter 'q' to see signal strength analysis or press any other key to continue adding records.\n");

        char c = getchar();   // The previously entered 'return' character is consumed by this getchar
        if(c == 'q'){
            break;
        }
    }

    // Sorting wifi names in ascending order
    for(int i=0; i<num_records-1; i++){
        for(int j=i+1; j<num_records; j++){
            if(strcmp(records[i].wifi_name, records[j].wifi_name) > 0){
                wifi_data temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    // Calculating average signal strength for each wifi network
    int current_position = 0;
    int last_position = 0;
    char current_wifi_name[MAX_WIFI_NAME_LENGTH];
    int current_sum = 0;
    int num_occurrences = 0;
    while(current_position < num_records){
        strcpy(current_wifi_name, records[current_position].wifi_name);
        current_sum = 0;
        num_occurrences = 0;

        while(strcmp(records[current_position].wifi_name, current_wifi_name) == 0 && current_position < num_records){
            current_sum += records[current_position].signal_strength;
            num_occurrences++;
            current_position++;
        }

        int average_signal_strength = current_sum / num_occurrences;
        printf("Wi-Fi Network: %s \t Average signal strength: %d\n", current_wifi_name, average_signal_strength);
    }

    printf("Thank you for using Wi-Fi Signal Strength Analyzer.\n");
    return 0;
}