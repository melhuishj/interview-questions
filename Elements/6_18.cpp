#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string decode(string s);
string encode(string s);

int main()
{
  char op;

  while (cin >> op) {
    cin.get();
    string t;
    getline(cin, t);
    if (op == 'd') cout << t << " --> " << decode(t) << endl;
    else cout << t << " --> " << encode(t) << endl;
  }
}

string decode(string s)
{
  stringstream str(s);
  string out;
  char c;
  int count(0);

  while (str >> c) {
    if ((c >= '0') && (c <= '9')) {
      count *= 10;
      count += c - '0';
    } else {
      out.resize(out.size() + (count ? count : 1), c);
      count = 0;
    }
  }

  return out;
}

string encode(string s)
{
  stringstream str(s);
  stringstream out;
  char c;
  char cur;
  int count(0);

  str >> cur;
  count++;

  while (str >> c) {
    if (c == cur) count++;
    else {
      if (count > 1) out << count;
      out << cur;
      cur = c;
      count = 1;
    }
  }

  return out.str();
}
