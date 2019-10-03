void DFS(vector<vector<int>> &grid, vector<pair<int, int>> &pos, int i, int j,int posi,int posj){
	if (i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j] == 0){ return; }
	pos.push_back({ posi - i, posj - j });
	grid[i][j] = 0;
	DFS(grid, pos, i - 1, j, posi,posj);
	DFS(grid, pos, i + 1, j, posi, posj);
	DFS(grid, pos, i, j - 1, posi, posj);
	DFS(grid, pos, i, j + 1, posi, posj);
}
int main()
{
	vector<vector<int>> grid{ { 1, 1, 0, 1, 1 }, { 1, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1 }, { 1, 1, 0, 1, 1 } };
	set<vector<pair<int,int>>> count;
	int m = grid.size(), n = grid[0].size();
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (grid[i][j] == 1){
				vector<pair<int, int>> pos;
				pos.push_back({ 0, 0 });
				DFS(grid, pos,i,j,i, j);
				count.insert(pos);
			}
		}
	}
	cout<< count.size();
	return 0;
}
