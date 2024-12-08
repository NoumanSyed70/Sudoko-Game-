/* Suduko Game
9 * 9 matrix
45 sum from each angle
IF user press for one more game the difficulty should increase
for this I can change the order of matrix on each new gameand for all the game I can
make functions for easy proceedings
*/
#include <iostream>
using namespace std;


// To check number of rows //
bool validrow(int board[9][9], int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) { // Board is sudoko board
            return false;
        }
    }
    return true;
}


// to check if the number entered by user can be placed in column //
bool validcolumn(int board[9][9], int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false; // terminate if number present
        }
    }
    return true;
}



// To check if number can be placed in grid (3*3) matrix //
bool validgrid(int board[9][9], int row, int col, int num) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}



// to check if the given number can be placed in the sudoko board //
bool valid(int board[9][9], int row, int col, int num) {
    return validrow(board, row, num) && validcolumn(board, col, num) && validgrid(board, row, col, num);
}



// to print the board
void print_Board(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8) {
                cout << "| ";
            } // to draw | line after every three columns //
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < 8) {
            cout << "---------------------" << endl; // to draw -- horizontal line after every three rows //
        }
    }
}


int games = 0; // Global variable and can be used in and outside main too //


int main() {
    int board[9][9];
    if (games == 1) {
        cout << "    .-^-." << endl;
        cout << "   /     \\" << endl;
        cout << "  | () () |" << endl;
        cout << "   \\  u  /" << endl;
        cout << "    \\_-_/" << endl;
        cout << "\n\n THE LEVEL IS HARDER NOW!!!!\n " << endl;
        int anotherboard[9][9] = {
            {0, 0, 0, 3, 0, 5, 0, 2, 0},
            {0, 7, 5, 0, 2, 0, 0, 0, 9},
            {9, 2, 0, 1, 4, 7, 3, 0, 6},
            {6, 0, 3, 7, 5, 0, 0, 0, 0},
            {0, 4, 0, 0, 0, 1, 5, 0, 3},
            {5, 0, 9, 2, 3, 0, 0, 1, 4},
            {0, 3, 0, 4, 0, 9, 0, 7, 0},
            {4, 0, 7, 0, 8, 0, 6, 0, 2},
            {0, 0, 0, 5, 6, 0, 4, 3, 0}
        };
        /* Solved Board
          1 6 4 | 3 7 5 | 9 2 8
          3 7 5 | 6 2 8 | 1 4 9
          9 2 8 | 1 4 7 | 3 5 6
          6 1 3 | 7 5 4 | 2 8 9
          7 4 2 | 8 9 1 | 5 6 3
          5 8 9 | 2 3 6 | 7 1 4
          2 3 6 | 4 1 9 | 8 7 5
          4 5 7 | 9 8 3 | 6 1 2
          8 9 1 | 5 6 2 | 4 3 7   
        */
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = anotherboard[i][j];
            }
        }
    }
    else if(games == 0)
        {
            int aboard[9][9] = {
                {5, 3, 0, 6, 7, 8, 1, 9, 2},
                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                {1, 9, 8, 3, 4, 2, 0, 6, 7},
                {0, 5, 9, 7, 6, 1, 4, 2, 3},
                {4, 2, 6, 8, 5, 3, 7, 0, 9},
                {7, 1, 0, 9, 0, 4, 8, 5, 6},
                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                {2, 8, 0, 4, 1, 9, 0, 3, 5},
                {0, 4, 5, 2, 8, 6, 1, 7, 9}
            };
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    board[i][j] = aboard[i][j];
                }
            }
            /*
             Solved Sudoko Board
            5 3 4 | 6 7 8 | 9 1 2
            6 7 2 | 1 9 5 | 3 4 8
            1 9 8 | 3 4 6 | 5 7 9
            8 5 9 | 7 6 3 | 2 1 4
            4 2 6 | 8 5 3 | 7 9 1
            7 1 3 | 9 2 4 | 8 6 6
            9 6 1 | 5 3 7 | 2 8 4
            2 8 7 | 4 1 9 | 6 3 5
            3 4 5 | 2 8 6 | 1 7 9
            */
        }
    else if (games == 2) {
        cout << "\n\n THE LEVEL IS HARDEST NOW!!!!\n " << endl;
        cout << "     .-.-." << endl;
        cout << "    /o o \\" << endl;
        cout << "   |  -  |" << endl;
        cout << "    \\ ^ /" << endl;
        cout << "     \\_/" << endl;
        cout << "    /|\\" << endl;
        cout << "   / | \\" << endl;
        cout << "  /  |  \\" << endl;
        cout << " /   |   \\" << endl;
        cout << "/    |    \\\n\n" << endl;
        int finalboard[9][9] = {
                                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 3, 0, 8, 5},
                                {0, 0, 1, 0, 2, 0, 0, 0, 0},
                                {0, 0, 0, 5, 0, 7, 0, 0, 0},
                                {0, 0, 4, 0, 0, 0, 1, 0, 0},
                                {0, 9, 0, 0, 0, 0, 0, 0, 0},
                                {5, 0, 0, 0, 0, 0, 0, 7, 3},
                                {0, 0, 2, 0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0}
                                };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = finalboard[i][j];
            }
        }
        /*
        Solved Suduko Board
        9 8 7 | 6 5 4 | 3 2 1
        6 5 4 | 3 2 1 | 9 7 8
        3 2 1 | 9 8 7 | 6 5 4
        ------+------+------
        8 9 6 | 7 1 5 | 4 3 2
        7 1 3 | 4 6 2 | 8 9 5
        4 5 2 | 1 3 8 | 7 6 9
        ------+------+------
        5 3 8 | 2 4 6 | 1 1 7
        2 7 9 | 5 1 3 | 6 4 8
        1 6 5 | 8 7 9 | 2 3 4
        */
        
    }
    cout << "Initial Sudoku board:\n";
    print_Board(board);
    bool finish = true;
    int row, col, value;
    while (true) {
        cout << "Enter the row, column, and value to replace on the board or -1,-1,-1 to break: ";
        cin >> row >> col >> value;
        if (row == -1 || col == -1 || value == -1) {
            break;
        }
        if (row < 0 || row >= 9 || col < 0 || col >= 9 || value < 1 || value > 9) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }
        if (valid(board, row, col, value)) {
            board[row][col] = value;
            cout << "Sudoku board updated:" << endl;
            print_Board(board);
        }
        else {
            cout << "Invalid move. Please try again." << endl;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    finish = false;
                    break;
                }
            }
        }

        // Check if the Sudoku board is completed
        if (finish) {
            cout << "You Win!" << endl;
            cout << "Do you want to play again? (y/n): ";
            char response;
            cin >> response;
            if (response == 'y') {
                games = games + 1; // To count total number of games played by user
                if (games == 2) {
                    cout << "You won all levels! Great Congrats! GoodBye....... <3" << endl;
                    break;
                }
                main();
            }
            else {
                cout << "Number of games you played are: " << games << endl;
                cout << "Thank you for playing." << endl;
                break;
            }
        }
    }

    return 0;
}