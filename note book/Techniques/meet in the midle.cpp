int meet_in_the_middle(int n, int k, vector<int>& arr){ // complexity O(2^(n/2) * log(2^(n/2))) = O(2^(n/2) * n)
    int m = n/2;
    vector<int> left, right;
    for(int i=0; i<(1<<m); i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            if(i&(1<<j)) sum += arr[j];
        }
        left.push_back(sum);
    }
    for(int i=0; i<(1<<(n-m)); i++){
        int sum = 0;
        for(int j=0; j<n-m; j++){
            if(i&(1<<j)) sum += arr[m+j];
        }
        right.push_back(sum);
    }
    sort(right.begin(), right.end());
    int ans = 0;
    for(int x : left){
        int y = k-x;
        ans += upper_bound(right.begin(), right.end(), y) - lower_bound(right.begin(), right.end(), y);
    }
    return ans;
}