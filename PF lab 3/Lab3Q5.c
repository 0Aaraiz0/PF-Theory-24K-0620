#include <stdio.h>
int main(){
    float P, R, T, SI;

    do{
        printf("Principal Amount : \n");
        scanf("%f", &P);
        printf("Rate Of Interest : \n");
        scanf("%f", &R);
        printf("Time Period : \n");
        scanf("%f", &T);

        if ((P<100 || P>1000000) || (R<5 || R>10) || (T<1 || T>10 ))

        {
            printf("Invalid Input. Please choose numbers from the range.\n");
        }
        } while ((P<100 || P>1000000) || (R<5 || R>10) || (T<1 || T>10 ));

    //Calculations
    SI=(P*R*T)/100;

    //Displaying
    printf("Simple Interest = %f\n", SI);
    return 0;
}