# DS-ALGO
Here I will be posting the famous DS and algorithms code as well as the notes

### Sort function and string join operation equivalent in python
https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
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

### Using Lambda function (in custom comparator) in C++
https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

## Code

``` js
// [] is used for capturing external variables
// () for passing the parameters
// -> is used for declaring the return type
// start with auto keyword
auto comp=[&mp](char &ch1,char &ch2)->bool{
            return mp[ch1]<mp[ch2];
        };
```

### Reversing a Linked List

## Code

``` js
ListNode* reverse(ListNode *head)
	{
		ListNode *prev = NULL;
		ListNode *curr = head;
		while (curr)
		{
			ListNode *temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;
	}
```

