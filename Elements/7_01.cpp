#include <iostream>
#include <sstream>

using namespace std;

struct node {
  int data;
  node * next;
};

int main()
{
  string str;
  stringstream ss;
  node * L, * F, * LF;
  
  getline(cin, str);
  ss.str(str);

  int n;
  ss >> n;
  L = new node;
  L->data = n;
  L->next = NULL;
  node * cur = L;
  while (ss >> n) {
    cur->next = new node;
    cur->next->data = n;
    cur->next->next = NULL;
    cur = cur->next;
  }

  getline(cin, str);
  ss.str(str);
  ss.clear();

  ss >> n;
  F = new node;
  F->data = n;
  F->next = NULL;
  cur = F;
  while (ss >> n) {
    cur->next = new node;
    cur->next->data = n;
    cur->next->next = NULL;
    cur = cur->next;
  }

  if (L->data < F->data) {
    LF = L;
    L = L->next;
  } else {
    LF = F;
    F = F->next;
  }

  cur = LF;

  while (L && F) {
    if (L->data < F->data) {
      cur->next = L;
      L = L->next;
    } else {
      cur->next = F;
      F = F->next;
    }
    cur = cur->next;
  }

  if (L) cur->next = L;
  else cur->next = F;

  cur = LF;
  while (cur) {
    cout << cur->data << " --> ";
    cur = cur->next;
  }
  cout << "NULL" << endl;
}
