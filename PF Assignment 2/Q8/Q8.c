#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal);
int binaryToDecimal(int binary);
void decimalToHexadecimal(int decimal);
int hexadecimalToDecimal(char hex[]);
void binaryToHexadecimal(int binary);
void hexadecimalToBinary(char hex[]);

int displayMenu() {
    int choice;
    
    printf("\nNumerical Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal equivalent: %d\n", binaryToDecimal(number));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToBinary(number);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                decimalToHexadecimal(number);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Decimal equivalent: %d\n", hexadecimalToDecimal(hexNumber));
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                binaryToHexadecimal(number);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                hexadecimalToBinary(hexNumber);
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

void decimalToBinary(int decimal) {
    int binary[32], index = 0;
    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void decimalToHexadecimal(int decimal) {
    char hex[20];
    int i = 0;
    if (decimal == 0) {
        printf("Hexadecimal equivalent: 0\n");
        return;
    }
    while (decimal > 0) {
        int remainder = decimal % 16;
        hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        decimal /= 16;
    }
    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int hexadecimalToDecimal(char hex[]) {
    int decimal = 0, base = 1, len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        int value = (hex[i] >= '0' && hex[i] <= '9') ? (hex[i] - '0') : (hex[i] - 'A' + 10);
        decimal += value * base;
        base *= 16;
    }
    return decimal;
}

void binaryToHexadecimal(int binary) {
    int decimal = binaryToDecimal(binary);
    decimalToHexadecimal(decimal);
}

void hexadecimalToBinary(char hex[]) {
    int decimal = hexadecimalToDecimal(hex);
    decimalToBinary(decimal);
}
