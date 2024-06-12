#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Truck {
    int weight;
    int entry_time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<Truck> bridge;
    int total_weight = 0;
    int time = 0;
    int index = 0;

    while (index < truck_weights.size() || !bridge.empty()) {
        time++;

        if (!bridge.empty() && time - bridge.front().entry_time >= bridge_length) {
            total_weight -= bridge.front().weight;
            bridge.pop();
        }

        if (index < truck_weights.size() && total_weight + truck_weights[index] <= weight) {
            bridge.push({truck_weights[index], time});
            total_weight += truck_weights[index];
            index++;
        }
    }

    return time;
}

int main() {
    vector<int> truck_weights1 = {7, 4, 5, 6};
    int result1 = solution(2, 10, truck_weights1); // Expected output: 8
    cout << "Result: " << result1 << endl;

    vector<int> truck_weights2 = {10};
    int result2 = solution(100, 100, truck_weights2); // Expected output: 101
    cout << "Result: " << result2 << endl;

    vector<int> truck_weights3 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int result3 = solution(100, 100, truck_weights3); // Expected output: 110
    cout << "Result: " << result3 << endl;

    return 0;
}
