#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input;
    input.open("input.txt");
    char c;
    string current = "";
    string max = "";
    char answ='\0';
    char prev_value;
    input.get(prev_value);
    current.push_back(prev_value);
    while (input.get(c)) {
        if (prev_value==c) {
            current.push_back(c);
        }
        else {
            if (current.size() > max.size()) {
                max = current;
                answ=max[0];
            }
            current = "";
            current.push_back(c);
        }
        prev_value = c;
    }
    cout << answ << " " << max.size();
    input.close();
}

