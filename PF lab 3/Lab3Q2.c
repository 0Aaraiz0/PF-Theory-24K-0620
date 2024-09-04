#include <stdio.h>
int main(){
    
    int a , b , c;
    
    // Taking input 
    printf("THE FIRST NUMBER ");
    scanf("%d" , &a);

    printf("THE SECOND NUMBER ");
    scanf("%d" , &b);
    
    // Swapping the values
    c=a;
    a=b;
    b=c;

    // Displaying the swapped values
    printf("a = %d\n" , a);
    printf("b = %d\n" , b);

return 0;
}
