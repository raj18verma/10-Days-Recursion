#include <bits/stdc++.h> 

int helper(int i, vector<int>& digits, int N, int index = 0, int number = 0) {
    if (index == i) {
        return number <= N;
    }

    int count = 0;
    for (int digit : digits) {
        int newNumber = number * 10 + digit;
        if (newNumber <= N) {
            count += helper(i, digits, N, index + 1, newNumber);
        }
    }
    return count;
}

int possibleNumbers(int n, int m, vector<int>& digits) {
	// Write your code here.
	int D = to_string(n).length();
    int ans = 0;

    for (int i = 1; i <= D; i++) {
        ans += helper(i, digits, n);
    }

    return ans;
}


// This code does not run for all the test cases
