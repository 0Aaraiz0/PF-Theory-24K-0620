#include <stdio.h>
int main (){
    int Income , Tax , Salary;
    
    // TAKING Input
printf("Total Salary : ");
scanf("%d", &Income);

// Calculating Tax 10% And Remaining Salary
Tax=Income*0.1;
Salary=Income+ -Tax;

// Displaying Tax and Remaining Salary
printf("Tax=%d\n" , Tax);
printf("Salary=%d\n" , Salary);

return 0;
}