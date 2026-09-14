
/* 
Intuition

If a substring is an anagram of p, then both strings must have the same frequency of every character.

So, instead of generating all permutations of p, we maintain a sliding window of size p.size() in s.

We keep two frequency arrays:

freq1 → frequency of characters in p
freq2 → frequency of characters in the current window of s

Whenever both frequency arrays are equal, the current window is an anagram of p.

Approach
Create freq1 and store the frequency of each character in p.
Use two pointers, left and right, to maintain a sliding window in s.
Add s[right] to freq2 as the right pointer moves.
If the window size becomes greater than p.size(), remove s[left] from freq2 and increment left.
Compare the two frequency arrays.
If all 26 character frequencies are equal, the current window is an anagram of p, so add left to the result.
Continue until the entire string s is processed.
Complexity
Time complexity: O(26 × n) = O(n), where n is the length of s.
For every position, we compare at most 26 character frequencies.
Space complexity: O(1) because both frequency arrays contain only 26 elements.
Code */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26, 0);

        for (char x : p) {
            freq1[x - 'a']++;
        }

        int left = 0;
        vector<int> freq2(26, 0);
        vector<int> res;

        for (int right = 0; right < s.size(); right++) {
            freq2[s[right] - 'a']++;

            if (right - left + 1 > p.size()) {
                freq2[s[left] - 'a']--;
                left++;
            }

            bool valid = true;

            for (int i = 0; i < 26; i++) {
                if (freq1[i] != freq2[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                res.push_back(left);
            }
        }

        return res;
    }
};
