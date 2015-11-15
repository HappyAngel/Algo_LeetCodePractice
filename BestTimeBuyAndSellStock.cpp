/*
	Problem: [Best Time to Buy and Sell Stock]
	Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

	Solution:
	this problem could be transformed to given an array A[n], how to find a range i..j, with which we can get a max value sigma(A[i]..A[j]), noting that A[i] could be
	less than 0.

	A trick here is to assume we know the index x which result in the max sum A[x..j] with A[j] as the last element, then how we get the max sum of A[i..j+1]?
	simple, if (A[x..j] + A[j+1] > A[j+1]), then it's A[x..j+1] or it's A[j+1] where we can safely discard A[x..j].
	So, we can calculate from A[0] to A[n], and get a max value which is also the solution.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
		{
			return 0;
		}

		vector<int> diff(prices.size());
		
		for (int i = 1; i < prices.size(); i++)
		{
			diff.push_back(prices[i] - prices[i - 1]);
		}

		int* pLeastwithCurrentElemAsLast = new int[diff.size()];
		int result = -1;

		for (int i = 0; i < diff.size(); i++)
		{
			pLeastwithCurrentElemAsLast[i] = diff[i];

			if (i > 0 && pLeastwithCurrentElemAsLast[i - 1] > 0)
			{
				pLeastwithCurrentElemAsLast[i] = diff[i] + pLeastwithCurrentElemAsLast[i - 1];
			}

			if (result < pLeastwithCurrentElemAsLast[i])
			{
				result = pLeastwithCurrentElemAsLast[i];
			}
		}

		delete[] pLeastwithCurrentElemAsLast;

		return result;
	}
};

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(3);
	prices.push_back(1);
	prices.push_back(9);
	prices.push_back(4);
	prices.push_back(2);
	prices.push_back(11);
	prices.push_back(2);


	Solution s;

	int c = s.maxProfit(prices);

	cout << c << endl;

	char h;
	cin >> h;

	return 0;
}