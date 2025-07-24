//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include<stdio.h>

int main(){
    float distance,converted_distance;
    char from_unit,to_unit;

    printf("Enter the distance to convert: ");
    scanf("%f",&distance);
    printf("Enter the unit of the distance: ");
    scanf(" %c",&from_unit);
    printf("Enter the unit to convert to: ");
    scanf(" %c",&to_unit);

    if(from_unit=='m'&&to_unit=='k'){
        converted_distance = distance / 1000;
    }
    else if(from_unit=='m'&&to_unit=='c'){
        converted_distance = distance * 100;
    }
    else if(from_unit=='k'&&to_unit=='m'){
        converted_distance = distance * 1000;
    }
    else if(from_unit=='k'&&to_unit=='c'){
        converted_distance = distance * 100000;
    }
    else if(from_unit=='c'&&to_unit=='m'){
        converted_distance = distance / 100;
    }
    else if(from_unit=='c'&&to_unit=='k'){
        converted_distance = distance / 100000;
    }
    else{
        printf("Invalid input!");
        return 0;
    }
    printf("%f%c is equal to %f%c",distance,from_unit,converted_distance,to_unit);
    return 0;
}