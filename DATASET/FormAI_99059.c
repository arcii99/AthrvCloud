//FormAI DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ShapeShifter {
    char type[20];
    double value;
} ShapeShifter;

ShapeShifter convertLength(char* unit, double value) {
    ShapeShifter output;
    strcpy(output.type,unit);
    if(strcmp(unit,"meters")==0) {
        output.value = value * 3.28084;
    } else if(strcmp(unit,"feet")==0) {
        output.value = value / 3.28084;
    } else if(strcmp(unit,"kilometers")==0) {
        output.value = value * 0.621371;
    } else if(strcmp(unit,"miles")==0) {
        output.value = value / 0.621371;
    }
    return output;
}

int main() {
    double num;
    char unit[20];
    printf("Enter a value: ");
    scanf("%lf", &num);
    printf("Enter a unit (meters, feet, kilometers, miles): ");
    scanf("%s", unit);

    ShapeShifter result = convertLength(unit, num);
    printf("%.2f %s is equal to %.2f",num,unit,result.value,result.type);

    return 0;
}