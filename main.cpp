#include <iostream>
#include <string>

using namespace std;

bool palindrom(string str);

int main() {
  string str;
  getline(cin, str);
  if (!str.empty())
    cout << palindrom(str) << endl;
  return 0;
}

bool palindrom(string str) {
  for (int i = 0, j = str.length() - 1; i < j; i++, j--)
    if (str[i] != str[j])
      return false;
  return true;
}
