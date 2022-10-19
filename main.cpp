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
int firstAvailableCell (const vector<vector<int>>& gameBoard, int colonne);

const int LIGNE = 6;
const int COLONNE = 7;

int main(){
    vector<int> xAxisGameBoard(7, 0);
    vector<vector<int>> gameBoard(6, xAxisGameBoard);

    //displayRules();
    displayGameBoard(gameBoard);

    bool playerTurn = 0;
    bool winner = false;

    while (!winner){
        playerInput(playerTurn, gameBoard);
        displayGameBoard(gameBoard);

        //winner  = checkDiagonal(gameBoard) || checkHorizontal(gameBoard) || checkVertical(gameBoard);

        playerTurn = winner ? playerTurn : !playerTurn;
    }

    //victory();
    return 0;
}

void playerInput(bool player, vector<vector<int>>& gameBoard)
{
    int playerChar = !player ? 1 : 2;
    int colonne = -1;
    int firstCellAvailable = -1;

    int sizeBoard = gameBoard[0].size();

    cout << sizeBoard;

    do
    {
        cout << "Entrez le numero de colonne :";
        cin >> colonne;
        if (colonne > 0 && colonne < sizeBoard){
            cout << "Colonne non valide" << endl;
            continue;
        }

        firstCellAvailable = firstAvailableCell(gameBoard, colonne);

    }while ((colonne > 0 && colonne < sizeBoard) || firstCellAvailable != -1);

    gameBoard.at(colonne).at(firstCellAvailable) = playerChar;
}

int firstAvailableCell (const vector<vector<int>>& gameBoard, int colonne){
    for (int i = gameBoard.at(0).size(); i >= 0; i--){
        if(gameBoard.at(colonne).at(i) == 0) {
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
