class Solution {
public:

    void backward(vector<vector<int>> &res,vector<int> nums,vector<int> temp,int cur,int len,int time){
        if(len==time){
            res.push_back(temp);
            return;
        }
        for(int i =cur;i<nums.size();i++){
                temp.push_back(nums[i]);
                backward(res,nums,temp,i+1,len+1,time);
                temp.pop_back();
        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back({});
        for(int time = 1;time<=nums.size();time++){
            for(int cur = 0;cur<nums.size();cur++){
                temp.push_back(nums[cur]);
                backward(res,nums,temp,cur+1,1,time);
                temp.pop_back();
            }
        }        
        



        return res;
    }
};
