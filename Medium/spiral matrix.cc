//col，row是移动中的标志，而u，r，d，l，则是四个边界
while (true) {
            for (int col = l; col <= r; col++) matrix[u][col] = n_sqr++;//向右遍历
            if (++u > d) break;//判断是不是到达边界，同时向下移动一行
            for (int row = u; row <= d; row++) matrix[row][r] = n_sqr++;
            if (--r < l) break;//判断是不是到达边界，同时向左移动一列
            for (int col = r; col >= l; col--) matrix[d][col] = n_sqr++;
            if (--d < u) break;//判断是不是到达边界，同时向上移动一行
            for (int row = d; row >= u; row--) matrix[row][l] = n_sqr++;
            if (++l > r) break;//判断是不是到达边界，同时向右移动一列
        }
