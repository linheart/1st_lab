#include "../include/arr.h"
#include "../include/menu.h"

#include <fstream>

vector<string> parse(const string &input) {
  vector<string> tokens;
  istringstream iss(input);
  string token;

  while (iss >> token) {
    tokens.push_back(token);
  }

  return tokens;
}

void freeAll(map<string, any> &mp) {
  for (auto &[key, value] : mp) {
    if (value.type() == typeid(Array)) {
      freeArray(&any_cast<Array &>(mp[key]));
    }
  }
}

void printStructure(map<string, any> &mp, string key) {
  if (mp.find(key) != mp.end()) {
    any &value = mp[key];

    if (value.type() == typeid(Array)) {
      readArray(&any_cast<Array &>(mp[key]));
    }
  } else {
    cout << "There's no name: " << key << endl;
  }
}

int main(int argc, char **argv) {
  vector<string> tokens;
  string input;
  bool console = true;
  map<string, any> mp;

  if (argc > 1) {
    assert(string(argv[1]) == "--file" && string(argv[3]) == "--query");

    ifstream file(argv[2]);

    assert(file.is_open());

    input = argv[4];
    console = false;
    file.close();
  }

  do {
    if (console) {
      getline(cin, input);
    }

    tokens = parse(input);

    if (tokens[0] == "EXIT") {
      break;
    }

    switch (tokens[0][0]) {
    case 'M':
      mMenu(mp, tokens);
      break;
    case 'L':
      break;
    case 'Q':
      break;
    case 'S':
      break;
    case 'H':
      break;
    case 'T':
      break;
    case 'P':
      if (tokens[0] == "PRINT") {
        printStructure(mp, tokens[1]);
        break;
      }
    default:
      cout << "Wrong query" << endl;
      break;
    }
  } while (console);

  freeAll(mp);

  return 0;
}
