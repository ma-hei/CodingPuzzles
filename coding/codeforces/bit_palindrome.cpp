#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	int blocksize = 1;
	int temp = 0;
	int count = 0;
	while(temp<n){
		cout<<"temp: "<<temp<<"\n";
		if (blocksize*10<=n){
			//count+= blocksize<=10 ? 9 : blocksize;
			temp=blocksize*10;
			blocksize*=10;
		} else if (temp+blocksize<=n){
			temp+=blocksize;
			count+=blocksize==1 ? 1 : blocksize/10;
		} else {
			cout<<"left: "<<(n-temp)<<"\n";
			//n = 6340 -> blocksize = 1000
			//n = 154101 -> blocksize = 100000
			int temp_ = n/blocksize;
			count+= (n-temp-temp_)/10;
			break;
		}
	}
	cout<<count<<"\n";
}
