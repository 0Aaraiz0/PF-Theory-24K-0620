#include <stdio.h>
#include <string.h>

void analyze_character_frequency(char slogans[][100], int num_slogans) {
    // 2D frequency array: Each row represents a slogan, each column represents a letter
    int frequency[num_slogans][26] = {0}; 


    for (int i = 0; i < num_slogans; i++) {
        for (int j = 0; j < strlen(slogans[i]); j++) {
            char ch = slogans[i][j];

           
            if (ch >= 'A' && ch <= 'Z') {
                frequency[i][ch - 'A']++;  //increment the equivalent number of index of char. eg d = 3 
            } else if (ch >= 'a' && ch <= 'z') {
                frequency[i][ch - 'a']++; 
            }
        }
    }

    for (int i = 0; i < num_slogans; i++) {
        printf("\nFrequency for slogan %d:\n", i + 1);
        for (int j = 0; j < 26; j++) {
            if (frequency[i][j] > 0) {
                printf("%c: %d\n", 'A' + j, frequency[i][j]);
            }
        }
    }
}

int main() {
    int num_slogans;
    printf("Enter the number of slogans: ");
    scanf("%d", &num_slogans);
    getchar(); 

    char slogans[num_slogans][100];
    
    printf("Enter each slogan:\n");
    for (int i = 0; i < num_slogans; i++) {
        fgets(slogans[i], 100, stdin);
        slogans[i][strcspn(slogans[i], "\n")] = '\0'; 
    }

    analyze_character_frequency(slogans, num_slogans);

    return 0;
}