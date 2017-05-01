#include <iostream>

using namespace std;

void change_array(int* array){

	array[4] = 5;

}

int main(){
	
	int foo[5];
	change_array(foo);
	for (int i=0; i<5; ++i) cout<<foo[i]<<", ";
}
