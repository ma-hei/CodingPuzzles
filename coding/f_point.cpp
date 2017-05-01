#include <iostream>

using namespace std;

int main(){

	int a = 1350;
	int b = 4;
	int d = b*3.45;
	float c = b*3.45;
	cout<<c<<"\n";
	c = (float) a/d;
	cout<<c<<"\n";
	int temp = a/(b*0.9);
	float temp_ = a/(b*0.9);
	cout<<temp<<" "<<temp_<<"\n";
}
