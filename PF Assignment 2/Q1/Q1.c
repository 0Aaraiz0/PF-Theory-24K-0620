#include <stdio.h>

int main() {
    int num;

    printf("How many numbers: ");
    scanf("%d", &num);

    int arr[num];

    for (int i = 0; i < num; i++) {
    input:
        printf("Enter Number: ");
        scanf("%d", &arr[i]);
        if (arr[i] >= 9999) {
            printf("Enter number smaller than 9999\n");
            goto input;
        }
    }

    int largest = -9999, second_largest = -9999;

    for (int i = 0; i < num; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }

    if (second_largest == -9999) {
        printf("No second largest element found.\n");
    } else {
        printf("Second largest is: %d\n", second_largest);
    }

    return 0;
}
