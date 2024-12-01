#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int total_distance(const string &file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error."<< endl;
        return -1;
    }

    vector<int> left, right;
    int num1, num2;

    while (file >> num1 >> num2) {
        left.push_back(num1);
        right.push_back(num2);
    }
    file.close();

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int distance = 0;
    for (int i = 0; i < left.size(); i++) {
        distance += abs(left[i] - right[i]);
    }

    return distance;
}

int main() {
    string file_name = "input.txt";
    int distance = total_distance(file_name);

    if (distance != -1) {
        cout << "Total distance: " << distance << endl;
    }
    return 0;
}
