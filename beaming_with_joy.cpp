#include <iostream>
#include <unordered_set>

using namespace std;

struct Path{
	unordered_set<pair< pair<int,int>, bool> > > pairs;
};

int main(){
	int r,c,n;
	cin>>n>>r>>c;
	char** house = new char*[r];
	for (int i=0;i<r;i++){
		house[i] = new char[c];
		cout<<house[i];
	}

}
