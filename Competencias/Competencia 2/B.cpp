#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int prefixSuffixArray[1000001];
    string inputString;
    cin >> inputString;

    int currentMatchIndex;

    prefixSuffixArray[0] = currentMatchIndex = -1;

    for (int i = 1; i < inputString.length(); i++) {

        while (currentMatchIndex != -1 && inputString[i] != inputString[currentMatchIndex + 1])
            currentMatchIndex = prefixSuffixArray[currentMatchIndex];

        if (inputString[i] == inputString[currentMatchIndex + 1])
            prefixSuffixArray[i] = ++currentMatchIndex;
        else
            prefixSuffixArray[i] = -1;
    }

    int stringLength = inputString.length();

    int longestPrefixSuffix = prefixSuffixArray[stringLength - 1];
    int repeatingPrefixSuffix = prefixSuffixArray[longestPrefixSuffix];
    if (longestPrefixSuffix == -1)
        repeatingPrefixSuffix = -1;

    for (int i = 1; i < stringLength - 1; i++) {
        if (prefixSuffixArray[i] == longestPrefixSuffix)
            repeatingPrefixSuffix = longestPrefixSuffix;
    }

    if (repeatingPrefixSuffix == -1)
        cout << "Just a legend" << endl;
    else {
        cout << inputString.substr(0, repeatingPrefixSuffix + 1) << endl;
    }
}
