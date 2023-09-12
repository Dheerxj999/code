// ninja training 
//recursion + memoization
#include<vector>
int solve(vector<vector<int>> &points , int day , int last ,  vector<vector<int> >&dp){
    if(day == 0 ){
        int maxi = 0;
        for(int i = 0 ; i<3 ; i++){
            if(i != last){
                maxi = max(maxi , points[day][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    if(dp[day][last] != -1 ) return dp[day][last];
    int maxi = 0 , point =0;
    for( int i = 0 ; i<3 ; i++){
        if(i != last){
            point = (points[day][i] + solve(points ,day-1 ,i,dp));
            maxi = max(maxi , point);
        }
    }

    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int day = n-1;
    vector<vector<int> > dp(n , vector<int> (4 , -1));
    return solve(points , day , 3, dp) ;

}


// tabulation

