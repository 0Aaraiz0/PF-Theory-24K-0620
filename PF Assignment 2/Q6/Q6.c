//q6
#include <stdio.h>

int match(int n) {
    if (n % 5 == 0) {
        return -1; 
    } else {
        return n % 5;
    }
}

int main() { 
    int n;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &n);

    int result = match(n);

    if (result == -1) {
        printf("It's impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on the first turn to guarantee a win.\n", result);
    }

    return 0;
}