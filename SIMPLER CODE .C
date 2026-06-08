#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
    char input[100];
    int birthYear, age, currentYear, i, valid;
    time_t t;
    
    time(&t);
    currentYear = localtime(&t)->tm_year + 1900;
    
    printf("Current Year: %d\n", currentYear);
    printf("Enter birth year (1-9999): ");
    
    while(1) {
        valid = 1;
        scanf("%s", input);
        
        for(i = 0; i < strlen(input); i++) {
            if(!isdigit(input[i])) { valid = 0; break; }
        }
        
        if(!valid) {
            printf("Use only numbers! Try again: ");
            continue;
        }
        
        birthYear = atoi(input);
        if(birthYear >= 1 && birthYear <= 9999) break;
        printf("Enter year between 1-9999: ");
    }
    
    if(birthYear > currentYear) {
        printf("You will be born in %d years!\n", birthYear - currentYear);
    } else {
        age = currentYear - birthYear;
        printf("Your age: %d years\n", age);
        if(isLeapYear(birthYear)) printf("Leap year birth!\n");
    }
    
    return 0;
}
