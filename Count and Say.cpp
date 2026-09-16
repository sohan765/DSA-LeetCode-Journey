/* # Intuition

The idea is to read the current string and **count consecutive repeated digits**.

For example:

```text
"1223315"
```

We read it as:

```text
one 1
two 2s
two 3s
one 1
one 5
```

So the next string becomes:

```text
"11223115"
```

We repeat this process until we reach the `n`th term.

# Approach

1. Start with `s = "1"`.
2. Traverse the string and count consecutive equal characters.
3. Store each character and its count in a `pair<char, int>`.
4. Build the next string by adding:

   * count first
   * character second
5. Recursively generate the next term until `value == n`.
6. Return the final string.

For example:

```text
1
↓
11
↓
21
↓
1211
↓
111221
```

Therefore, for `n = 5`, the answer is:

```text
"111221"
```

# Complexity

Let `k` be the length of the current string.

**Time complexity:** `O(n × k)`

**Space complexity:** `O(k)`

The exact size of the string changes at every iteration, so this is a simplified representation of the complexity.

# Code
*/
class Solution {
public:
    string solve(string& s, int value, int n) {
        if (value == n) {
            return s;
        }

        vector<pair<char, int>> rle;
        int count = 1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                count++;
            }
            else {
                rle.push_back({c, count});
                count = 1;
            }
        }

        s = "";

        for (auto& it : rle) {
            s.push_back(it.second + '0');
            s.push_back(it.first);
        }

        return solve(s, value + 1, n);
    }

    string countAndSay(int n) {
        string s = "1";
        string p = solve(s, 1, n);
        return p;
    }
};
