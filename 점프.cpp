#include<iostream>
using namespace std;

long long int data[110][110];
int dir[2][2] = { { 1, 0 }, { 0, 1 } };
int n;
long long int mem[110][110];

long long int dfs(int row, int col){
	if (mem[row][col] != 0){
		return mem[row][col];
	}
	if (data[row][col] == 0){
		if (row == n - 1 && col == n - 1){
			return 1;
		}
		else
			return 0;
	}
	for (int i = 0; i < 2; i++){
		int gorow = row + dir[i][0] * data[row][col];
		int gocol = col + dir[i][1] * data[row][col];


		if (gorow >= 0 && gocol >= 0 && gorow < n && gocol < n){
			mem[row][col] += dfs(gorow, gocol);

		}
	}
	return mem[row][col];
}



int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%lld", &data[i][j]);
			
		}
	}
	
	cout << dfs(0,0) << endl;

}