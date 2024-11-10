#include <stdio.h>

/*
 * Program Description:
 * This program generates a symmetrical star pattern based on an input number of stars.
 * The pattern includes:
 * - An upper pyramid that gradually widens with each row.
 * - A central row of stars that matches the specified width (numStars).
 * - A lower inverted pyramid that narrows with each descending row.
 * 
 * Pattern Details:
 * - Input: An integer `numStars`, which specifies the number of stars in the central row.
 * - The top pyramid aligns with the center star in its uppermost row.
 * - The total height of the pattern is calculated as 2 * numStars - 1.
 * - The pattern width reaches `numStars` in the center row, with rows expanding and contracting to form the pyramid shapes.
 */

int main() {
    int numStars;
    
    printf("Enter an odd number of stars: ");
    scanf("%d", &numStars);
    
    if (numStars % 2 != 0) {
        int spacing = 1; // Variable to control inner spacing for the upper pyramid
        int maxSpacing = (numStars + (numStars - 2)); // Maximum spacing for the first row
        
        // Upper pyramid structure
        for (int row = 0; row < numStars - 1; row++) {
            // Print leading spaces for alignment
            for (int space = 1; space <= maxSpacing - row; space++) {
                printf(" ");
            }
            printf("*"); // Print the left star
            // For all rows except the first, print inner stars
            if (row != 0) {
                for (int innerSpace = 0; innerSpace < spacing; innerSpace++) {
                    printf(" ");
                }
                spacing = spacing + 2; // Increase spacing for the next row
                printf("*"); // Print the right star
            }
            printf("\n"); // Move to the next line
        }
        
        // Print the middle horizontal line of stars
        for (int i = 0; i < numStars; i++) {
            printf("*");
        }
        
        // Print spaces between the upper and lower parts of the pattern
        for (int i = 0; i < spacing; i++) {
            printf(" ");
        }
        
        // Print the middle horizontal line of stars again
        for (int i = 0; i < numStars; i++) {
            printf("*");
        }
        printf("\n"); 
        
        spacing = spacing + 2 * (numStars - 2); // Adjust spacing for the lower part
        
        // Lower inverted pyramid structure
        for (int row = 1; row < numStars; row++) {
            // Print leading spaces for alignment
            for (int space = 0; space != row; space++) {
                printf(" ");
            }
            printf("*"); // Print the left star
            // Print spaces between the stars
            for (int innerSpace = 0; innerSpace < spacing; innerSpace++) {
                printf(" ");
            }
            spacing = spacing - 2; // Decrease spacing for the next row
            printf("*\n"); // Print the right star and move to the next line
        }
        
        // Print the bottom part of the pattern
        maxSpacing = 1; // Reset for the lower part
        for (int row = 0; row < numStars - 1; row++) {
            // Print leading spaces for alignment
            for (int space = 0; space < (numStars - 2) - row; space++) {
                printf(" ");
            }
            printf("*"); // Print the left star
            // Print spaces between the stars
            for (int space = 0; space < (numStars - 2) - row; space++) {
                printf(" ");
            }
            if (row != numStars - 2) {
                printf("*"); // Print the right star if not the last row
            } else {
                printf(" "); // Leave a space in the last row
            }
            // Print middle spaces
            for (int g = 1; g <= maxSpacing; g++) {
                printf(" ");
            }
            if (row != numStars - 2) {
                printf("*"); // Print the left star of the middle section if not the last row
            } else {
                printf(" "); // Leave a space in the last row
            }
            // Adjust maxSpacing for the next iteration
            if (row != numStars - 1) {
                maxSpacing = maxSpacing + 4; // Increase spacing for the next row
            } else {
                maxSpacing = maxSpacing + 6; // Special case for the last row
            }
            // Print trailing spaces
            for (int space = 0; space < (numStars - 2) - row; space++) {
                printf(" ");
            }
            printf("*\n"); // Print the right star and move to the next line
        }
    } else {
        printf("The number entered is not odd!\n");
    }
    return 0; 
}