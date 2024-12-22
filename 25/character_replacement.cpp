#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> count;
    int maxFreq = 0, left = 0, result = 0;

    for (int right = 0; right < s.length(); ++right) {
        count[s[right]]++;
        maxFreq = max(maxFreq, count[s[right]]);
        
        
        while ((right - left + 1) - maxFreq > k) {
            count[s[left]]--;
            left++;
        }

        result = max(result, right - left + 1);
    }

    return result;
}

int main() {
    string s = "ABAB";
    int k = 2;
    cout << "Result: " << characterReplacement(s, k) << endl;
    return 0;
}