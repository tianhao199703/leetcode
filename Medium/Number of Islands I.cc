int numIslandsI(vector<vector<char>>& grid) {
        //必要的条件判断，防止特殊样例。
        if(!grid.size()) return 0;
        if(!grid[0].size()) return 0;
        int m=grid.size(),n=grid[0].size();
        int count=0;
        //DFS消除相连的1。
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    DFS(grid,i,j);
                } 
            }
        }
        return count;
    }
    void DFS(vector<vector<char>>& grid,int i,int j){
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1') DFS(grid, i-1, j);
        if(i < grid.size()-1 && grid[i+1][j] == '1') DFS(grid, i+1, j);
        if(j > 0 && grid[i][j-1] == '1') DFS(grid, i, j-1);
        if(j < grid[0].size()-1 && grid[i][j+1] == '1') DFS(grid, i, j+1);
    }
