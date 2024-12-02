#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

bool is_safe(vector<int> report){
    bool is_safe = true;
    int b = 0;
    for(int i=0;i<report.size()-1;i++){
        int a = report[i] - report[i+1];
        if (i == 0){
            if(a>0 && abs(a)>0 && abs(a)<4){
                b = 1; //1 for descending
            }
            else if(a<0 && abs(a)>0 && abs(a)<4){
                b = 2; //2 for ascending
            }
            else{
                is_safe = false;
                break;
            }
        }
        else{
            if(a>0 && b==1 && abs(a)>0 && abs(a)<4){
                continue;
            }
            else if(a<0 && b==2 && abs(a)>0 && abs(a)<4){
                continue; 
            }
            else{
                is_safe = false;
                break;
            }
        }

    }
    return is_safe;
}

int safe_report(const string &file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error."<< endl;
        return -1;
    }
    
    string line;
    int count = 0;
    while(getline(file,line)){
        istringstream iss(line);
        vector<int> report;
        int num;

        while (iss >> num){
            report.push_back(num);
        }
        if(is_safe(report)){
            count++;
        }
        else if(!is_safe(report)){
            for(int i=0; i<report.size(); i++){
                vector<int> m_report = report;
                m_report.erase(m_report.begin()+i);
                if(is_safe(m_report)){
                    count++;
                    break;
                }
                else{
                    continue;
                }
            }
        }
    }
    return count;
}

int main() {
    string file_name = "input.txt";
    int s_report = safe_report(file_name);

    if (s_report != -1) {
        cout << "Total Safe Reports: " << s_report << endl;
    }
    return 0;
}