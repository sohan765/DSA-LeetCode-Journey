/*
# Intuition

Two rectangles overlap only when they have a **positive area in common**.

For two rectangles to overlap:

* Their horizontal ranges must overlap.
* Their vertical ranges must overlap.

If either of these conditions fails, the rectangles do not overlap.

For example, if the right edge of `rec1` is less than or equal to the left edge of `rec2`, then `rec1` is completely to the left of `rec2`.

Similarly, if the top edge of one rectangle is less than or equal to the bottom edge of the other, they do not overlap.

# Approach

Each rectangle is represented as:

```text
[x1, y1, x2, y2]
```

where:

* `(x1, y1)` → bottom-left corner
* `(x2, y2)` → top-right corner

We check four cases where the rectangles **do not overlap**:

1. `rec1` is completely to the left of `rec2`:

   ```cpp
   rec1[2] <= rec2[0]
   ```

2. `rec1` is completely to the right of `rec2`:

   ```cpp
   rec1[0] >= rec2[2]
   ```

3. `rec1` is completely below `rec2`:

   ```cpp
   rec1[3] <= rec2[1]
   ```

4. `rec1` is completely above `rec2`:

   ```cpp
   rec1[1] >= rec2[3]
   ```

If any of these conditions is true, the rectangles do not overlap, so we return `false`.

Otherwise, their horizontal and vertical ranges both overlap, meaning they have a positive overlapping area. Therefore, we return `true`.

# Complexity

* Time complexity: **O(1)**

  We perform only a constant number of comparisons.

* Space complexity: **O(1)**

  We use no additional space apart from a few variables.

# Code

```cpp id="v1g8q2"
  */
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] || rec1[0] >= rec2[2])
            return false;

        if (rec1[3] <= rec2[1] || rec1[1] >= rec2[3])
            return false;

        return true;
    }
};
```
