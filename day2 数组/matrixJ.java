  public int[][] generateMatrix(int n) {
        int ans[][] = new int[n][n];
        int up = 0 , down = n -1 , left = 0 , right = n -1 , num = 1;
        while (true) {
            for (int j = left ; j <= right ; j++ ) {
                ans[up][j] = num++;
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; i++) {
                ans[i][right] = num++;
            }
            if (--right < left) {
                break;
            }
            for (int j = right ; j >= left ; j--) {
                ans[down][j] = num++;
            }
            if (--down < up) {
                break;
            }
            for (int i = down ; i >= up ; i-- ) {
                ans[i][left] = num++;
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }