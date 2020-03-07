vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto compare = [](const vector<int> &intv1, const vector<int> &intv2){ 
            return intv1[1] < intv2[0]; 
        };
        auto itr1 = intervals.begin(),itr2 = intervals.begin();
        for(;itr1 != intervals.end();itr1++){//找到左边第一个能合并的区间
            if((*itr1)[1] >= newInterval[0]) break;
        }
        for(;itr2 != intervals.end();itr2++){//找到右边第一个不能合并的区间
            if((*itr2)[0] > newInterval[1]) break;
        }
        if (itr1 == itr2) {此时没有可合并的区间，直接插入
            intervals.insert(itr1, newInterval);
        }
        else {
            //合并并删除[itr1,itr2)区间
            itr2--;
            (*itr2)[0] = min(newInterval[0], (*itr1)[0]);
            (*itr2)[1] = max(newInterval[1], (*itr2)[1]);
            intervals.erase(itr1, itr2);
        }
        return intervals;     
    }
