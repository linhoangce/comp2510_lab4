//
// Created by linho on 2024-09-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

int playGame();
void displayGuesses(int *guesses, int attempts); // Function to display all guesses

int main() {
    srand(time(0)); // Seed the random number generator
    char playAgain;
    int gamesPlayed = 0;
    int gamesWon = 0;
    int gamesLost = 0;
    int gameResult = 0;

    do {
        gameResult = playGame();
        gamesPlayed++;
        if (gameResult == 1) {
            gamesWon++;
            printf("You've won %d games!\n", gamesWon);
        } else {
            gamesLost++;
            printf("You've lost %d games\n", gamesLost);
        }
        printf("You've played %d games.\n", gamesPlayed);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

int playGame() {
    int number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    // Declare an array to store guesses
    int usersGuess[MAX_ATTEMPTS] = {0};

    // Declare a pointer to manipulate guesses
    int *p = &usersGuess[0];

    printf("Guess the number between 1 and 100:\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        // Store the guess in the array using the pointer
        usersGuess[attempts] = guess;

        attempts++;

        if (guess < number) {
            printf("Too low!\n");
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            // Display all guesses
            displayGuesses(p, attempts);
            return 1;
        }
    }

    printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_ATTEMPTS, number);

    // Display all guesses
    displayGuesses(p, attempts);
    return 0;
}

// Function to display all guesses
void displayGuesses(int *guesses, int attempts) {
    printf("Guesses: \n");
    for (int i = 0; i < attempts; i++) {
        printf("%d\n", *(guesses + i));
    }
}
