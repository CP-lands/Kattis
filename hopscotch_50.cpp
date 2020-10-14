#include<bits/stdc++.h>

using namespace std;

//https://open.kattis.com/contests/nac20open/problems/hopscotch50
void Solve(){
	int n, k;
	cin>>n>>k;
	vector<int> dp[k + 1];
	vector<pair<int, int>> pos[k + 1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin>>x;
			pos[x] .push_back({i, j});
			if(x == 1) dp[x].push_back(0);
			else dp[x].push_back(INT_MAX);
		}
	}
	for(int i = 1; i <= k; i++){
		if(!pos[i].size()){
			cout<<-1<<'\n';
			return;
		}
	}
	if(k == 1){
		cout<<0<<'\n';
		return;
	}
	for(int i = 2; i <= k; i++){
		for(int j = 0; j < dp[i].size(); j++){
			for(int a = 0; a < dp[i - 1].size(); a++){
				dp[i][j] = min(dp[i][j], dp[i - 1][a] + abs(pos[i - 1][a].first - pos[i][j].first) + abs(pos[i - 1][a].second - pos[i][j].second));
			}
		}
	}
	int res = INT_MAX;
	for(auto x: dp[k]) res = min(res, x);
	cout<<res<<'\n';

}
// not this backtracking (-_-), it gonna give Time Limit Exceeded
/*
vector<pair<int, int>> path[2501];
int res = INT_MAX, sum = 0;
int n, k;

void backtrack(int st, int x, int y){
	if(st > k) return;
	for(auto i: path[st]){
		int distance = abs(x - i.first) + abs(y - i.second);
		if(st == 1) distance = 0;
		sum += distance;
		if(st == k) res = min(res, sum);
		backtrack(st + 1, i.first, i.second);
		sum -= distance;
	}
}
void Solve(){
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin>>x;
			path[x].push_back({i, j});
		}
	}
	for(int i = 1; i <= k; i++){
		if(path[i].size() == 0){
			cout<<-1<<'\n';
			return;
		}
	}
	backtrack(1, 0, 0);
	cout<<res<<'\n';

}
*/
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}