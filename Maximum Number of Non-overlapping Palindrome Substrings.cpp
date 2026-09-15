/* # Intuition

We need to find the maximum number of **non-overlapping palindromic substrings** whose length is at least `k`.

Instead of checking every possible substring, we use a **greedy approach**.

For every index `i`, we first check whether the substring of length `k` is a palindrome:

```text
s[i ... i+k-1]
```

If it is a palindrome, we select it because it ends as early as possible. This leaves more characters available for finding the next palindrome.

If the substring of length `k` is not a palindrome, we check the substring of length `k+1`:

```text
s[i ... i+k]
```

A longer palindrome is not necessary to check because if a palindrome of length greater than `k+1` exists, it contains a palindrome of length `k` or `k+1` that can be selected without reducing the maximum number of non-overlapping palindromes.

The `Palindrome()` function checks whether a substring is a palindrome using two pointers.

# Approach

1. Initialize `count = 0` to store the number of palindromes found.

2. Traverse the string using index `i`.

3. First check the substring of length `k`:

   ```cpp
   Palindrome(s, i, i + k - 1)
   ```

4. If it is a palindrome:

   * Increment `count`.
   * Move `i` forward by `k - 1`.
   * The `for` loop automatically increments `i` once more, so the next search starts after the selected palindrome.

5. If the length `k` substring is not a palindrome, check a substring of length `k + 1`:

   ```cpp
   Palindrome(s, i, i + k)
   ```

6. If this is a palindrome:

   * Increment `count`.
   * Move `i` forward by `k`.

7. Continue until fewer than `k` characters remain.

8. Return `count`.

For example:

```text
s = "abaccdbbd"
k = 3
```

We can select:

```text
"aba"  → length 3 palindrome
"dbbd" → length 4 palindrome
```

They are non-overlapping, so the answer is:

```text
2
```

# Complexity

* Time complexity: **O(n × k)**

  We visit each position of the string, and the `Palindrome()` function can take up to `O(k)` time.

* Space complexity: **O(1)**

  We only use a few variables and do not use any extra array or data structure.

# Code
*/
class Solution {
public:

    bool Palindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i <= n-k; i++) {

            // Check palindrome of length k
            if(Palindrome(s, i, i+k-1)) {
                count++;
                i += k-1;
            }

            // Check palindrome of length k+1
            else if(i+k < n && Palindrome(s, i, i+k)) {
                count++;
                i += k;
            }
        }

        return count;
    }
};

