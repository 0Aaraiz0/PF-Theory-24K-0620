#include <stdio.h>

void printHorizontalHistogram(int arr[], int a) {
    printf("\nHorizontal Histogram\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }
}


void printVerticalHistogram(int arr[], int a) {
    int largest = arr[0];
    for (int i = 1; i < a; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("\nVertical Histogram\n");
    for (int i = largest; i > 0; i--) {
        for (int j = 0; j < a; j++) {
            if (arr[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int a;
    printf("How many lines: ");
    scanf("%d", &a);

    int arr[a];

    // Input values
    for (int i = 0; i < a; i++) {
        printf("Enter num: ");
        scanf("%d", &arr[i]);
    }

    printHorizontalHistogram(arr, a);

    printVerticalHistogram(arr, a);

    return 0;
}