#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push(i);
    }

    vector<int> result;

    while (!people.empty()) {
        for (int i = 1; i < K; ++i) {
            people.push(people.front());
            people.pop();
        }
        result.push_back(people.front());
        people.pop();
    }

    cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}
