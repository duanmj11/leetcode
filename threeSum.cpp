class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() <=2) return {};
        unordered_map<int, int> thirdList;
        for(int i=0;i<nums.size();i++){
            int key = nums[i];
            if(thirdList.find(key) == thirdList.end()){
                thirdList.insert(make_pair(key, 1));
            }
            else{
                int value = thirdList[key];
                value++;
                thirdList[key] = value;
            }
        }
        vector<vector<int>> ans;
        for(int first = 0;first<nums.size()-2;first++){
            if(nums[first] > 0){
                break;
            }
            else if(nums[first] == 0){
                if(thirdList[0] >= 3){
                    ans.push_back({0,0,0});
                    break;
                }
            }
            else{//a<0
                int second=first+1;
                while(second<nums.size()-1){
                    int c=0-(nums[first]+nums[second]);
                    if(c < nums[second]) break;//c<b, break
                    if(nums[first] == nums[second]){//a=b, b<c
                        if(thirdList.find(c)!=thirdList.end()){
                            vector<int> tmp;
                            tmp.push_back(nums[first]);
                            tmp.push_back(nums[second]);
                            tmp.push_back(c);
                            ans.push_back(tmp);
                            //find next b which b>a
                            while(second<nums.size()-1 &&nums[second] == nums[first]){
                                second++;
                            }
                        }
                        else{
                            second++;
                        }
                    }
                    else{//a<b, b<=c
                        if(thirdList.find(c)!=thirdList.end()){
                            if(c == nums[second]){//c=b
                                if(thirdList[c] >= 2){
                                    vector<int> tmp;
                                    tmp.push_back(nums[first]);
                                    tmp.push_back(nums[second]);
                                    tmp.push_back(c);
                                    ans.push_back(tmp);
                                    //find next b which new b!=old b
                                    int b= nums[second];
                                    while(second<nums.size()-1 &&nums[second] == b){
                                        second++;
                                    }
                                }
                                else{
                                    second++;
                                }
                            }
                            else{//c>b
                                vector<int> tmp;
                                tmp.push_back(nums[first]);
                                tmp.push_back(nums[second]);
                                tmp.push_back(c);
                                ans.push_back(tmp);
                                //find next b which new b!=old b
                                int b= nums[second];
                                while(second<nums.size()-1 && nums[second] == b){
                                    second++;
                                }
                            }
                        }
                        else{
                            second++;
                        }
                    }
                }
            }
            //find next a which new a!=old a
            int a = nums[first];
            while(first<nums.size()-2 && nums[first] == a){
                first++;
            }
            first--;
        }
        return ans;

    }
};
