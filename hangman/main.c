#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6
#define WORD_COUNT 5

const char *wordList[WORD_COUNT] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry"
};

void printHangman(int tries) {
    printf("\n");
    switch (tries) {
        case 0: printf("   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========\n"); break;
        case 1: printf("   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========\n"); break;
        case 2: printf("   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========\n"); break;
        case 3: printf("   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========\n"); break;
        case 4: printf("   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========\n"); break;
        case 5: printf("   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========\n"); break;
        case 6: printf("   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n=========\n"); break;
    }
}

void playGame() {
    srand(time(NULL));  // 랜덤 시드 설정
    const char *chosenWord = wordList[rand() % WORD_COUNT];  // 랜덤 단어 선택
    int wordLength = strlen(chosenWord);
    char guessedWord[wordLength + 1];
    int tries = 0;
    int guessedCorrectly = 0;

    // 초기화
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';  // null terminator 추가

    printf("단어 맞추기 게임에 오신 것을 환영합니다!\n");

    while (tries < MAX_TRIES && !guessedCorrectly) {
        printf("\n현재 상태: %s\n", guessedWord);
        printHangman(tries);
        char guess;
        printf("문자를 추측해보세요: ");
        scanf(" %c", &guess);

        int correctGuess = 0;

        // 정답 확인
        for (int i = 0; i < wordLength; i++) {
            if (chosenWord[i] == guess) {
                guessedWord[i] = guess;  // 맞춘 경우
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            tries++;  // 틀린 경우 시도 횟수 증가
            printf("틀렸습니다! 남은 기회: %d\n", MAX_TRIES - tries);
        }

        // 단어를 모두 맞춘 경우
        if (strcmp(chosenWord, guessedWord) == 0) {
            guessedCorrectly = 1;
        }
    }

    // 게임 종료
    if (guessedCorrectly) {
        printf("\n축하합니다! 단어를 맞췄습니다: %s\n", chosenWord);
    } else {
        printf("\n게임 오버! 정답은: %s\n", chosenWord);
    }
}

int main(void) {
    playGame();
    return 0;
}
