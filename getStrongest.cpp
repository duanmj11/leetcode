class Solution {
public:

    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end()); 
        int lamda = ((arr.size() - 1) / 2);
        int m = arr[lamda];
        vector<pair<int, int>>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back({abs(arr[i]-m), arr[i]});
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(int i=ans.size()-1;i>=0;i--){
            if(res.size()<k){
                res.push_back(ans[i].second);
            }
            else{
                break;
            }
        }
        return res;
        

    }
};
