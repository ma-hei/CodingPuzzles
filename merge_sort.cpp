#include <iostream>

using namespace std;

int* merge_lists(int* left_list, int* right_list, int length_left, int length_right){

	int* res = new int[length_left+length_right];
	int ind_left = 0;
	int ind_right = 0;
	int ind_res = 0;
	while (ind_left<length_left && ind_right<length_right){
		if (left_list[ind_left]<=right_list[ind_right]){
			res[ind_res++] = left_list[ind_left++];
		}else{
			res[ind_res++] = right_list[ind_right++];
		}
	}
	while (ind_left<length_left) res[ind_res++] = left_list[ind_left++];
	while (ind_right<length_right) res[ind_res++] = right_list[ind_right++];
	return res;
}

void merge_sort(int* list, int list_length){
	if (list_length<=1) return;

	int length_left = list_length/2; 
	int length_right = list_length - length_left;

	merge_sort(list, length_left);
	merge_sort(list + length_left, length_right);

	int* merged = merge_lists(list, list+length_left, length_left, length_right);

	for (int i=0;i<list_length;i++) list[i] = merged[i];
}

int main(){
	int a[] = {12,23,1,39,100,2,5,410};
	merge_sort(a,8);
	for (int i=0;i<8;i++) cout<<a[i]<<", ";
}
