#include <iostream>
#include <vector>

using namespace std;

bool checkRow(vector<int> & row);
bool checkColumn(vector<vector<int>> & board, int i);

int main()
{
  vector<vector<int>> board;

  int t;
  vector<int> row;

  while (cin >> t) {
    row.push_back(t);
    if (row.size() == 9) {
      board.push_back(row);
      row.clear();
    }
  }

  bool rows[9][9] = {false};
  bool columns[9][9] = {false};
  bool grids [3][3][9] = {false};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j]) {
	if (rows[i][board[i][j] - 1] || columns[j][board[i][j] - 1] || grids[i / 3][j / 3][board[i][j] - 1]) {
	  cout << "Incorrect." << endl;
	  return 0;
	}
	else {
	  rows[i][board[i][j] - 1] = true;
	  columns[j][board[i][j] - 1] = true;
	  grids[i / 3][j / 3][board[i][j] - 1] = true;
	}
      }
    }
  }

}
