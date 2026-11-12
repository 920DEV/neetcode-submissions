class Solution {
   public:
    bool isValid(string s) {
        stack<char> chrStack;

        for (int i = 0; i < s.length(); i++) {
            if (chrStack.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;

            if (s[i] == ')' && chrStack.top() == '(') {
                chrStack.pop();
                continue;
            }
            else if (s[i] == ')' && chrStack.top() != '(') return false;

            if (s[i] == ']' && chrStack.top() == '[') {
                chrStack.pop();
                continue;
            }
            else if (s[i] == ']' && chrStack.top() != '[') return false;

            if (s[i] == '}' && chrStack.top() == '{') {
                chrStack.pop();
                continue;
            }
            else if (s[i] == '}' && chrStack.top() != '{') return false;
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                chrStack.push(s[i]);
            }
        }
        if (chrStack.empty()) return true;
        return false;
    }
};
