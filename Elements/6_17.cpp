// Takes input from stdin in the form of an nxn array of unsigned integers preceeded
// by n on its own line.
// Using vectors because I don't care about memory.

#include <iostream>
#include <vector>

using namespace std; //sorry

typedef unsigned int ui;
typedef vector<ui> vui;
typedef vector<vui> vvui;

int main()
{
  ui N;
  vvui grid;

  cin >> N;

  //Read in input
  for (ui i = 0; i < N; i++) {
    vui temp;
    for (ui j = 0; j < N; j++) {
      ui t;
      cin >> t;
      temp.push_back(t);
    }
    grid.push_back(temp);
  }

  //Output original state
  for (auto i : grid) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }

  // To avoid needing to add - 1 in border calculations later
  N--;

  for (ui i = 0; i < (N + 2) / 2; i++) {
    for (ui j = 0; j < (N + 1) / 2; j++) {
      ui start = grid[j][i];
      grid[j][i] = grid[N - i][0 + j];
      grid[N - i][0 + j] = grid[N - j][N - i];
      grid[N - j][N - i] = grid[0 + i][N - j];
      grid[0 + i][N - j] = start;
    }
  }

  cout << endl;

  for (auto i : grid) {
    for (auto j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}
