#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define ARRAYSIZE 10000
using namespace std;
void swap(vector<int>& array, int idx_1, int idx_2) {
	int tmp = array[idx_1];
	array[idx_1] = array[idx_2];
	array[idx_2] = tmp;
}

void quicksortImpl(vector<int>& array, int left, int right) {
	int pivot = left;
	int left_ = left;
	int right_ = right;
	while(left_ < right_) {
		while(array[right_] > array[pivot] && right_ > left_) right_--;
		while(array[left_]  < array[pivot] && left_ < right_) left_++;
		swap(array, left_, right_);
	}
	if(pivot != left_) {
		swap(array, pivot, left_);
	}
	pivot = left_;
        if(pivot-1 > left) quicksortImpl(array, left, pivot-1);
	if(pivot+1 < right) quicksortImpl(array, pivot+1, right);
	return;
}

void quicksort(vector<int>& array) {
	int pivot;
	quicksortImpl(array, 0, array.size()-1);
}

void randomarraygen(vector<int>& array) {
	for(int i = 0; i < ARRAYSIZE; i++)
		array.push_back(rand());
}

void printarray(vector<int>& array) {
	for(int i : array) {
		cout<<i<<" ";
	}
	cout<<"\n";
}

bool verify(vector<int>& array) {
	for(int i = 0; i < array.size() - 2; i++) {
		if(array[i] > array[i+1]) return false;
	}
	return true;
}

int main() {
	srand((unsigned int)time(NULL));
	vector<int> v;
	randomarraygen(v);
	quicksort(v);
	if(verify) cout<<"SUCCESS"<<endl;
	else cout<<"FAIL"<<endl;
	return 0;
}
