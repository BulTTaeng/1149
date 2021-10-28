#include <iostream>

using namespace std;

int dp[1001][3];
int input[1001][3];

int find_min(int a, int b);

int main() {
  int N;
  cin >> N;
  long ans =0;

  for(int i =0; i<N; i++){
    for(int j =0; j<3; j++){
      cin >> input[i][j];
    }
  }

  for(int i =0; i< 3; i++){
    dp[0][i] = input[0][i];
  }

  for(int i =1; i< N; i++){
    
    dp[i][0] = find_min(dp[i-1][1] , dp[i-1][2]) + input[i][0]; // take R

    dp[i][1] = find_min(dp[i-1][0] , dp[i-1][2]) + input[i][1]; // take G

    dp[i][2] = find_min(dp[i-1][1] , dp[i-1][0]) + input[i][2]; // take B
    
  }

  ans = find_min(dp[N-1][0], dp[N-1][1]);
  ans = find_min(ans, dp[N-1][2]);

  cout << ans;

  return 0;
  

}

int find_min(int a, int b){
  if(a < b){
    return a;
  }
  else{
    return b;
  }
}