//FormAI DATASET v1.0 Category: System event logger ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void log_event(char *event)
{
	time_t current_time;
	char* c_time_string;

  	/* Obtain current time as seconds elapsed since the Epoch. */
  	current_time = time(NULL);

  	/* Convert to local time format. */
  	c_time_string = ctime(&current_time);

	FILE *fp;
	fp = fopen("system_logs.txt", "a");

	if(fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	fprintf(fp, "%s - %s\n", c_time_string, event);

	printf("Event Logged Successfully!\n");

	fclose(fp);
}

int main()
{
	char event[100];
	
	printf("Enter the event to be logged: ");
	scanf("%[^\n]%*c", event);

	log_event(event);

	return 0;
}