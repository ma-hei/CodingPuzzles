#include <iostream>

using namespace std;

int main(){
  int** r = new int* [4];
  for (int i=0;i<4;i++){
	r[i] = new int[4];
	for (int k=0;k<4;k++) cin>>r[i][k];
  }
   
}
