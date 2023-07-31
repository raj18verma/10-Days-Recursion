#include <bits/stdc++.h>
using namespace std;

bool isAnyMapping(vector<string>& words, int row, int col, int bal,
        unordered_map<char, int>& letToDig, char digToLet[],
        int totalRows, int totalCols) {

    // If traversed all columns.
    if (col == totalCols) {
        if (bal == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // At the end of a particular column.
    if (row == totalRows) {
        return (bal % 10 == 0 && isAnyMapping(words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
    }

    string w = words[row];

    // If the current string 'W' has no character in the ('COL')th index.
    if (col >= w.length()) {
        return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
    }

    // Take the current character in the variable letter.
    char letter = w[w.length() - 1 - col];

    // Create a variable 'SIGN' to check whether we have to add it or subtract it.
    int sign;

    if (row < totalRows - 1) {
        sign = 1;
    }
    else {
        sign = -1;
    }

    /*
        If we have a prior valid mapping, then use that mapping.
        The second condition is for the leading zeros.
    */
    if (letToDig.find(letter) != letToDig.end() &&
        (letToDig[letter] != 0 || (letToDig[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {
        return isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);
    }

    // Choose a new mapping.
    else {
        for (int i = 0; i < 10; i++) {

            // If 'i'th mapping is valid then select it.
            if (digToLet[i] == '-' && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                digToLet[i] = letter;
                letToDig[letter] = i;

                // Call the function again with the new mapping.
                bool x = isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);

                if (x == true) {
                    return true;
                }

                // Unselect the mapping.
                digToLet[i] = '-';
                if (letToDig.find(letter) != letToDig.end()) {
                    letToDig.erase(letter);
                }
            }
        }
    }

    // If nothing is correct then just return false.
    return false;
}

bool isSolvable(int m, vector<string>& words, string result) {
    // Add the string 'RESULT' in the vector 'WORDS'.
    words.push_back(result);

    int totalRows;
    int totalCols;

    // Initialize 'TOTALROWS' with the size of the vector.
    totalRows = words.size();

    // Find the longest string in the vector and set 'TOTALCOLS' with the size of that string.
    totalCols = 0;

    for (int i = 0; i < words.size(); i++) {

        // If the current string is the longest then update 'TOTALCOLS' with its length.
        if (totalCols < words[i].length()) {
            totalCols = words[i].length();
        }
    }

    // Create a HashMap for the letter to digit mapping.
    unordered_map<char, int> letToDig;

    // Create an array for the digit to letter mapping.
    char digToLet[10];
    for (int i = 0; i < 10; i++) {
        digToLet[i] = '-';
    }

    return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
}

