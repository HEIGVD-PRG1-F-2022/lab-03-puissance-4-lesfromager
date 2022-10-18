#include <iostream>
#include <vector>

using namespace std;

void displayRules();
bool checkHorizontal(const vector<vector<int>>& gameBoard);
bool checkVertical(const vector<vector<int>>& gameBoard);
bool checkDiagonal(const vector<vector<int>>& gameBoard);
void playerInput(bool player, vector<vector<int>>& gameBoard);
void displayGameBoard(const vector<vector<int>>& gameBoard);
void victory();


int main(){
    vector<int> colGameBoard(7, 0);
    vector<vector<int>> gameBoard(6, colGameBoard);

    displayRules();
    displayGameBoard(gameBoard);

    bool playerTurn = 0;
    bool winner = false;

    while (!winner){
        playerInput(playerTurn, gameBoard);
        displayGameBoard(gameBoard);

        winner  = checkDiagonal(gameBoard) || checkHorizontal(gameBoard) || checkVertical(gameBoard);

        playerTurn = winner ? playerTurn : !playerTurn;
    }

    victory();
    return 0;
}

