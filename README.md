# UPDATED_AGE_CALCULATOR.C
Complete Step-by-Step Explanation of the Universal Age Calculator WITH SOURCE CODE


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Function to check if input contains only numbers
int isValidYear(char input[]) {
    int i;
    int len = strlen(input);
    
    if(len == 0) return 0;
    
    for(i = 0; i < len; i++) {
        if(!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    char userInput[100];
    int birthYear, age;
    int currentYear;
    time_t t;
    
    // Get current year automatically from system
    time(&t);
    currentYear = localtime(&t)->tm_year + 1900;
    
    printf("================================================\n");
    printf("     UNIVERSAL AGE CALCULATOR (Works in Any Year)\n");
    printf("================================================\n\n");
    printf("Current Year Detected: %d\n", currentYear);
    printf("================================================\n\n");
    
    while(1) {
        printf("Enter your birth year (any year from 1 to 9999): ");
        scanf("%s", userInput);
        
        // Check if input contains only numbers
        if(!isValidYear(userInput)) {
            printf("❌ Invalid input! Use only numbers (0-9).\n");
            printf("   Examples: 1066, 1492, 1776, 2000, 2024\n\n");
            continue;
        }
        
        // Convert to integer
        birthYear = atoi(userInput);
        
        // Check for valid year range (1 to 9999)
        if(birthYear < 1) {
            printf("❌ Year cannot be less than 1!\n\n");
            continue;
        }
        else if(birthYear > 9999) {
            printf("❌ Year is too large! Maximum is 9999.\n\n");
            continue;
        }
        
        break;  // Valid input received
    }
    
    printf("\n================================================\n");
    printf("                 RESULT\n");
    printf("================================================\n");
    printf("Birth Year:      %d\n", birthYear);
    printf("Current Year:    %d\n", currentYear);
    
    // Calculate age or handle future years
    if(birthYear > currentYear) {
        int yearsToWait = birthYear - currentYear;
        printf("\n🔮 FUTURE PREDICTION:\n");
        printf("   You haven't been born yet!\n");
        printf("   You will be born in %d year(s).\n", yearsToWait);
        
        if(yearsToWait == 1) {
            printf("   Next year will be your birth year!\n");
        }
    }
    else if(birthYear == currentYear) {
        printf("\n🍼 NEWBORN:\n");
        printf("   Congratulations on being born this year!\n");
        printf("   You are a newborn baby.\n");
    }
    else {
        age = currentYear - birthYear;
        printf("Your Age:        %d years\n", age);
        
        printf("\n📅 AGE CALCULATION:\n");
        printf("   You were born in %d\n", birthYear);
        printf("   Current year is %d\n", currentYear);
        printf("   You will turn %d years old this year!\n", age);
        
        // Leap year check
        if(isLeapYear(birthYear)) {
            printf("\n✨ LEAP YEAR DETECTED:\n");
            printf("   You were born in a LEAP YEAR (February 29th existed)!\n");
            printf("   That's special! 🎉\n");
        } else {
            printf("\n📆 Note: You were not born in a leap year.\n");
        }
        
        // Historical context
        printf("\n🏛️ HISTORICAL CONTEXT:\n");
        if(birthYear < 476) {
            printf("   You were born in Ancient Times (before the fall of Rome)!\n");
        }
        else if(birthYear < 1500) {
            printf("   You were born in Medieval Times! ⚔️🏰\n");
        }
        else if(birthYear < 1700) {
            printf("   You were born in the Renaissance/Early Modern period! 🎨\n");
        }
        else if(birthYear < 1900) {
            printf("   You were born in the Modern Era (Industrial Revolution)! 🏭\n");
        }
        else if(birthYear < 2000) {
            printf("   You were born in the 20th Century! 📻📺\n");
        }
        else if(birthYear < 2026) {
            printf("   You were born in the 21st Century (Digital Age)! 💻📱\n");
        }
        else {
            printf("   You are from the future! 🤖\n");
        }
        
        // Age category with medieval/future awareness
        printf("\n👥 AGE CATEGORY:\n");
        if(age >= 100) {
            printf("   Centenarian! A century of life! 🎂🎉\n");
        }
        else if(age >= 60) {
            printf("   Senior Citizen - Wisdom years! 🧓👴\n");
        }
        else if(age >= 25) {
            printf("   Prime Adult - Peak of life! 💪\n");
        }
        else if(age >= 18) {
            printf("   Young Adult - Starting journey! 🎓\n");
        }
        else if(age >= 13) {
            printf("   Teenager - Growing years! 🏃\n");
        }
        else if(age >= 5) {
            printf("   Child - Learning and playing! 🧸\n");
        }
        else if(age >= 1) {
            printf("   Toddler - First steps! 👶\n");
        }
        else if(age == 0) {
            printf("   Infant - Just born! 🍼\n");
        }
    }
    
    printf("\n================================================\n");
    printf("        CALCULATOR WILL WORK IN ANY YEAR\n");
    printf("        (Auto-detects current year)\n");
    printf("================================================\n");
    
    return 0;
}
