#include <stdio.h>
int main(){
    int arr[5], num , a , tarr[3];

    for(int i = 0 ; i < 5 ; i++){
        input:
        printf("Enter Number: ");
        scanf("%d", &arr[i]);
        if(arr[i]>=9999){
            printf("Enter number smaller than 9999");
            goto input;
        }
    }


    for(int i = 0; i < 5 ; i++){
        a=0;
        for(int j = 0 ; j < 5 ; j++){
            if(arr[i]>arr[j]){
                a++;
            }
        }
         tarr[a] = arr[i];
    }

    printf("Second largest is : %d", tarr[1]);

    return 0;
}