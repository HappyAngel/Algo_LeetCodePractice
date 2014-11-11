/*
	given vector of string, return the longest prefix of the strings, returned string is
	a copy version
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string longestCommonPrefixStr;
        
        if(strs.empty())
        {
            return longestCommonPrefixStr;
        }
        
        int index = 0;
        
        for(vector<string>::iterator iter=strs.begin(); iter!=strs.end(); ++iter)
        {
            if(index == 0)
            {
                for(int i=0; i < (*iter).size(); i++)
                {
                    longestCommonPrefixStr += (*iter)[i];
                }
            }
            else
            {
                int i=0;
                
                for(; i < (*iter).size(); i++)
                {
                    if(longestCommonPrefixStr.size() < i+1)
                    {
                        break;
                    }
                    else
                    {
                        if(longestCommonPrefixStr[i] != (*iter)[i])
                        {
                            longestCommonPrefixStr = longestCommonPrefixStr.erase(i, longestCommonPrefixStr.size());
                        }
                    }
                }
                
                if(i < longestCommonPrefixStr.size())
                {
                    longestCommonPrefixStr = longestCommonPrefixStr.erase(i, longestCommonPrefixStr.size());
                }
            }
            index++;
        }
        
        return longestCommonPrefixStr;
    }
};