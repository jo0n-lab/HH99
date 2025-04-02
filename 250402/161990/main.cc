#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int x1=50;
    int x2=0;
    int y1=50;
    int y2=0;
    for(int i=0;i<wallpaper.size();i++){
        string s=wallpaper[i];
        for(int j=0;j<s.length();j++){
            if(s[j]=='.') continue;
            x1=min(x1,i);
            x2=max(x2,i+1);
            y1=min(y1,j);
            y2=max(y2,j+1);
        }
    }
    
    vector<int> answer;
    answer={x1,y1,x2,y2};
    return answer;
}
