#include <iostream>
#include <vector>

using namespace std;

void dutchFlagOrdering(vector<int> & v, int i);

int main()
{
  vector<int> v;
  int t;
  int i;

  cin >> i;
  while (cin >> t) {
    v.push_back(t);
  }

  for (auto it : v) {
    cout << it << endl;
  }

  cout << "Pivot (v[" << i << "]): " << v[i] << endl << endl;

  dutchFlagOrdering(v, i);

  for (auto it : v) {
    cout << it << endl;
  }
}


void dutchFlagOrdering(vector<int> & v, int i)
{
  int pivot = v[i];
  int back = v.size() - 1;

  for (int j = 0; j < back; j++) {
    if (!(v[j] < pivot)) {
      int t = v[j];
      v[j] = v[back];
      v[back--] = t;
      j--;
    }
  }

  int backg = v.size() - 1;

  for (back; back < backg; back++) {
    if (!(v[back] == pivot)) {
      int t = v[back];
      v[back] = v[backg];
      v[backg--] = t;
      back--;
    }
  }
}
