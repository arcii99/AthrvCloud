//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>

int main() {
    // set initial time
    time_t current_time;
    time(&current_time);

    // set birthdate of Romeo and Juliet
    struct tm romeo_birthdate = {0}, juliet_birthdate = {0};
    romeo_birthdate.tm_year = 106;
    romeo_birthdate.tm_mon = 6;
    romeo_birthdate.tm_mday = 1;
    juliet_birthdate.tm_year = 106;
    juliet_birthdate.tm_mon = 7;
    juliet_birthdate.tm_mday = 31;

    // calculate romeo and juliet's ages at start time
    double romeo_age = difftime(current_time, mktime(&romeo_birthdate)) / (365.25 * 24 * 60 * 60);
    double juliet_age = difftime(current_time, mktime(&juliet_birthdate)) / (365.25 * 24 * 60 * 60);

    // check if they are the same age
    if(romeo_age == juliet_age) {
        printf("Romeo and Juliet are the same age.\n");
    } else if(romeo_age > juliet_age) {
        printf("Romeo is %g years older than Juliet.\n", romeo_age - juliet_age);
    } else {
        printf("Juliet is %g years older than Romeo.\n", juliet_age - romeo_age);
    }

    // travel back in time to the original setting of Romeo and Juliet's story
    struct tm original_time = {0};
    original_time.tm_year = 98;
    original_time.tm_mon = 6;
    original_time.tm_mday = 1;
    time_t original_time_t = mktime(&original_time);
    time(&original_time_t);

    // check if Romeo meets Juliet at the Capulet party
    if(difftime(original_time_t, current_time) < 0) {
        printf("Romeo met Juliet at the Capulet party.\n");
    } else {
        printf("Romeo has not yet met Juliet.\n");
    }

    // travel to the morning after Romeo and Juliet's marriage
    struct tm marriage_time = {0};
    marriage_time.tm_year = 98;
    marriage_time.tm_mon = 6;
    marriage_time.tm_mday = 17;
    time_t marriage_time_t = mktime(&marriage_time);
    time(&marriage_time_t);

    // check if Romeo and Juliet are still alive
    if(difftime(current_time, marriage_time_t) < 0) {
        printf("Romeo and Juliet are still alive and married.\n");
    } else {
        printf("Romeo and Juliet are no longer alive.\n");
    }

    // travel to the future where Romeo and Juliet's families have reconciled
    struct tm reconciled_time = {0};
    reconciled_time.tm_year = 250;
    reconciled_time.tm_mon = 6;
    reconciled_time.tm_mday = 1;
    time_t reconciled_time_t = mktime(&reconciled_time);
    time(&reconciled_time_t);

    // check if Romeo and Juliet's families have reconciled
    if(difftime(current_time, reconciled_time_t) < 0) {
        printf("Romeo and Juliet's families have reconciled in the future.\n");
    } else {
        printf("Romeo and Juliet's families have not yet reconciled.\n");
    }

    return 0;
}