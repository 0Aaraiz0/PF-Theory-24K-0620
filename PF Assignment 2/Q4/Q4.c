#include <stdio.h>
#include <string.h>

int main() {
    int WORD_COUNT;

    printf("Enter the number of words: ");
    scanf("%d", &WORD_COUNT);

    int WORD_LENGTH = 100;

    char arr[WORD_COUNT][WORD_LENGTH + 1];

    printf("Enter the words:\n");
    for (int i = 0; i < WORD_COUNT; i++) {
        scanf("%s", arr[i]);
    }

    int grouped[WORD_COUNT];
    for (int i = 0; i < WORD_COUNT; i++) {
        grouped[i] = 0;
    }

    for (int i = 0; i < WORD_COUNT; i++) {
        if (grouped[i]) continue;
        printf("%s: ", arr[i]);
        grouped[i] = 1;

        char sorted_i[WORD_LENGTH + 1];
        strcpy(sorted_i, arr[i]);
        for (int x = 0; x < strlen(sorted_i) - 1; x++) {
            for (int y = x + 1; y < strlen(sorted_i); y++) {
                if (sorted_i[x] > sorted_i[y]) {
                    char temp = sorted_i[x];
                    sorted_i[x] = sorted_i[y];
                    sorted_i[y] = temp;
                }
            }
        }

        for (int j = i + 1; j < WORD_COUNT; j++) {
            if (grouped[j]) continue;

            char sorted_j[WORD_LENGTH + 1];
            strcpy(sorted_j, arr[j]);
            for (int x = 0; x < strlen(sorted_j) - 1; x++) {
                for (int y = x + 1; y < strlen(sorted_j); y++) {
                    if (sorted_j[x] > sorted_j[y]) {
                        char temp = sorted_j[x];
                        sorted_j[x] = sorted_j[y];
                        sorted_j[y] = temp;
                    }
                }
            }

            if (strcmp(sorted_i, sorted_j) == 0) {
                printf("%s ", arr[j]);
                grouped[j] = 1;
            }
        }
        printf("\n");
    }

    return 0;
}