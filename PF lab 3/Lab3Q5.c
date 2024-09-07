#include <stdio.h>
int main(){
    float P, R, T, SI;

    do
    {
        printf("Principal Amount : ");
        scanf("%f", &P);
        printf("Rate Of Interest : ");
        scanf("%f", &R);
        printf("Time Period : ");
        scanf("%f", &T);

        if (P<100 || P>1000000 && R<5 || R>10 && T<1 || T>10 );

        {
            printf("Invalid Input. Please choose numbers from the range.");
        }
        

    } while (P<100 || P>1000000 && T<5 || T>10 && T<1 || T>10);

    //Calculations
    SI=(P*R*T)/100;

    //Displaying
    printf("Simple Interest=%f", SI);
    return 0;
}