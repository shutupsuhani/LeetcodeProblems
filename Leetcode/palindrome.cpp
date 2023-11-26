#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        vector<int> digits;
        int num = x;
        while(num > 0){
            digits.push_back(num % 10);
            num /= 10;
        }

        int i = 0, j = digits.size() - 1;
        while(i < j){
            if(digits[i] != digits[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;        
    }
};

int main () {
    Solution check;

    int x1 = 121;
    cout << "Example 1: " << (check.isPalindrome(x1) ? "true" : "false") << endl;

    int x2 = -121;
    cout << "Example 2: " << (check.isPalindrome(x2) ? "true" : "false") << endl;

    int x3 = 10;
    cout << "Example 3: " << (check.isPalindrome(x3) ? "true" : "false") << endl;

    return 0;
}
