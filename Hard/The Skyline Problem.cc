vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
	vector<vector<int>> res;
	multiset<pair<int, int>> all;
	for (auto &building : buildings){
		all.insert(make_pair(building[0], -building[2]));
		all.insert(make_pair(building[1], building[2]));//区分左右端点
	}
	multiset<int> heights = { 0 };// 保存当前位置所有高度。
	vector<int> last = { 0, 0 }; // 保存上一个位置的横坐标以及高度
	for (auto &p : all) {
		if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
		else heights.erase(heights.find(p.second)); // 右端点，移除高度
		// 当前关键点，最大高度
		auto maxHeight = *heights.rbegin();
		// 当前最大高度如果不同于上一个高度，说明这是一个转折点
		if (last[1] != maxHeight) {
			// 更新 last，并加入结果集
			last[0] = p.first;
			last[1] = maxHeight;
			res.push_back(last);
		}
	}
	return res;
}
