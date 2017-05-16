#include <queue>
#include <iostream>
#include "math.h"

using namespace std;

float surface_1(const int* pancake){
	return (float) pancake[0]*pancake[0]*M_PI;
}

float surface_2(const int* pancake){
	return (float) 2*M_PI*pancake[0]*pancake[1];
}

bool sort_pancakes(int* a, int* b){
	return a[0]>b[0];
}

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int* lhs, const int* rhs) const
  {
	float temp1 = surface_2(lhs);
	float temp2 = surface_2(rhs); 
    if (reverse) return (temp1>temp2);
    else return (temp1<temp2);
  }
};

int main(){
	int t;
	cin>>t;
	priority_queue<int> heights;
	for (int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int** size = new int*[n];
		for (int j=0; j<n; j++){
			size[j] = new int[2];
			cin>>size[j][0]>>size[j][1];
		}
		sort(size, size+n, sort_pancakes);
		typedef std::priority_queue<int* ,std::vector<int*>,mycomparison> mypq_type;
		mypq_type heap(mycomparison(true));
		float old_ground = 0;
		float old_height = 0;
		for (int j=n-1;j>=n-k;j--){
			heap.push(size[j]);		
			old_height+= surface_2(size[j]);
			old_ground = surface_1(size[j]);
		}	
		float old_total = old_height+old_ground;		
		for (int j=n-k-1;j>=0;j--){
			float height_temp = surface_2(size[j]);
			float ground_temp = surface_1(size[j]);
			float smallest_height_current = surface_2(heap.top());
			float new_total = old_total - old_ground + ground_temp - smallest_height_current + height_temp;
			if(new_total>old_total){
				heap.pop();
				heap.push(size[j]);
				old_total = new_total;
				old_ground = ground_temp;		
			}
		}
		cout<<"Case #"<<i<<": "<<old_total<<"\n";
	}
}		
