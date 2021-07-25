#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    map<char,char> paren = {{'[',']'},{'{','}'},{'(',')'}};
    string s;
    cin >> s;
    stack<char> stack;
    for (char c : s){
        if (c == '[' || c == '{' || c == '('){
            stack.push(paren[c]);
        }
        else if (c == ']' || c == '}' || c == ')'){
            if (!stack.empty() && stack.top() == c) {
                stack.pop();
            } else {
                cout << "Incorrect\n";
                return 0;
            }
        }
    }
    if (stack.empty()) cout << "Correct\n";
    else cout << "Incorrect\n";
}