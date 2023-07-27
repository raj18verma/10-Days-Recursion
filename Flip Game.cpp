#include <bits/stdc++.h> 
bool canNinjaWin(string& str) {
    // Write your code here.
    int n = str.length();
    if (n < 2) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == '$' && str[i + 1] == '$') {
            string changed_str = str.substr(0, i) + "**" + str.substr(i + 2);
            if (!canNinjaWin(changed_str)) {
                return true;
            }
        }
    }
    return false;
}
