#include <vector>
#include <iostream>

using namespace std;

// Primeira questão da lista prática de backtracking

bool valid_opt(vector<vector<int>>& sudoku, int row, int col, int ii) {
    for(int i = 0; i < sudoku.size(); i++) {
        if(sudoku[row][i] == ii || sudoku[i][col] == ii) {
            return false;
        }
    }
    int box_i = (row / 3)*3;
    int box_j = (col / 3)*3;
    for(int k = box_i; k < box_i+3; k++) {
        for(int m = box_j; m < box_j+3; m++) {
            if(sudoku[k][m] == ii) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku_solve(vector<vector<int>>& sudoku) {
    for(int i = 0; i < sudoku.size(); i++) {
        for(int j = 0; j < sudoku.size(); j++) {
            if(sudoku[i][j] == 0) {
                for(int ii = 1; ii <= 9; ii++) {
                    if(valid_opt(sudoku, i, j, ii)) {
                        sudoku[i][j] = ii;
                        if(sudoku_solve(sudoku)) {
                            return true;
                        }
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        vector<vector<int>> sudoku(9, vector<int>(9, 0));
        for(int j = 0; j < sudoku.size(); j++) {
            for(int l = 0; l < sudoku.size(); l++) {
                cin >> sudoku[j][l];
            }
        }
        bool solve = sudoku_solve(sudoku);
        if(!solve) {
            cout << "No solution" << "\n";
        } else {
            for(int el = 0; el < 9; el++) {
                for(int ell = 0; ell < 9; ell++) {
                    cout << sudoku[el][ell] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}