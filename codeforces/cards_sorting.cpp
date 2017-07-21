#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Segment_Node{
  Segment_Node* left_child;
  Segment_Node* right_child;
  int value;
  pair<int,int> range;
  public:
    Segment_Node(int* arr, int l, int r){
      if (l==r){
        this->value = arr[l];
        this->left_child = NULL;
        this->right_child = NULL;
      } else {
        this->left_child = new Segment_Node(arr, l, (l+r)/2);
        this->right_child = new Segment_Node(arr, ((l+r)/2)+1, r);
        this->value = this->left_child->value + this->right_child->value;
      }
      this->range = pair<int,int>(l,r);
    }

    int sum(int l,int r){
      if (this->range.first>=l && this->range.second<=r){
        return this->value;
      }
      else if ((this->range.first>=l && this->range.first<=r) || (this->range.second>=l && this->range.second<=r)){
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
};



int main(){
  int n;
  int* arr = new int[n];
  int* intervals = new int[n];
  map<int,vector<int> > m;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>arr[i];
    intervals[i]=1;
    m[arr[i]].push_back(i);
  } 
  Segment_Node* root = new Segment_Node(intervals,0,n-1);
  for (map<int,vector<int> >::iterator it = m.begin(); it!=m.end(); ++it){
       
  } 
}
