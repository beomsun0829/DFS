#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int data[30][30];
int num = 0;
int n;
int ans[1000];
int idx;

int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

void back(int row, int col){
    for(int i=0;i<4;i++){
        int gorow=row+dir[i][0];
        int gocol=col+dir[i][1];
        if(gorow>=0&&gorow<n&&gocol>=0&&gocol<n&&data[gorow][gocol]==1){
            data[gorow][gocol]=0;
            ans[idx]++;
            back(gorow,gocol);

        }
    }
    return;
}


int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&data[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(data[i][j]==1){
                data[i][j]=0;
                back(i,j);
                num++;
                idx++;
            }
        }
    }
    sort(ans,ans+num);
    cout << num << endl;
    for(int i=0;i<num;i++){
        cout << ans[i] + 1 << endl;
    }
}

