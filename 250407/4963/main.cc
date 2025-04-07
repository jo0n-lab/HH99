#include<iostream>
#include<queue>
#include<utility>
using namespace std;

#define __DEBUG__

#define X first
#define Y second

int w,h;
int board[52][52];
int cache[52][52];
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true){

		cin>>w>>h;
		if(w==0 || h==0) break;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>board[i][j];
			}
		}

		fill_n(&cache[0][0],52*52,0);

		queue<pair<int,int>> q;
		int ans=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(board[i][j]==0) continue;
				if(cache[i][j]==1) continue;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> cur=q.front();
					q.pop();
					for(int dir=0;dir<8;dir++){
						int nx=cur.X+dx[dir];
						int ny=cur.Y+dy[dir];
						if(nx>=h||nx<0||ny>=w||ny<0) continue;
						if(board[nx][ny]==0) continue;
						if(cache[nx][ny]==1) continue;
						cache[nx][ny]=1;
						q.push({nx,ny});
					}
				}
				ans++;
			}
		}

		cout<<ans<<"\n";
	}
}
