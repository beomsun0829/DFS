#include<iostream>
using namespace std;

int data[2510][2510];
int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int t, m, n, k;

void DFS(int row, int col){
	for (int i = 0; i < 4; i++){
		int gorow = row + dir[i][0];
		int gocol = col + dir[i][1];
		if (data[gorow][gocol] == 1 && gorow >= 0 && gorow < n&&gocol >= 0 && gocol < m){
			data[gorow][gocol] = 0;
			DFS(gorow, gocol);
		}
	}

}

int main(){
	cin >> t;
	while (t--){
		int c = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			data[y][x] = 1;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (data[i][j] == 1){
					data[i][j] = 0;
					DFS(i, j);
					c++;
				}
			}
		}
		cout << c << endl;
	}
}