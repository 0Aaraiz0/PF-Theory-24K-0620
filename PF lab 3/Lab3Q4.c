#include <stdio.h>
int main(){
    float C, A, B;

    //Taking Input
    do
    {
       printf("Car's Fuel Average (Km/L) : ");
       scanf("%f", &C);
    if (C<=0){
       printf("Invalid Input . Please enter a positive number.");
    }
    } while (C<=0);
    
    // Calculations
    A=2414/C;
    B=(A/2)*118+(A/2)*123;

    //Displaying
    printf("Total Fuel Consumed=%f" , A);
    printf("Total Fuel Cost=%f" , B);

return 0;
}