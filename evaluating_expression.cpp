#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int calculate(string s)
{
    stack<int> stk;
    int currentNum = 0;
    char operation = '+';
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        char currentChar = s[i];

        if (isdigit(currentChar))
        {
            currentNum = currentNum * 10 + (currentChar - '0');
        }

        if (!isdigit(currentChar) && !isspace(currentChar) || i == n - 1)
        {
            if (operation == '+')
            {
                stk.push(currentNum);
            }
            else if (operation == '-')
            {
                stk.push(-currentNum);
            }
            else if (operation == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * currentNum);
            }
            else if (operation == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / currentNum);
            }

            operation = currentChar;
            currentNum = 0;
        }
    }

    int result = 0;
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int main()
{
    string s = "3+2*2";
    cout << calculate(s) << endl;
    return 0;
}

