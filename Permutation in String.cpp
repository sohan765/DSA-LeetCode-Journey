/* # Intuition

If `s2` contains a permutation of `s1`, then there must be a substring of `s2` whose length is equal to `s1` and whose **character frequencies are exactly the same as `s1`**.

For example:

```text
s1 = "ab"
s2 = "eidbaooo"
```

The substring `"ba"` is a permutation of `"ab"`.

So, instead of generating all permutations of `s1`, we use a **sliding window** of size `s1.size()` over `s2`.

We maintain two frequency arrays:

* `freq1` → frequency of characters in `s1`
* `freq2` → frequency of characters in the current window of `s2`

If both frequency arrays are equal, the current window is a permutation of `s1`.

# Approach

1. Store the frequency of each character of `s1` in `freq1`.
2. Initialize two pointers:

   * `left` → start of the current window
   * `i` → end of the current window
3. As `i` moves through `s2`, add `s2[i]` to `freq2`.
4. If the window size becomes greater than `s1.size()`, remove `s2[left]` from `freq2` and move `left` forward.
5. Compare `freq1` and `freq2`.
6. If all 26 character frequencies are equal, the current window is a permutation of `s1`, so return `true`.
7. If no valid window is found after traversing `s2`, return `false`.

The sliding window ensures that we only check substrings having the same length as `s1`.

# Complexity

* Time complexity: **O(26 × n) = O(n)**, where `n` is the length of `s2`.

  For every position, we compare at most 26 character frequencies.

* Space complexity: **O(1)** because we use two fixed-size frequency arrays of 26 characters.

# Code

```cpp
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();

        vector<char> ans;

        vector<int> freq1(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int left = 0;
        vector<int> freq2(26, 0);

        for (int i = 0; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;

            if (i - left + 1 > n) {
                freq2[s2[left] - 'a']--;
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
                return true;
            }
        }

        return false;
    }
};
```
