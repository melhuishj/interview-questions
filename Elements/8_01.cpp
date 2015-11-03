#include <iostream>
#include <stack>

using namespace std;

struct maxCount
{
  int val;
  int num;
};

class maxStack
{
public:

  void push(int n)
  {
    data.push(n);
    maxCount mC;
    if (max.empty()) {
      mC.val = n;
      mC.num = 1;
      max.push(mC);
    } else if (max.top().val < n) {
      mC.val = n;
      mC.num = 1;
      max.push(mC);
    } else {
      max.top().num++;
    }
  }

  int top()
  {
    return data.top();
  }

  void pop()
  {
    if (max.top().num == 1) max.pop();
    else max.top().num--;
    data.pop();
  }

  bool empty()
  {
    return data.empty();
  }

  int getMax()
  {
    return max.top().val;
  }

private:
  stack<int> data;
  stack<maxCount> max;
};

int main()
{
  int n;
  maxStack myStack;
  
  while (cin >> n) {
    myStack.push(n);
  }

  while (!myStack.empty()) {
    cout << "Max: " << myStack.getMax() << endl << "Popping " << myStack.top() << endl;
    myStack.pop();
  }
}
