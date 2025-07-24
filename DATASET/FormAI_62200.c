//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include<stdio.h>
#include<time.h>

void logEvent(const char* event)
{
  FILE *file = fopen("eventLog.txt", "a+");
  time_t t = time(NULL);
  struct tm current_time = *localtime(&t);
  fprintf(file, "%d-%02d-%02d %02d:%02d:%02d %s\n", 
          current_time.tm_year + 1900, current_time.tm_mon + 1, current_time.tm_mday, 
          current_time.tm_hour, current_time.tm_min, current_time.tm_sec, event);
  printf("Event logged successfully!\n");
  fclose(file);
}

int main()
{
  int a, b;
  printf("Enter two numbers:\n");
  scanf("%d %d", &a, &b);
  if(b == 0)
  {
    logEvent("Division by zero error occurred.");
    printf("Error: Division by zero is not allowed!\n");
  }
  else
  {
    int result = a / b;
    printf("Result: %d\n", result);
  }
  return 0;
}