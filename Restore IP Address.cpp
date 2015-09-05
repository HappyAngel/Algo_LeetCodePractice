/*
	LeetCode : Restore IP Addresses

	Solution: relative easy code problem, as the problem space is small (16 digit strin at most), 
	use brute force with certain branch cutting is enough.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;

		if (s.length() > 16)
		{
			return result;
		}

		for (int i = 0; i < 3; i++)
		{
			string possibleStr = "";

			if (i >= s.length())
			{
				continue;
			}

			string subA = s.substr(0, i + 1);
			
			if (i+1 > 1 && !isValidIPNum(subA))
			{
				continue;
			}


			for (int j = i + 1; j < i + 4; j++)
			{
				if (j >= s.length())
				{
					continue;
				}

				string subB = s.substr(i + 1, j - i);

				if (j-i>1 && !isValidIPNum(subB))
				{
					continue;
				}


				for (int k = j + 1; k < j + 4; k++)
				{
					if (k >= s.length())
					{
						continue;
					}

					string subC = s.substr(j+1, k-j);

					if (k - j>1 && !isValidIPNum(subC))
					{
						continue;
					}


					for (int l = k + 1; l < k + 4; l++)
					{
						if (l+1 != s.length())
						{
							continue;
						}

						string subD = s.substr(k + 1, l - k);

						if (l - k > 1 && !isValidIPNum(subD))
						{
							continue;
						}

						possibleStr = subA + "."  + subB + "." + subC + "." + subD;
						result.push_back(possibleStr);
					}
				}
			}
		}

		return result;
	}

private: 
	bool isValidIPNum(string str)
	{
		if (str.length() > 3)
		{
			return false;
		}
		else
		{
			int value = atoi(str.c_str());

			if (value > 255 || value < 0)
			{
				return false;
			}
			else
			{
				if (str.length() != 1 && str[0] == '0')
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
	}
};

int main()
{
	Solution so;

	vector<string> vec = so.restoreIpAddresses("010010");

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	char c;
	cin >> c;
}