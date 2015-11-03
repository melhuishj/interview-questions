#include <iostream>
#include <vector>

using namespace std;


void split(vector<int> & list, int first, int last, vector<int> & work);
void merge(vector<int> & list, int first, int middle, int last, vector<int> & work);
void copy(vector<int> & list, int first, int last, vector<int> & work);

void sort(vector<int> & list) {
  vector<int> work;
  work.resize(list.size());

  split(list, 0, list.size(), work);
  list = work;
}

void split(vector<int> & list, int first, int last, vector<int> & work)
{
  if ((last - first) < 2) return; //sorted
  else {
    int middle = (first + last) / 2;
    split(list, first, middle, work);
    split(list, middle, last, work);
    merge(list, first, middle, last, work);
    copy(list, first, last, work);
  }
}

void merge(vector<int> & list, int first, int middle, int last, vector<int> & work)
{
  int it0 = first;
  int it1 = middle;
  
  for (int i = first; i < last; i++) {
    if ((it0 < middle) && (it1 >= last || list[it0] <= list[it1])) {
      work[i] = list[it0++];
    } else {
      work[i] = list[it1++];
    }
  }
}

void copy(vector<int> & list, int first, int last, vector<int> & work)
{
  for (int i = first; i < last; i++) list[i] = work[i];
}

int main()
{
  vector<int> list;

  int n;
  while (cin >> n) {
    list.push_back(n);
  }

  sort(list);
  for (auto it : list) {
    cout << it << " ";
  }
  cout << endl;
}
