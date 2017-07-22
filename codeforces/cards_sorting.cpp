#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Segment_Node{
  Segment_Node* left_child;
  Segment_Node* right_child;
  long long value;
  pair<int,int> range;
  public:
    Segment_Node(int* arr, int l, int r){
      if (l==r){
        this->value = (long long) arr[l];
        this->left_child = NULL;
        this->right_child = NULL;
      } else {
        this->left_child = new Segment_Node(arr, l, (l+r)/2);
        this->right_child = new Segment_Node(arr, ((l+r)/2)+1, r);
        this->value = this->left_child->value + this->right_child->value;
      }
      this->range = pair<int,int>(l,r);
    }

    long long sum(int l,int r){
      if (this->range.first>=l && this->range.second<=r){
        return this->value;
      }
      else if ((this->range.first>=l && this->range.first<=r) || (this->range.second>=l && this->range.second<=r) || (range.first<l && range.second>r)){
        return this->left_child->sum(l,r) + this->right_child->sum(l,r);
      } else {
        return 0;
      }
    }
  
    void set_to_zero(int idx){
      if (range.first<=idx && range.second>=idx){
        value--;
        if (left_child!=NULL) left_child->set_to_zero(idx);
        if (right_child!=NULL) right_child->set_to_zero(idx);
      }
    }
  void print_range(){
    cout<<range.first<<" "<<range.second<<"\n";
  }
  void print_value(){
    cout<<value<<"\n";
  }
};

int find_last_index(vector<int> v, int current){
  if (current<=v[0]) return v[v.size()-1];
  else{
    int res = v[0];
    int idx = 0;
    while(idx<v.size() && current>v[idx++]) res = v[idx-1];
    return res;
  }
}

int main(){
  int n;
  cin>>n;
  int* arr = new int[n];
  int* intervals = new int[n];
  map<int,vector<int> > m;
  for (int i=0;i<n;i++){
    cin>>arr[i];
    intervals[i]=1;
    m[arr[i]].push_back(i);
  } 
  Segment_Node* root = new Segment_Node(intervals,0,n-1);
  int position = 0;
  long long int cnt=0;
  for (map<int,vector<int> >::iterator it = m.begin(); it!=m.end(); ++it){
    int temp = find_last_index(it->second, position);
    
    if (temp<position){
      cnt += root->sum(position,n-1) + root->sum(0,temp);
    } else {
      cnt += root->sum(position, temp);
    }
    for (int i : it->second){ 
      root->set_to_zero(i); 
      intervals[i]=0;
    }

    position = temp==n-1 ? 0 : temp+1;
  } 
 
  cout<<cnt<<"\n"; 
}
