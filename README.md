# DS-ALGO
Here I will be posting the famous DS and algorithms code as well as the notes

### Sort function and string join operation equivalent in python

## Code

``` js
from functools import cmp_to_key

class Solution:
    def comp(self, a, b):
        if a + b > b + a:
            return -1
        return 1

    def printLargest(self, n, arr):
        arr = sorted(arr, key=cmp_to_key(self.comp))
        largest_number = "".join(arr)
        return largest_number
```
