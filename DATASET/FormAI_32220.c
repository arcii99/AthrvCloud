//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct FitnessRecord {
    int day;
    int month;
    int year;
    double weight;
    double height;
    double bmi;
};

int numRecords = 0;
struct FitnessRecord *records;

void printRecords(struct FitnessRecord *recs, int count) {
    printf("Day\tMonth\tYear\tWeight\tHeight\tBMI\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\t%.2f\t%.2f\t%.2f\n", recs[i].day, recs[i].month, recs[i].year, recs[i].weight, recs[i].height, recs[i].bmi);
    }
}

int main() {
    records = malloc(sizeof(struct FitnessRecord));
    char choice = 'y';
    while (choice == 'y') {
        printf("Enter the date (dd mm yyyy): ");
        scanf("%d %d %d", &records[numRecords].day, &records[numRecords].month, &records[numRecords].year);
        printf("Enter your weight (kg): ");
        scanf("%lf", &records[numRecords].weight);
        printf("Enter your height (m): ");
        scanf("%lf", &records[numRecords].height);
        records[numRecords].bmi = records[numRecords].weight / (records[numRecords].height * records[numRecords].height);
        numRecords++;

        printf("Do you want to enter another record? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            records = realloc(records, sizeof(struct FitnessRecord) * (numRecords + 1));
        }
    }
    printRecords(records, numRecords);
    return 0;
}