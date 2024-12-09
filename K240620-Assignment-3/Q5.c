#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void updateSpecie(char** specie, char*** specieSupply, int rows, int columns) {
    char changespecie[5];
    printf("Enter Specie to update: ");
    scanf("%s", changespecie);

    for (int i = 0; i < rows; i++) {
        if (strcmp(changespecie, specie[i]) == 0) {
            printf("Enter new name for the specie: ");
            scanf("%s", specie[i]);

            for (int j = 0; j < columns; j++) {
                printf("Enter updated name for supply %d: ", j + 1);
                scanf("%s", specieSupply[i][j]);
            }
            return; 
        }
    }

    printf("Specie '%s' not found.\n", changespecie);
}

void removeSpecie(char** specie, char*** specieSupply, int* rows, int columns) {
    char deletespecie[5];
    printf("Enter Specie to remove: ");
    scanf("%s", deletespecie);

    for (int i = 0; i < *rows; i++) {
        if (strcmp(deletespecie, specie[i]) == 0) {
            free(specie[i]);
            for (int j = 0; j < columns; j++) {
                free(specieSupply[i][j]);
            }
            free(specieSupply[i]);

            for (int k = i; k < *rows - 1; k++) {
                specie[k] = specie[k + 1];
                specieSupply[k] = specieSupply[k + 1];
            }

            *rows -= 1;
            specie = (char**)realloc(specie, (*rows) * sizeof(char*));
            specieSupply = (char***)realloc(specieSupply, (*rows) * sizeof(char**));

            printf("Specie '%s' removed successfully.\n", deletespecie);
            return;
        }
    }

    printf("Specie '%s' not found.\n", deletespecie);
}


void displaySpecie(char** specie, char*** specieSupply, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
            printf("%s        ", specie[i]);

            for (int j = 0; j < columns; j++) {
                printf("%s       ", specieSupply[i][j]);
            }
            printf("\n");
        }
}



void freeMemory(char** specie, char*** specieSupply, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            free(specieSupply[i][j]);
        }
        free(specieSupply[i]); 
        free(specie[i]);       
    }

    free(specieSupply);
    free(specie);      
}


int main() {
    int rows, columns;

    printf("Enter No. of species: ");
    scanf("%d", &rows);
    printf("Enter No. of supplies: ");
    scanf("%d", &columns);

    char** species = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        species[i] = (char*)malloc(10 * sizeof(char));  // Allocate 10 characters per species name
    }

    char*** speciesSupply = (char***)malloc(rows * sizeof(char**));
    for (int i = 0; i < rows; i++) {
        speciesSupply[i] = (char**)malloc(columns * sizeof(char*));
        for (int j = 0; j < columns; j++) {
            speciesSupply[i][j] = (char*)malloc(10 * sizeof(char));  // Allocate 10 characters per species supply name
        }
    }

    for (int i = 0; i < rows; i++) {
        printf("\nEnter specie name (max 9 characters):\n");
        scanf("%s", species[i]);
            for (int j = 0; j < columns; j++) {
                printf("\nEnter supply %d for %s (max 9 characters) :\n", j+1 , species[i]);
                scanf("%s", speciesSupply[i][j]);
        }
    }
    int ch;
    while(ch != 4)
    printf("\n1. Update Specie\n");
    printf("\n2. Remove Specie\n");
    printf("\n3. Display Species and supplies\n");
    printf("\n4.Exit");
    printf("\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        updateSpecie(species, speciesSupply, rows, columns);
        break;

    case 2:
        removeSpecie(species, speciesSupply, rows, columns);
        break;

    case 3:
        displaySpecies(species, speciesSupply, rows, columns);
    
    default:
        printf("\nInvalid choice");
        break;
    }

    freeSpecies(species, speciesSupply, rows, columns);
    return 0;
}
