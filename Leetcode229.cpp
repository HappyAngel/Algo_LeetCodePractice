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
