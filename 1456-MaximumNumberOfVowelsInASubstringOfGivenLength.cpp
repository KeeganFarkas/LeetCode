// Given a string s and an integer k, return the maximum number of vowel 
// letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.


// Example 1:
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:
// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

// Accepted: 05/04/2023 - 19ms beats 81.96% - 10MB beats 68.38%

#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxV = 0, currentV = 0;
        for (int i = 0; i < s.length(); i++) {
            // Add the next character's vowel count to the window
            switch (s[i]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    currentV++;
            }

            // Remove the first character's vowel count when the window is 
            // larger than k
            if (i >= k) {
                switch (s[i - k]){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        currentV--;
                }
            }

            // Update the maximum vowel count
            if (i >= k - 1 && currentV > maxV) {
                maxV = currentV;
            }
        }
        return maxV;
    }
};