#include <stdio.h>
#include <string.h>

// Function 
int remove_duplicates(char arr[][30], int n) {
    int total_removed = 0;  // Track total characters removed

   
    for (int d = 0; d < n; d++) {
        int len = strlen(arr[d]);

        // Mark duplicates in the current word with '?'
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (arr[d][i] == arr[d][j]) {
                    arr[d][j] = '?';  
                }
            }
        }

        // Shift non-'?' characters to the left
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (arr[d][i] != '?') {
                arr[d][pos++] = arr[d][i];
            } else {
                total_removed++;  // Increment count of removed characters
            }
        }
        arr[d][pos] = '\0';  
    }

    return total_removed;
}

int main() {
    int n;
    printf("How many words will you put in: ");
    scanf("%d", &n);

    char arr[n][30];
    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", arr[i]);
    }


    int removed_count = remove_duplicates(arr, n);

  
    printf("Result after removing repeated characters:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    printf("Total characters removed: %d\n", removed_count);

    return 0;
}
