#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ratings;
    int totalScore;
} Employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Enter rating for Employee %d for period %d (between 1 and 10): ", i + 1, j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    printf("\nPerformance Ratings:\n");
    printf("---------------------------------------------------------------\n");
    printf("Employee   ");
    for (int i = 0; i < numPeriods; i++) {
        printf("Period %d   ", i + 1);
    }
    printf("\n");

    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d  ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("   %d       ", ratings[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int avgrating[numEmployees];
    for (int i = 0; i < numEmployees; i++) {
        avgrating[i] = 0;
        for (int j = 0; j < numPeriods; j++) {
            avgrating[i] += ratings[i][j];
        }
        avgrating[i] /= numPeriods;
    }

    int index = 0;
    int max = avgrating[0];
    for (int i = 1; i < numEmployees; i++) {
        if (avgrating[i] > max) {
            max = avgrating[i];
            index = i;
        }
    }
    return index;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int avgperiodrating[numPeriods];
    for (int i = 0; i < numPeriods; i++) {
        avgperiodrating[i] = 0;
        for (int j = 0; j < numEmployees; j++) {
            avgperiodrating[i] += ratings[j][i];
        }
        avgperiodrating[i] /= numEmployees;
    }

    int index = 0;
    int max = avgperiodrating[0];
    for (int i = 1; i < numPeriods; i++) {
        if (avgperiodrating[i] > max) {
            max = avgperiodrating[i];
            index = i;
        }
    }
    return index;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int avgrating[numEmployees];
    for (int i = 0; i < numEmployees; i++) {
        avgrating[i] = 0;
        for (int j = 0; j < numPeriods; j++) {
            avgrating[i] += ratings[i][j];
        }
        avgrating[i] /= numPeriods;
    }

    int index = 0;
    int min = avgrating[0];
    for (int i = 1; i < numEmployees; i++) {
        if (avgrating[i] < min) {
            min = avgrating[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int numEmployees, numPeriods;
    printf("Enter No. of Employees: ");
    scanf("%d", &numEmployees);
    printf("Enter No. of periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    if (ratings == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
        if (ratings[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    printf("\nEmployee of the Year is Employee %d\n", findEmployeeOfTheYear(ratings, numEmployees, numPeriods) + 1);
    printf("Highest Rated Period is Period %d\n", findHighestRatedPeriod(ratings, numEmployees, numPeriods) + 1);
    printf("Worst Performing Employee is Employee %d\n", findWorstPerformingEmployee(ratings, numEmployees, numPeriods) + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
