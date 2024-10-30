#include <stdio.h>
#include <string.h>

int main() {
    int a;
    printf("How many alphabets will you put in: ");
    scanf("%d", &a);

    char arr[a + 1];
    int freq[a];

    printf("Enter the slogan: ");
    scanf("%s", arr);

    for (int i = 0; i < a; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < a; i++) {
        if (freq[i] == 0) {
            int count = 1;
            for (int j = i + 1; j < a; j++){
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1;
                }
            }
            freq[i] = count;
        }
    }

    for (int i = 0; i < a; i++) {
        if (freq[i] != -1) {
            printf("%c has appeared %d times\n", arr[i], freq[i]);
        }
    }
    return 0;
}