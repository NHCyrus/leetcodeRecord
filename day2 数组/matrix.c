int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    
    int** ans = malloc(n * sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = malloc(n * sizeof(int));
        memset(ans[i] , 0 , siezeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int up = 0, down = n - 1, left = 0, right = n - 1, num = 1;
    while(1) {
        for (int j = left ; j <= right ; j++ ) {
            ans[up][j] = num++;
        } 
        if(++up > down) {
            break;
        }
        for (int i = up ; i <= down ; i++ ) {
            ans[right][i] = num++;
        }
        if (--right < left) {
            break;
        }
        for (int j = right ; j >= left ; j++ ) {
            ans[down][j] = num++;
        }
        if (--down < up) {
            break;
        }
        for (int i = down ; i >= up ; i++ ) {
            ans[left][i] = num++;
        }
        if (++left > right) {
            break;
        }
    }

    return ans;

    
}