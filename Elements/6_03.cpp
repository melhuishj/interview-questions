#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
  int z;
  int minHeight = INT_MAX;
  int capacity = 0;
  
  while (cin >> z) {
    cin >> z;//Ignore first two values
    cin >> z;
    capacity = max(capacity, z - minHeight);
    minHeight = min(minHeight, z);
  }

  cout << capacity << endl;
}
