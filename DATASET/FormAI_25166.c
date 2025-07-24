//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	// get current time
	time_t current_time = time(NULL);
	
	// convert current time to string
	char* current_time_string = ctime(&current_time);
	
	// output current time
	printf("Current Time: %s", current_time_string);
	
	// create struct for future time
	struct tm future_time;
	
	// set future time to 10 years from now
	future_time.tm_year = localtime(&current_time)->tm_year + 10;
	future_time.tm_mon = localtime(&current_time)->tm_mon;
	future_time.tm_mday = localtime(&current_time)->tm_mday;
	future_time.tm_hour = localtime(&current_time)->tm_hour;
	future_time.tm_min = localtime(&current_time)->tm_min;
	future_time.tm_sec = localtime(&current_time)->tm_sec;
	
	// convert future time to time_t
	time_t future_time_t = mktime(&future_time);
	
	// convert future time to string
	char* future_time_string = ctime(&future_time_t);
	
	// output future time
	printf("Future Time: %s", future_time_string);
	
	return 0;
}