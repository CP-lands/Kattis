#include<bits/stdc++.h>
 
//https://open.kattis.com/problems/alicedigital
using namespace std;
 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d", &q);
	for(int j = 0; j < q; j++){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> v(n), sum(n + 1);
		sum.push_back(0);
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
			sum[i + 1] = sum[i] + v[i];
		}
		int res = 0;
		int tmp = 0;
		int count = 0;
		int index = 0;
		int start = 0;
		int end = 0;
		int i = 0;

		while(i < n){
			if(v[i] >= m){
				start = i;
				while(v[i] >= m && i < n){
					if(v[i] == m){
						count++;
						if(count == 2){
							tmp = sum[i] - sum[start];
							if(res < tmp) res = tmp;
						  	start = index + 1;
							count = 1;
						}
						index = i;
					}
					i++;
				}
				if(count == 1){
					if(i == n){
						tmp = sum[i] - sum[start];
						if(res < tmp) res = tmp;
					}
					if(v[i] >= m){
						tmp = sum[i + 1] - sum[start];
						if(res < tmp) res = tmp;
					}
					else{
						tmp = sum[i] - sum[start];
						if(res < tmp) res = tmp;
					}
				}
				count = 0;
			}
			i++;
		}
		printf("%d\n", res);
	}

	return 0;
}
