int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int maxarea=0,n=heights.size();
        for (int i=0;i<n;i++) {
            while (stack.top() != -1 && heights[stack.top()] >= heights[i]){
                int curtop = stack.top();
                stack.pop();
                maxarea = max(maxarea, heights[curtop] * (i-stack.top()-1));
            }
            stack.push(i);
        }
        
        while (stack.top() != -1){
            int curtop = stack.top();
            stack.pop();
            maxarea = max(maxarea, heights[curtop] * (n-stack.top()-1));
        }    
        return maxarea;
    }
