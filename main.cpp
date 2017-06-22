#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printChoices(int n);
void checkOutcome(int playNum, int compNum);

int playWinCount = 0;
int compWinCount = 0;
int playNum;
int compNum;
int playAgain = 0;

int main() {
    do {
        cout << "Welcome to rock, paper, scissors!" << endl;
        do {
            cout << "Please select your choice:" << endl
                 << "0 - Rock" << endl
                 << "1 - Paper" << endl
                 << "2 - Scissors" << endl;
            cin >> playNum;
        } while (playNum > 2 || playNum < 0);
        compNum = rand() % 3;
        cout << "Player threw ";
        printChoices(playNum);
        cout << "Comp threw " << compNum;
        printChoices(compNum);
        checkOutcome(playNum, compNum);

        cout << endl;
        cout << "Results: " << endl;
        cout << "Total player victories " << playWinCount << endl;
        cout << "Total computer victories " << compWinCount << endl;
        do {
            cout << "Play again?" << endl;
            cout << "0 - No 1 - Yes" << endl;
            cin >> playAgain;
        } while (playAgain > 1 || playAgain < 0);
    } while (playAgain == 1);
    return EXIT_SUCCESS;
}

void printChoices(int n) {
    switch (n) {
        case 0:
            cout << "rock" << endl;
            break;
        case 1:
            cout << "paper" << endl;
            break;
        case 2:
            cout << "scissors" << endl;
            break;
        default:
            cout << "error" << endl;
            break;
    }
}

void checkOutcome(int playNum, int compNum) {
    if (playNum == 0) {
        if (compNum == 0) {
            cout << "Game is tied" << endl;
        }
        else if (compNum == 1) {
            cout << "Computer wins" << endl;
            compWinCount++;
        }
        else {
            cout << "Player wins" << endl;
            playWinCount++;
        }
    }
    else if (playNum == 1) {
        if (compNum == 0) {
            cout << "Player wins" << endl;
            playWinCount++;
        }
        else if (compNum == 1) {
            cout << "Game is tied" << endl;
        }
        else {
            cout << "Computer wins" << endl;
            compWinCount++;
        }
    }
    else {
        if (compNum == 0) {
            cout << "Computer wins" << endl;
            compWinCount++;
        }
        else if (compNum == 1) {
            cout << "Player wins" << endl;
            playWinCount++;
        }
        else {
            cout << "Game is tied" << endl;
        }
    }
}