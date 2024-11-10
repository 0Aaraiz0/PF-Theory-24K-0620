#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define GRID_SIZE 5

// Define the symbols
#define EMPTY ' '
#define PLAYER 'P'
#define ITEM 'I'
#define OBSTACLE 'X'

// Function prototypes
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]);
void movePlayer(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY, char direction);
int countItems(char grid[GRID_SIZE][GRID_SIZE]);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerX, playerY;
    char move;
    int itemsCollected = 0, totalItems;

    // Seed the random number generator
    srand(time(0));

    // Initialize grid and place items, obstacles, and player
    initializeGrid(grid, &playerX, &playerY);
    totalItems = countItems(grid);

    printf("Welcome to the Adventure Game!\n");
    printf("Collect all items (I) while avoiding obstacles (X).\n");
    printf("Use W (up), S (down), A (left), and D (right) to move.\n");

    while (itemsCollected < totalItems) {
        displayGrid(grid);
        printf("Items collected: %d/%d\n", itemsCollected, totalItems);
        printf("Enter your move: ");
        scanf(" %c", &move);

        // Move the player and check if an item was collected
        char prev = grid[playerX][playerY];
        movePlayer(grid, &playerX, &playerY, move);

        if (grid[playerX][playerY] == ITEM) {
            itemsCollected++;
            printf("You collected an item!\n");
        } else if (prev == grid[playerX][playerY]) {
            printf("You can't move there! Try another direction.\n");
        }
    }

    printf("Congratulations! You've collected all items!\n");
    return 0;
}

// Function to initialize the grid with empty spaces, items, obstacles, and the player
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY) {
    // Place empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Randomly place items and obstacles
    int items = 3, obstacles = 3;
    while (items > 0) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = ITEM;
            items--;
        }
    }
    while (obstacles > 0) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = OBSTACLE;
            obstacles--;
        }
    }

    // Place the player
    do {
        *playerX = rand() % GRID_SIZE;
        *playerY = rand() % GRID_SIZE;
    } while (grid[*playerX][*playerY] != EMPTY);
    grid[*playerX][*playerY] = PLAYER;
}

// Function to display the grid
void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// Function to move the player in the specified direction
void movePlayer(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY, char direction) {
    int newX = *playerX, newY = *playerY;

    switch (direction) {
        case 'W': case 'w':
            newX -= 1; // Move up
            break;
        case 'S': case 's':
            newX += 1; // Move down
            break;
        case 'A': case 'a':
            newY -= 1; // Move left
            break;
        case 'D': case 'd':
            newY += 1; // Move right
            break;
        default:
            printf("Invalid move! Use W, A, S, or D.\n");
            return;
    }

    // Check boundaries and obstacles
    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] != OBSTACLE) {
        // Move player to new position if valid
        grid[*playerX][*playerY] = EMPTY;
        *playerX = newX;
        *playerY = newY;
        grid[*playerX][*playerY] = PLAYER;
    }
}

// Function to count the total number of items in the grid
int countItems(char grid[GRID_SIZE][GRID_SIZE]) {
    int count = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == ITEM) {
                count++;
            }
        }
    }
    return count;
}