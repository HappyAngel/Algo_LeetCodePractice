/*
	problem:
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.

	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

	You are given a target value to search. If found in the array return its index, otherwise return -1.

	You may assume no duplicate exists in the array.

	ideas (assume the array is increasing):
		again, this is another binary search usage, the principle for binary search is to cut those range we don't need, thus in this problem,
		if we find some range: A[i] <= A[middle] && A[middle] > A[j], we can definitely cut the left part with updating l = middle+1, because the
		left part is increasing while right part is decreasing, which means pivot should be in the right part.
		if we can use binary search to get pivot, then the left problem is trival. and total time is O(logn).
		
		from this example, we know, to design binary search, we need to find the condition where we can cut any of the part to achieve binary time.
		to search for a target value is just a small usage of binary search, we need to understand the principle.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        
		int index = -1;
        
        if(n<0)
        {
            return -1;
        }
		else if (n==1)
		{
			return A[0]==target ? 0 : -1;
		}
        else
        {
			// find the pivot index
			int l=0;
			int h=n-1;
			
			while(l<h)
			{
				int middle = (l+h)/2;

				if(A[l]<=A[middle] && A[middle]>A[h])
				{
					l=middle+1;
				}
				else
				{
					h=middle;
				}
			}

			int pivotIndex = l;

			l=0;
			h=pivotIndex;

			// find the target in the first half
			while(l<=h)
			{
				int middle = (l+h)/2;

				if(A[middle] < target)
				{
					l = middle+1;
				}
				else if(A[middle] > target)
				{
					h = middle-1;
				}
				else
				{
					index = middle;
					return index;
				}
			}

			l=pivotIndex;
			h=n-1;

			// find the target in the second half
			while(l<=h)
			{
				int middle = (l+h)/2;

				if(A[middle] < target)
				{
					l = middle+1;
				}
				else if(A[middle] > target)
				{
					h = middle-1;
				}
				else
				{
					index = middle;
					return index;
				}
			}
        }
        
        return index;
    }
};