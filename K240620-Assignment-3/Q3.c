#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    char* atPos = strchr(email, '@');
    if (atPos == NULL) {
        return 0;
    }

    char* dotPos = strchr(atPos + 1, '.');
    if (dotPos == NULL) {
        return 0;
    }

    if (atPos == email || dotPos == atPos + 1 || dotPos[1] == '\0') {
        return 0;
    }

    return 1;
}

int main() {
    char* email = (char*)malloc(100 * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter an email address: ");
    fgets(email, 100, stdin);
    email[strcspn(email, "\n")] = '\0';

    if (validateEmail(email)) {
        printf("Valid Email.\n");
    } else {
        printf("Invalid Email.\n");
    }

    free(email);

    return 0;
}
