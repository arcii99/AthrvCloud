//FormAI DATASET v1.0 Category: Unit converter ; Style: brave
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice1, choice2;
    float value, result;
    
    printf("\nWelcome to Brave Unit converter !\n\n");
    printf("Select the source unit:\n1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Mile\n6. Foot\n7. Inch\n8. Yard\n");
    scanf("%d", &choice1);
    printf("You have chosen: ");
    
    switch(choice1)
    {
        case 1: printf("Meter\n");
                break;
        case 2: printf("Kilometer\n");
                break;
        case 3: printf("Centimeter\n");
                break;
        case 4: printf("Millimeter\n");
                break;
        case 5: printf("Mile\n");
                break;
        case 6: printf("Foot\n");
                break;
        case 7: printf("Inch\n");
                break;
        case 8: printf("Yard\n");
                break;
        default: printf("Invalid choice!\n");
                 exit(0);
    }
    
    printf("Select the destination unit:\n1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Mile\n6. Foot\n7. Inch\n8. Yard\n");
    scanf("%d", &choice2);
    printf("You have chosen: ");
    
    switch(choice2)
    {
        case 1: printf("Meter\n");
                break;
        case 2: printf("Kilometer\n");
                break;
        case 3: printf("Centimeter\n");
                break;
        case 4: printf("Millimeter\n");
                break;
        case 5: printf("Mile\n");
                break;
        case 6: printf("Foot\n");
                break;
        case 7: printf("Inch\n");
                break;
        case 8: printf("Yard\n");
                break;
        default: printf("Invalid choice!\n");
                 exit(0);
    }
    
    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    
    switch(choice1)
    {
        case 1: switch(choice2)
                {
                    case 1: result = value;
                            break;
                    case 2: result = value/1000;
                            break;
                    case 3: result = value*100;
                            break;
                    case 4: result = value*1000;
                            break;
                    case 5: result = value/1609;
                            break;
                    case 6: result = value*3.281;
                            break;
                    case 7: result = value*39.37;
                            break;
                    case 8: result = value*1.094;
                            break;
                }
                break;
        case 2: switch(choice2)
                {
                    case 1: result = value*1000;
                            break;
                    case 2: result = value;
                            break;
                    case 3: result = value*100000;
                            break;
                    case 4: result = value*1000000;
                            break;
                    case 5: result = value/1.609;
                            break;
                    case 6: result = value*3281;
                            break;
                    case 7: result = value*39370;
                            break;
                    case 8: result = value*1094;
                            break;
                }
                break;
        case 3: switch(choice2)
                {
                    case 1: result = value/100;
                            break;
                    case 2: result = value/100000;
                            break;
                    case 3: result = value;
                            break;
                    case 4: result = value*10;
                            break;
                    case 5: result = value/160934;
                            break;
                    case 6: result = value/30.48;
                            break;
                    case 7: result = value/2.54;
                            break;
                    case 8: result = value/91.44;
                            break;
                }
                break;
        case 4: switch(choice2)
                {
                    case 1: result = value/1000;
                            break;
                    case 2: result = value/1000000;
                            break;
                    case 3: result = value/10;
                            break;
                    case 4: result = value;
                            break;
                    case 5: result = value/1609344;
                            break;
                    case 6: result = value/304.8;
                            break;
                    case 7: result = value/25.4;
                            break;
                    case 8: result = value/914.4;
                            break;
                }
                break;
        case 5: switch(choice2)
                {
                    case 1: result = value*1609;
                            break;
                    case 2: result = value*1.609;
                            break;
                    case 3: result = value*160934;
                            break;
                    case 4: result = value*1609344;
                            break;
                    case 5: result = value;
                            break;
                    case 6: result = value*5280;
                            break;
                    case 7: result = value*63360;
                            break;
                    case 8: result = value*1760;
                            break;
                }
                break;
        case 6: switch(choice2)
                {
                    case 1: result = value/3.281;
                            break;
                    case 2: result = value/3281;
                            break;
                    case 3: result = value*30.48;
                            break;
                    case 4: result = value*304.8;
                            break;
                    case 5: result = value/5280;
                            break;
                    case 6: result = value;
                            break;
                    case 7: result = value*12;
                            break;
                    case 8: result = value*0.333;
                            break;
                }
                break;
        case 7: switch(choice2)
                {
                    case 1: result = value/39.37;
                            break;
                    case 2: result = value/39370;
                            break;
                    case 3: result = value*2.54;
                            break;
                    case 4: result = value*25.4;
                            break;
                    case 5: result = value/63360;
                            break;
                    case 6: result = value/12;
                            break;
                    case 7: result = value;
                            break;
                    case 8: result = value/36;
                            break;
                }
                break;
        case 8: switch(choice2)
                {
                    case 1: result = value/1.094;
                            break;
                    case 2: result = value/1094;
                            break;
                    case 3: result = value*91.44;
                            break;
                    case 4: result = value*914.4;
                            break;
                    case 5: result = value/1760;
                            break;
                    case 6: result = value*0.333;
                            break;
                    case 7: result = value*36;
                            break;
                    case 8: result = value;
                            break;
                }
                break;
        default: printf("Invalid input!\n");
                 exit(0);
    }
    
    printf("%g ", value);
    
    switch(choice1)
    {
        case 1: printf("m");
                break;
        case 2: printf("km");
                break;
        case 3: printf("cm");
                break;
        case 4: printf("mm");
                break;
        case 5: printf("mi");
                break;
        case 6: printf("ft");
                break;
        case 7: printf("in");
                break;
        case 8: printf("yd");
                break;
    }
    
    printf(" = %g ", result);
    
    switch(choice2)
    {
        case 1: printf("m");
                break;
        case 2: printf("km");
                break;
        case 3: printf("cm");
                break;
        case 4: printf("mm");
                break;
        case 5: printf("mi");
                break;
        case 6: printf("ft");
                break;
        case 7: printf("in");
                break;
        case 8: printf("yd");
                break;
    }
    
    printf("\nThank you for using Brave Unit converter!\n");
    
    return 0;
}