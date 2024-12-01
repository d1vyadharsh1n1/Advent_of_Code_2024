#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int similarity_score(const string &file_name) {
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

    int similarity_score = 0;
    for (int i = 0; i < left.size(); i++) {
        int count =0;
        for(int j = 0; j < right.size(); j++){
            if(left[i] == right[j]){
                count++;
            }
        }
        similarity_score += (left[i] * count);
    }
   
    return similarity_score;
}

int main() {
    string file_name = "input.txt";
    int s_score = similarity_score(file_name);

    if (s_score!= -1) {
        cout << "Similarity Score " << s_score << endl;
    }
    return 0;
}
