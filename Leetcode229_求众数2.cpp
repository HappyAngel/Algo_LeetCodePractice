#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 229. 求众数 II
/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // user moore majority vote algorithm
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vec;
        int num = nums.size();
        if (num == 0) {
            return vec;
        } else if (num == 1) {
            return nums;
        } else if (num == 2) {
            vec.push_back(nums[0]);
            if (nums[0] != nums[1]) {
                vec.push_back(nums[1]);
            }
            return vec;
        }

        int res=0, res2=0;
        // pair阶段
        tryFindMajority(nums, res, res2);

        // validate阶段
        if (validate(nums, res)) {
            vec.push_back(res);
        }

        if (res!=res2 && validate(nums, res2)) {
            vec.push_back(res2);
        }

        return vec;
    }

private:
    bool validate(vector<int>& ori, int k) {
        int c = 0;

        for (int i=0; i < ori.size(); i=i+1) {
            if (ori[i] == k) {
                c++;
            }
        }
        return c > ori.size()/3;
    }

    void tryFindMajority(vector<int>& nums, int& res1, int& res2) {
        int c1 = 0;
        int c2 = 0;
        res1 = nums[0];
        res2 = res1;
        int size = nums.size();
        int i = 0;


        while(i<size) {
            int cur = nums[i];
            if (res1 == cur) {
                c1++;
            } else if (res2 == cur) {
                c2++;
            } else if (c1 == 0) {
                res1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                res2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
                           
            i++;
        }
    }
};
