/* # Intuition

Two strings are anagrams if they contain the **same characters with the same frequency**, only in a different order.

For example:

```text
"eat" → "aet"
"tea" → "aet"
"ate" → "aet"
```

After sorting each string, all anagrams produce the **same sorted string**. We can use this sorted string as a key in an `unordered_map`.

# Approach

1. Create an `unordered_map<string, vector<string>>`.
2. Traverse every string in `strs`.
3. Make a copy of the current string.
4. Sort the copy.
5. Use the sorted string as the key in the map.
6. Add the original string to that key's vector.
7. Finally, traverse the map and add every group to `ans`.

For example:

```text
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

"eat" → "aet"
"tea" → "aet"
"tan" → "ant"
"ate" → "aet"
"nat" → "ant"
"bat" → "abt"
```

So the map becomes conceptually:

```text
"aet" → ["eat", "tea", "ate"]
"ant" → ["tan", "nat"]
"abt" → ["bat"]
```

# Complexity

Let:

* `n` = number of strings
* `k` = maximum length of a string

For every string, we sort its characters, which takes `O(k log k)`.

**Time complexity:**

\(O(n*k*logk)

**Space complexity:**
(O(n * k)

This includes the storage required for the map and the answer.

# Code
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string p = s;

            // Sort to create a common key for anagrams
            sort(p.begin(), p.end());

            mp[p].push_back(s);
        }

        // Store all groups in the answer
        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
```
