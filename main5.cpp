#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int prioritetnost(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

string remove_brackets(string s)
{
    while (s[0] == '(' && s[s.size() - 1] == ')')
    {
        int bracket_depth = 1;
        for (int i = 1; i < s.size() - 1; i++)
        {
            char c = s[i];
            if (c == '(')
            {
                bracket_depth++;
            }
            else if (c == ')')
            {
                bracket_depth--;
                if (bracket_depth == 0)
                {
                    return s;
                }
            }
        }
        s = s.substr(1, s.size() - 2);
    }
    return s;
}

int solve(string s)
{
    s = remove_brackets(s);

    int bracket = 0;
    int min_priority = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        int p = prioritetnost(c);
        if (p != -1 && bracket == 0 && (min_priority == -1 || p <= prioritetnost(s[min_priority])))
        {
            min_priority = i;
        }
        else if (c == '(')
        {
            bracket++;
        }
        else if (c == ')')
        {
            bracket--;
        }
    }

    if (min_priority != -1)
    {
        int a = solve(s.substr(0, min_priority));
        int b = solve(s.substr(min_priority + 1, s.size()));

        switch (s[min_priority])
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
    }

    return stoi(s);
}

int main()
{
    string s;
    getline(cin, s);
    cout << solve(s);
    return 0;
}
