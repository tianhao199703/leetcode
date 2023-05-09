// 洗牌算法的应用
class Solution {
    int[] reset;
    int n;
    Random random = new Random();
    public Solution(int[] nums) {
        this.reset = nums;
        this.n = nums.length;
    }
    
    public int[] reset() {
        return this.reset;
    }
    
    // 每次决定第K位的值时，将K为和K-N位中随机的一位做交换
    public int[] shuffle() {
        int[] ans = reset.clone();
        for (int i = 0; i < n; i++) {
            swap(ans, i, i + random.nextInt(n - i));
        }
        return ans;
    }

    private void swap(int[] ans,int x,int y){
        int temp = ans[x];
        ans[x] = ans[y];
        ans[y] = temp;
    }
}
