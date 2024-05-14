#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int len(const char *a) {
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        count++;
    }
    return count;
}
int find(char p, const char *a) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (p == a[i]) {
            return 1;
        }
    }
    return 0;
}
void displayWord(const char *word, const char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (find(word[i], guessedLetters)) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int main() {
    int j = 0;
    const char *words[] = {"dust", "hello", "string", "python", "javascript", "quiz", "juice"};
    srand(time(NULL));
    int n = rand() % 7;
    const char *word = words[n];
    int wordLen = len(word);
    char guessedLetters[26] = {0};
    int attempts = 6;
    printf("Welcome to Hangman!\n");
    printf("Guess the word: ");
    displayWord(word, guessedLetters);
    while (attempts > 0) {
        char guess;
        scanf(" %c", &guess);
        if (find(guess, guessedLetters)) {
            printf("You already guessed '%c'. Try again.\n", guess);
            continue;
        }
        guessedLetters[len(guessedLetters)] = guess;
        guessedLetters[len(guessedLetters) + 1] = '\0';
        if (!find(guess, word)) {
            attempts--;
            printf("Incorrect guess! Attempts left: %d\n", attempts);
            j++;
            switch (j) {
                case 0:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 1:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 2:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |      |\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 3:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |     /|\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 4:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |     /|\\\n");
                    printf("   |\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 5:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |     /|\\\n");
                    printf("   |     /\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                case 6:
                    printf("   --------\n");
                    printf("   |      |\n");
                    printf("   |      O\n");
                    printf("   |     /|\\\n");
                    printf("   |     / \\\n");
                    printf("   |\n");
                    printf("   -\n");
                    break;
                default:
                    printf("Your game is over\nYOU LOSE!!\n");
                    return 0;
            }
        }
        displayWord(word, guessedLetters);
        int allGuessed = 1;
        for (int i = 0; word[i] != '\0'; i++) {
            if (!find(word[i], guessedLetters)) {
                allGuessed = 0;
                break;
            }
        }
        if (allGuessed) {
            printf("Congratulations! You guessed the word!\n");
            break;
        }
    }
    if (attempts == 0) {
        printf("Out of attempts! The word was: %s\n", word);
    }
    return 0;
}
