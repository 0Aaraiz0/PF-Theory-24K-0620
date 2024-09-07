#include <stdio.h>
int main(){
    float x1, x2, y1, y2, B;
    
    //Taking Input
    printf("x1 = \n");
    scanf("%f", &x1);
    printf("x2 = \n");
    scanf("%f", &x2);
    printf("y1 = \n");
    scanf("%f", &y1);
    printf("y2 = \n");
    scanf("%f", &y2);

    //Calculations
    B=(y2-y1)/(x2-x1);

    //Displaying
    printf("Slope=%.3f\n",B);
    return 0;
    
}