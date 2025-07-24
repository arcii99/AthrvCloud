//FormAI DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include<stdio.h>

const double CONVERSION_FACTOR = 0.0254;

double convert_m_to_inch(double m){
    double inch = m / CONVERSION_FACTOR;
    return inch;
}

double convert_inch_to_m(double inch){
    double m = inch * CONVERSION_FACTOR;
    return m;
}

int main(){
    printf("Hello user! Welcome to the Cryptic Unit Converter!\n");
    printf("Enter your value and the unit of measure (m or inch):\n");
    double value;
    char unit[4];
    scanf("%lf %s", &value, unit);
    if(unit[0] == 'm'){
        double converted = convert_m_to_inch(value);
        printf("%f m is equivalent to %f inch\n", value, converted);
    }else if(unit[0] == 'i' && unit[1] == 'n' && unit[2] == 'c' && unit[3] == 'h'){
        double converted = convert_inch_to_m(value);
        printf("%f inch is equivalent to %f m\n", value, converted);
    }else{
        printf("Invalid unit of measure. Please try again.\n");
    }

    return 0;

}