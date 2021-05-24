#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int prov_operation(string l) {
    if ("/" == l) return 1;
    if ("*" == l) return 2;
    if ("+" == l) return 3;
    if ("-" == l) return 4;
    return -1;
}

int main()
{
    stack<int> chisl;
    string str;
    getline(cin, str);
    str.push_back(' ');
    int probel = str.find(' ');
    while (probel != -1) {
        string el = str.substr(0, probel);
        int op = prov_operation(el);
        if (op == -1) {
            chisl.push(stoi(el));
        }
        else
        {
            int ch1 = chisl.top();
            chisl.pop();
            int ch2 = chisl.top();
            chisl.pop();
            if (op == 1) {
                chisl.push(ch2 / ch1);
            }
            if (op == 2) {
                chisl.push(ch2 * ch1);
            }
            if (op == 3) {
                chisl.push(ch2 + ch1);
            }
            if (op == 4) {
                chisl.push(ch2 - ch1);
            }
        }
        str = str.substr(probel + 1);
        probel = str.find(' ');
    }

    if (chisl.size() != 1) {
        cout << "ERROR";
    }
    else {
        cout << chisl.top();
    }
}


