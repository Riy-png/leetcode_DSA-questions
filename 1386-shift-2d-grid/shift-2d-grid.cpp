class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        for(int r =1 ; r<=k ; r++){
            vector<vector<int>> ans(row , vector<int>(col));
            for(int i =0 ; i<row; i++){
                for(int j =0 ; j<col; j++){
                    if(j< col-1) ans [i][j+1] = grid[i][j];
                    else if(i < row-1) ans[i+1][0]= grid[i][j];
                    else ans[0][0] = grid[i][j];
                }
            }
            grid = ans;
        }
        return grid;
    }
};
    