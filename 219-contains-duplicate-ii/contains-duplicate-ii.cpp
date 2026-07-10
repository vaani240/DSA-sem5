class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n=nums.size();
        // unordered_map<int,int>mp;
        // for (int i=0;i<n; i++) {
        //     if (mp.count(nums[i])){
        //         if (i-mp[nums[i]]<=k) {
        //             return true;
        //         }
        //     }
        //     mp[nums[i]]=i;
        // }
        // return false;

        unordered_set<int>window;
        for (int i=0;i<n;i++) {
            if (i>k) {
                window.erase(nums[i-k-1]);
            }
            

            //count
            if (window.count(nums[i])) {
                return true;
            }

            // insert in the set 
            window.insert(nums[i]);
        }
        return false;
    }
};