//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include<stdio.h>

int main(){
    //declare variables
    int month, day, year, julianDate;
    char response;
    
    do{
        //prompt user for date input
        printf("Enter month (1-12): ");
        scanf("%d", &month);
        printf("Enter day: ");
        scanf("%d", &day);
        printf("Enter year (yyyy): ");
        scanf("%d", &year);

        //check if date is valid
        if(month<1 || month>12 || day<1 || day>31){
            printf("Invalid date. Please try again.\n");
        }
        else{
            //calculate Julian Date
            julianDate = (1461 * (year + 4800 + (month - 14) / 12)) / 4 +
                        (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 -
                        (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;

            //print Julian Date
            printf("\nJulian Date: %d \n", julianDate);

            //convert Julian Date to Gregorian Date
            int L = julianDate + 68569;
            int N = (4 * L) / 146097;
            L = L - (146097 * N + 3) / 4;
            year = 4000 * (L + 1) / 1461001;
            L = L - (1461 * year) / 4 + 31;
            month = 80 * L / 2447;
            day = L - (2447 * month / 80);
            L = month / 11;
            month = month + 2 - (12 * L);
            year = 100 * (N - 49) + year + L;

            //print Gregorian Date
            printf("\nGregorian Date: %d/%d/%d \n", month, day, year);
        }

        //ask user if they want to convert another date
        printf("\nDo you want to convert another date? (y/n): ");
        scanf(" %c", &response);
    }while(response == 'y' || response == 'Y');

    return 0;
}