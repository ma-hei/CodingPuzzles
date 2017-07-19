#include <iostream>

using namespace std;

int main(){
  string a;
  string b;
  getline(cin, a, ':');
  getline(cin,b);
  int count=0;
  while(!(a[0]==b[1] && a[1]==b[0])){
	int i = stoi(a);
	int k = stoi(b);
	k++;
	if (k==60){
	  k=0;
	  i = i==23 ? 0 : i+1;
	}
	a = i<10 ? "0" : "";
	b = k<10 ? "0" : "";
	a.append(to_string(i));
	b.append(to_string(k));	
	count++;
  }
  
  cout<<count<<"\n";
}
