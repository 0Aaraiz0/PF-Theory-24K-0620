#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char arr[6][5];
    int roll[] = {0, 6, 2, 0};
    int score = 0;
    srand(time(0));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 5 && j < 4) {
                printf("| %d ", roll[j]);
            } else {
                arr[i][j] = (rand() % 26) + 65;
                printf("| %c ", arr[i][j]);
            }
        }
        printf("|\n");
    }

    char word[6];
    while (1) {
        printf("\nEnter word (type 'end' to quit): ");
        scanf("%s", word);

        if (strcmp(word, "end") == 0) {
            break;
        }

        int wordFound = 0;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j <= 5 - strlen(word); j++) {
                int match = 1;
                for (int k = 0; k < strlen(word); k++) {
                    if (arr[i][j + k] != word[k]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    wordFound = 1;
                    score++;
                    printf("%s is present horizontally at row %d.\n", word, i + 1);
                    break;
                }
            }
            if (wordFound) break;
        }

        if (!wordFound) {
            for (int j = 0; j < 5; j++) {
                for (int i = 0; i <= 6 - strlen(word); i++) {
                    int match = 1;
                    for (int k = 0; k < strlen(word); k++) {
                        if (arr[i + k][j] != word[k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) {
                        wordFound = 1;
                        score++;
                        printf("%s is present vertically at column %d.\n", word, j + 1);
                        break;
                    }
                }
                if (wordFound) break;
            }
        }

        if (wordFound) {
            printf("Your score is now %d.\n", score);
        } else {
            score--;
            printf("%s is not present. Your score is now %d.\n", word, score);
        }
    }

    printf("Game Over! Final score: %d\n", score);
    return 0;
}