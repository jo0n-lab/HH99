#include<iostream>
using namespace std;

int t;

int GCD(int a,int b){
	if(b==0) return a;
	return GCD(b,a%b);
}

int LCD(int a,int b){
	int gcd=GCD(a,b);
	return (a*b)/gcd;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=0;i<t;i++){
		int m,n,x,y;
		cin>>m>>n>>x>>y;
		x%=m;
		y%=n;

		int lcd=LCD(m,n);

		int ans=-1;
		for(int j=0;j*m+x<=lcd;j++){
			int year=j*m+x;
			if(year%n==y) {
				ans=year;
				break;
			}
		}

		cout<<ans<<"\n";
	}
}
