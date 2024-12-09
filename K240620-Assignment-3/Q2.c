#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];  
    char playerName[50]; 
    int totalScore;      
};

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void playGame(struct Player* player1, struct Player* player2) {
    
    player1->totalScore = 0;
    player2->totalScore = 0;


    printf("Enter name for Player 1: ");
    scanf("%s", player1->playerName);

    printf("Enter name for Player 2: ");
    scanf("%s", player2->playerName);

    
    for (int i = 0; i < 12; i++) {
        // Player 1's turn
        printf("Enter score for Ball %d for %s: ", i + 1, player1->playerName);
        scanf("%d", &player1->ballScores[i]);
        if (validateScore(player1->ballScores[i])) {
            player1->totalScore += player1->ballScores[i];
        } else {
            player1->ballScores[i] = -1; 
        }

        printf("Enter score for Ball %d for %s: ", i + 1, player2->playerName);
        scanf("%d", &player2->ballScores[i]);
        if (validateScore(player2->ballScores[i])) {
            player2->totalScore += player2->ballScores[i];
        } else {
            player2->ballScores[i] = -1; 
        }
    }
}

void findWinner(struct Player* player1, struct Player* player2) {
    printf("\nMatch Result:\n");
    if (player1->totalScore > player2->totalScore) {
        printf("Winner: %s with %d runs!\n", player1->playerName, player1->totalScore);
    } else if (player1->totalScore < player2->totalScore) {
        printf("Winner: %s with %d runs!\n", player2->playerName, player2->totalScore);
    } else {
        printf("It's a tie! Both players scored %d runs.\n", player1->totalScore);
    }
}

void displayMatchScoreboard(struct Player* player1, struct Player* player2) {
    printf("\nScoreboard:\n");
    printf("=====================================\n");

    // Display Player 1's scores
    printf("%s's Scoreboard:\n", player1->playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) {
        if (player1->ballScores[i] != -1) { 
            printf("%d ", player1->ballScores[i]);
        } else {
            printf("X "); 
        }
    }
    printf("\nTotal Score: %d\n", player1->totalScore);
    printf("Average Score: %.2f\n", player1->totalScore / 12.0);

    printf("-------------------------------------\n");

    printf("%s's Scoreboard:\n", player2->playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) {
        if (player2->ballScores[i] != -1) { 
            printf("%d ", player2->ballScores[i]);
        } else {
            printf("X "); 
        }
    }
    printf("\nTotal Score: %d\n", player2->totalScore);
    printf("Average Score: %.2f\n", player2->totalScore / 12.0);

    printf("=====================================\n");
}

int main() {
    struct Player player1, player2;

    playGame(&player1, &player2);

    findWinner(&player1, &player2);

    displayMatchScoreboard(&player1, &player2); 

    return 0;
}
