#include <stdio.h>
int main (){
    int Income , Tax , Salary , TaxRate , C;
    
    // TAKING Input
printf("Total Salary : ");
scanf("%d", &Income);
printf("Tax Rate : ");
scanf("%d", &TaxRate);

// Calculating Tax 10% And Remaining Salary
C=Income*TaxRate;
Tax=C/100;
Salary=Income+ -Tax;

// Displaying Tax and Remaining Salary
printf("Tax=%d\n" , Tax);
printf("Salary=%d\n" , Salary);

return 0;
}