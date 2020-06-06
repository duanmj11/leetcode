class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for (const int& num : nums) {
            uset.insert(num);
        }
        int i=0;
        int curlcc, maxlcc= 0;
        while(i<nums.size()){
            if(uset.count(nums[i]) == 0){
                i++;
                continue;
            }
            int posnum = nums[i];
            int posnuml = posnum;
            int posnumr = posnum;
            while(1){
                if(uset.count(posnuml-1)!=0){
                    uset.erase(posnuml-1);
                    posnuml--;
                }
                else{
                    break;
                }
            }
            while(1){
                if(uset.count(posnumr+1)!=0){
                    uset.erase(posnumr+1);
                    posnumr++;
                }
                else{
                    break;
                }
            }
            curlcc=posnumr-posnuml+1;
            maxlcc = max(maxlcc, curlcc);
            uset.erase(posnum);
            curlcc=0;
            i++;
        }
        return maxlcc;
    }
};
