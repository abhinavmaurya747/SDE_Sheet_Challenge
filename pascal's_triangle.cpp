// Approach 1 : Brute force generate permutations nCr

// Approach 2 : using the property that all the values are sum of 2 upper values
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> v;
    vector<long long int> l = {1};
    v.push_back(l);
    for(int i=1;i<n;i++){
        vector<long long int> t;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)    t.push_back(1);
            else    t.push_back(v[i-1][j-1] + v[i-1][j]);
        }
        v.push_back(t);
    }
    return v;
}
