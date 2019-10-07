class UnionFind {
public:
	UnionFind(int N){
		count = N;
		for (int i = 0; i<N; i++){
			id.push_back(i);
			weight.push_back(1);
		}
	}
    int find(int p){
		int root = p;
		while (root != id[root])root = id[root];
		while (p != root){
			int x = p;
			id[x] = root;
			p = id[p];
		}
		return root;
	}

	bool Union(int p, int q){
		int pid = find(p);
		int qid = find(q);
		if (qid == pid) return false;
		if (weight[pid]<weight[qid]){
			id[pid] = qid;
			weight[qid] += weight[pid];
		}
		else{
			id[qid] = pid;
			weight[pid] += weight[qid];
		}
		count--;
		return true;
	}

private:
	vector<int> id, weight;
	int count;
};
bool search(vector<vector<int>> &grid,UnionFind &store, int i,int j,int posi,int posj){
	if (i<0 || i == grid.size() || j<0 || j == grid[0].size() || grid[i][j] == 0){ return false; }
	int m = grid[0].size();
	return store.Union(i*m + j, posi*m + posj);
}

int main()
{
	int m = 3, n = 3;
	vector<vector<int>> grid(m,vector<int>(n,0));
	vector<pair<int, int>> pos{ { 0, 0 }, { 0, 2 }, { 0, 1 }, { 1, 1 }, {2,2} };
	vector<int> out;
	int num = 0;
	UnionFind store(m*n);
	for (int i = 0; i < pos.size(); i++){
		grid[pos[i].first][pos[i].second] = 1;
		num++;
		if (search(grid, store, pos[i].first - 1, pos[i].second, pos[i].first, pos[i].second)) num--;
		if (search(grid, store, pos[i].first, pos[i].second-1, pos[i].first, pos[i].second)) num--;
		if (search(grid, store, pos[i].first + 1, pos[i].second, pos[i].first, pos[i].second)) num--;
		if (search(grid, store, pos[i].first, pos[i].second+1, pos[i].first, pos[i].second)) num--;
		out.push_back(num);
	}
	return 0;
}
