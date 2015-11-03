#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> results;
  char c;

  while (cin >> c) {
    int a, b;
    
    switch (c) {
    case ' ':
      break;
    case '+':
      b = results.top();
      results.pop();
      a = results.top();
      results.pop();
      results.push(a + b);
      break;
    case '-':
      b = results.top();
      results.pop();
      a = results.top();
      results.pop();
      results.push(a - b);
      break;
    case '*':
      b = results.top();
      results.pop();
      a = results.top();
      results.pop();
      results.push(a * b);
      break;
    case '/':
      b = results.top();
      results.pop();
      a = results.top();
      results.pop();
      results.push(a / b);
      break;
    default:
      cin.putback(c);
      cin >> a;
      results.push(a);
      break;
    }
  }

  cout << results.top() << endl;
}
