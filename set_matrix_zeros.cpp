// Approach 1 using bruteforce. if the matrix[i][j] == 0 set all values of that row and column as 0
// Time complexity : O(m*n*(m+n))

// Approach 2 using additional space O(n+m) to mark the rows & columns to set as zeros
// Time complexity : O(m*n)
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rows, cols;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    for(int i=0;i<rows.size();i++){
        for(int j=0;j<n;j++){
            matrix[rows[i]][j] = 0;
        }
    }
    for(int i=0;i<cols.size();i++){
        for(int j=0;j<m;j++){
            matrix[j][cols[i]]=0;
        }
    }
}

// Approach 3 using the first row and first column as a dummmy array to mark the rows & columns to set as zeros
// Time complexity : O(m*n)
void setZeros(vector<vector<int>> &matrix)
{
	int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    for(int i=0;i<m;i++){
        if(matrix[i][0] == 0)     col0 = 0;
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=1;j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col0==0)    matrix[i][0] = 0;
    }
}