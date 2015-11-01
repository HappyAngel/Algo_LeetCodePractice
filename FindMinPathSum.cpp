/*
	Problem: 
	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
	Note: You can only move either down or right at any point in time.

	Solution:
	Dynamic programming, for this specific problem, when we think of [m][n] directly, we may get the equation like below:
	fmin(m,n) = min{fmin(m-1,n), fmin(m,n-1)}, this is very difficult to compute as there are lots of duplicate
	states needed to compute repeated. we can use an array to store the value for each state, and then, just go from the very
	begining fmin[0][0] which is naive, just itself!

	when solve complex problem, we can think from the easist and use mathmatical conclusion to get the final answer.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
		{
			return 0;
		}

		int** pArray = new int*[grid.size()];
		
		for (int i = 0; i < grid.size(); i++)
		{
			pArray[i] = new int[grid[i].size()];
		}

		// 
		int result = 0;

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (j>0 && i>0)
				{
					pArray[i][j] = pArray[i][j - 1] < pArray[i - 1][j] ? pArray[i][j - 1] + grid[i][j] : pArray[i - 1][j] + grid[i][j];
				}
				else if (i>0)
				{
					pArray[i][j] = pArray[i - 1][j] + grid[i][j];
				}
				else if (j > 0)
				{
					pArray[i][j] = pArray[i][j - 1] + grid[i][j];
				}
				else
				{
					// i=0, j=0, just initialize
					pArray[i][j] = grid[i][j];
				}

				result = pArray[i][j];
			}
		}

		return result;
	}
};

int main()
{
	vector<vector<int>> grid;
	
	vector<int> row1;
	row1.push_back(1);
	row1.push_back(1);
	row1.push_back(4);

	vector<int> row2;
	row2.push_back(3);
	row2.push_back(4);
	row2.push_back(1);

	vector<int> row3;
	row3.push_back(1);
	row3.push_back(1);
	row3.push_back(1);

	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);

	Solution s;

	int c = s.minPathSum(grid);

	cout << c << endl;

	return 0;
}