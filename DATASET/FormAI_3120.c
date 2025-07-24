//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
   int day;
   int month;
   int year;
} Date;

typedef struct {
   double weight;
   double bodyFat;
   int minutesOfWorkout;
   int steps;
   Date date;
} LogEntry;

typedef struct {
   LogEntry entries[MAX_LOG_ENTRIES];
   int numEntries;
} FitnessLog;

void logWeight(FitnessLog* log, const double weight, const Date date) {
   log->entries[log->numEntries].weight = weight;
   log->entries[log->numEntries].date = date;
   log->numEntries++;
}

void logBodyFat(FitnessLog* log, const double bodyFat, const Date date) {
   log->entries[log->numEntries].bodyFat = bodyFat;
   log->entries[log->numEntries].date = date;
   log->numEntries++;
}

void logWorkout(FitnessLog* log, const int minutesOfWorkout, const Date date) {
   log->entries[log->numEntries].minutesOfWorkout = minutesOfWorkout;
   log->entries[log->numEntries].date = date;
   log->numEntries++;
}

void logSteps(FitnessLog* log, const int steps, const Date date) {
   log->entries[log->numEntries].steps = steps;
   log->entries[log->numEntries].date = date;
   log->numEntries++;
}

void printLog(FitnessLog* log) {
   printf("Date\t\tWeight\tBody Fat\tMinutes of Workout\tSteps\n");
   for (int i = 0; i < log->numEntries; i++) {
      LogEntry entry = log->entries[i];
      printf("%d/%d/%d\t%.1lf lb\t%.2lf%%\t\t%d\t\t%d\n", entry.date.month,
             entry.date.day, entry.date.year, entry.weight, entry.bodyFat,
             entry.minutesOfWorkout, entry.steps);
   }
}

int main() {
   FitnessLog log = { .numEntries = 0 };
   Date today = { .day = 1, .month = 9, .year = 2021 };

   logWeight(&log, 180.0, today);
   logBodyFat(&log, 20.0, today);
   logWorkout(&log, 60, today);
   logSteps(&log, 10000, today);

   printf("Today's activities have been logged!\n\n");

   printLog(&log);

   return 0;
}