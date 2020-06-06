class Solution {
public:
    void oneCircle(vector<vector<int>>& matrix, vector<int>& res, int x1, int y1, int x2, int y2){
        if(y1 == y2){
            for(int i=x1;i<=x2;i++){
                res.push_back(matrix[i][y1]);
            }
            return;
        }
        if(x1 == x2){
            for(int i=y1;i<=y2;i++){
                res.push_back(matrix[x1][i]);
            }
            return;
        }
        for(int i=y1;i<=y2;i++){
            res.push_back(matrix[x1][i]);
        }
        for(int i=x1+1;i<=x2;i++){
            res.push_back(matrix[i][y2]);
        }
        for(int i=y2-1;i>=y1;i--){
            res.push_back(matrix[x2][i]);
        }
        for(int i=x2-1;i>x1;i--){
            res.push_back(matrix[i][y1]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int x1,y1=0;
        int x2=matrix.size()-1;
        if(x2 <0) return res;
        int y2 = matrix[0].size()-1;
        
        while((x1<=x2) && (y1<=y2)){
            oneCircle(matrix, res, x1, y1, x2, y2);
            x1++;
            y1++;
            x2--;
            y2--;
        }
        return res;

    }
};
