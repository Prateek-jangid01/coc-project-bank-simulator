#include <stdio.h>

int main()
{
    char word[] = "MENTOR"; // The secret word
    char display[10];              // To show guessed letters
    char guess;                    // Player's letter guess
    int lives = 6;                 // Number of wrong guesses allowed
    int i, correct, win = 0;
    int length = strlen(word);

    // Fill display with underscores
    for (i = 0; i < length; i++)
    {
        display[i] = '_';
    }
    display[length] = '\0';

    printf(" WORD GUESSING GAME \n");
    printf("Guess the secret word, one letter at a time!\n");
    printf("You have %d lives.\n\n", lives);

    // Main game loop
    while (lives > 0)
    {
        printf("Word: ");
        for (i = 0; i < length; i++)
        {
            printf("%c ", display[i]);
        }

        printf("\nLives left: %d\n", lives);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        correct = 0;

        // Check if guessed letter is in the word
        for (i = 0; i < length; i++)
        {
            if (word[i] == guess)
            {
                display[i] = guess;
                correct = 1;
            }
        }

        if (correct == 0)
        {
            lives--;
            printf("Wrong guess! You lost a life.\n");
            printf("Hint: The synonym of 'teacher' or 'advisor' which starts with 'M', ends with 'R' and also contains 'N' in it.\n");
        }
        else
        {
            printf("Good guess!\n");
        }

        // Check for win condition
        win = 1;
        for (i = 0; i < length; i++)
        {
            if (display[i] == '_')
            {
                win = 0;
                break;
            }
        }

        if (win == 1)
        {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            break;
        }

        printf("\n");
    }

    if (win == 0)
    {
        printf("You lost! The word was: %s\n", word);
    }

    return 0;
}
