#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int blocksize = 1;
	int temp = 0;
	int count = 0;
	while(temp<n){
		if (blocksize*10<=n){
			count+= 9 * (blocksize==1 ? 1 : blocksize/10);
			temp=blocksize*10;
			blocksize*=10;
		} else if (temp+blocksize<=n){
			temp+=blocksize;
			count+=blocksize==1 ? 1 : blocksize/10;
		} else {
			count+= (n-temp-(n/blocksize))>0 ? (n-temp-(n/blocksize))/10+1: 0;
			break;
		}
	}
	cout<<count<<"\n";
}
