#include <iostream>
#include <vector>

using namespace std;

void displayRules();
bool checkHorizontal(const vector<vector<int>>& gameBoard, const vector<int>& lastMove);
bool checkVertical(const vector<vector<int>>& gameBoard, const vector<int>& lastMove);
bool checkDiagonal(const vector<vector<int>>& gameBoard, const vector<int>& lastMove);
vector<int> playerInput(bool player, vector<vector<int>>& gameBoard);
void displayGameBoard(const vector<vector<int>>& gameBoard);
void victory();
int firstAvailableCell (const vector<vector<int>>& gameBoard, int colonne);

const int LIGNE = 6;
const int COLONNE = 7;

int main(){
    vector<int> xAxisGameBoard(7, 0);
    vector<vector<int>> gameBoard(6, xAxisGameBoard);
    vector<int> lastMovePlayer(2, -1);

    //displayRules();
    displayGameBoard(gameBoard);

    bool playerTurn = 0;
    bool winner = false;

    while (!winner){
        lastMovePlayer = playerInput(playerTurn, gameBoard);
        displayGameBoard(gameBoard);

        //winner  =  || checkHorizontal(gameBoard) || checkVertical(gameBoard);
        winner = checkHorizontal(gameBoard, lastMovePlayer);
        playerTurn = winner ? playerTurn : !playerTurn;
    }

    //victory();
    return 0;
}

vector<int> playerInput(bool player, vector<vector<int>>& gameBoard)
{
    vector<int> movePlayer(2, -1);
    int playerChar = !player ? 1 : 2;
    int colonne = -1;
    int firstCellAvailable = -1;

    int sizeBoard = gameBoard[0].size();

    do
    {
        cout << "Entrez le numero de colonne :";
        cin >> colonne;
        colonne--;

        bool checkCondition = colonne >= 0 && colonne < sizeBoard;
        if (!checkCondition){
            cout << "Colonne non valide" << endl;
            continue;
        }


        firstCellAvailable = firstAvailableCell(gameBoard, colonne);
        if(firstCellAvailable == -1)
        {
            cout << "Colonne Pleine " << endl;
        }

    }while (!(colonne >= 0 && colonne < sizeBoard) || firstCellAvailable == -1);

    gameBoard.at(firstCellAvailable).at(colonne) = playerChar;

    movePlayer.at(0) = firstCellAvailable;
    movePlayer.at(1) = colonne;
    return movePlayer;
}

bool checkVertical(const vector<vector<int>>& gameBoard, const vector<int>& lastMove){


}



bool checkHorizontal(const vector<vector<int>>& gameBoard, const vector<int>& lastMove){
    bool right = true;
    bool left = true;
    int ligneLastMove = lastMove.at(0);
    int colonneLastMove = lastMove.at(1);
    int playerValue = gameBoard.at(ligneLastMove).at(colonneLastMove);
    int countTrailing = 1;


    for (int i = 1; i <= 3; i++){
        int rightIndex = colonneLastMove + i;
        int leftIndex = colonneLastMove - i;
        if (right && rightIndex < gameBoard.at(ligneLastMove).size()){
            int checkedCellValue = gameBoard.at(ligneLastMove).at(rightIndex);
            if (checkedCellValue == playerValue) {
                countTrailing++;
            }else{
                right = false;
            }
        }
        if (left && leftIndex >= 0){
            int checkedCellValue = gameBoard.at(ligneLastMove).at(leftIndex);
            if(checkedCellValue == playerValue){
                countTrailing++;
            }else{
                left = false;
            }
        }
    }
    cout << countTrailing << endl;

    return (countTrailing >= 4);
}


int firstAvailableCell (const vector<vector<int>>& gameBoard, int colonne){
    for (int i = gameBoard.size() - 1; i >= 0; i--){
        if(gameBoard.at(i).at(colonne) == 0) {
            return i;
        }
    }
    return -1;
}

void displayGameBoard(const vector<vector<int>>& gameBoard)
{

    for (int y = 0; y < gameBoard.size(); ++y) {
        cout << "|";
        for (int x = 0; x < gameBoard[y].size(); ++x) {
            cout << " " << gameBoard.at(y).at(x) << " |";
        }
        cout << endl;
    }

    //Affichage de l'interface d'aide à l'utilisateur
    for (int i = 1; i <= 7; ++i) {
            cout << "  " << i << " ";
    }
    cout << endl;
}
