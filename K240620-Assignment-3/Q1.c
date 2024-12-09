#include <stdio.h>
#include <string.h>

typedef struct {
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11];
} Employee;

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

void input(Employee employee[]) {
    for (int i = 0; i < 4; i++) {
        printf("Enter Employee Code: ");
        scanf("%d", &employee[i].employeeCode);
        getchar();
        printf("Enter Employee Name: ");
        fgets(employee[i].employeeName, sizeof(employee[i].employeeName), stdin);
        employee[i].employeeName[strcspn(employee[i].employeeName, "\n")] = '\0';
        printf("Enter Employee's Date Of Joining (yyyy-mm-dd): ");
        fgets(employee[i].dateOfJoining, sizeof(employee[i].dateOfJoining), stdin);
        employee[i].dateOfJoining[strcspn(employee[i].dateOfJoining, "\n")] = '\0';
        printf("\n");
    }
}

void calculateTenure(Employee employee[]) {
    int currentYear, currentMonth, currentDay;
    printf("\nEnter today's year: ");
    scanf("%d", &currentYear);
    printf("Enter today's month: ");
    scanf("%d", &currentMonth);
    printf("Enter today's day: ");
    scanf("%d", &currentDay);

    printf("\nTenure of Employees:\n");
    printf("---------------------------------------------------\n");
    printf("Employee Code | Employee Name | Tenure (Years, Months, Days)\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int joiningYear, joiningMonth, joiningDay;
        sscanf(employee[i].dateOfJoining, "%d-%d-%d", &joiningYear, &joiningMonth, &joiningDay);

        int tenureYear = currentYear - joiningYear;
        int tenureMonth = currentMonth - joiningMonth;
        int tenureDay = currentDay - joiningDay;

        if (tenureDay < 0) {
            if (currentMonth == 1) {
                tenureDay += getDaysInMonth(12, currentYear - 1);
                tenureMonth--;
            } else {
                tenureDay += getDaysInMonth(currentMonth - 1, currentYear);
                tenureMonth--;
            }
        }

        if (tenureMonth < 0) {
            tenureMonth += 12;
            tenureYear--;
        }

        printf("%14d | %13s | %5d years, %2d months, %2d days\n",
               employee[i].employeeCode, employee[i].employeeName, tenureYear, tenureMonth, tenureDay);
    }
}

int main() {
    Employee employee[4];
    input(employee);
    calculateTenure(employee);
    return 0;
}
