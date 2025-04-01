#include<iostream>
using namespace std;

long long cache[121];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cache[1]=1;
	cache[2]=1;
	cache[3]=1;

	for(int i=4;i<=120;i++){
		cache[i]=cache[i-1]+cache[i-3];
	}

	cin>>n;

	cout<<cache[n]<<"\n";
}


