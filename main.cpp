#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    int n;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string command;
        getline(cin, command);

        if (command.substr(0, 4) == "push") {
            int num = stoi(command.substr(5));
            s.push(num);
        } else if (command == "top") {
            if (s.empty()) {
                cout << -1 << endl;
            } else {
                cout << s.top() << endl;
            }
        } else if (command == "size") {
            cout << s.size() << endl;
        } else if (command == "empty") {
            cout << s.empty() << endl;
        } else if (command == "pop") {
            if (s.empty()) {
                cout << -1 << endl;
            } else {
                cout << s.top() << endl;
                s.pop();
            }
        }
    }

    return 0;
}
