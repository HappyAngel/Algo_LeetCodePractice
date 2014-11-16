/*
	problem:
	Given a sorted array of integers, find the starting and ending position of a given target value.
	Your algorithm's runtime complexity must be in the order of O(log n).
	If the target is not found in the array, return [-1, -1].
	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].

	ideas: transformed binary search, when writing binary search, be ware of the infinite loop caused by lowIndex nor highIndex.
			when choose middleIndex to be lower bound, lowIndex must change, or highIndex must change.
			
*/
class Solution {
public:

	vector<int> searchRange(int A[], int n, int target) {

		vector<int> result;
		int result1, result2;

		// find index i that A[i] >= target
		int lowIndex = 0;
		int highIndex = n-1;

		while (lowIndex < highIndex)
		{
			int middleIndex = (lowIndex + highIndex) / 2;

			if(A[middleIndex] < target)
			{
				lowIndex = middleIndex+1;
			}
			else
			{
				highIndex = middleIndex;
			}
		}

		result1 = lowIndex;

		// find index j that A[j] <= target
		lowIndex = 0;
		highIndex = n-1;

		while (lowIndex < highIndex)
		{
			int middleIndex = (lowIndex + highIndex + 1) / 2;

			if(A[middleIndex] > target)
			{
				highIndex = middleIndex-1;
			}
			else
			{
				lowIndex = middleIndex;
			}
		}

		result2 = highIndex;

		if(result1 > result2 || A[result1] != target)
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		else
		{
			result.push_back(result1);
			result.push_back(result2);

		}

		return result;
	}
};
