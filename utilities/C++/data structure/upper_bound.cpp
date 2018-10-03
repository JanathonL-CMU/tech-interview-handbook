#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
void print(list<int> l){
	for(int it: l){
		cout<<it<<" ";
	}
	cout<<endl;
}
list<int>::iterator binary_search(list<int> l, int target){
	auto left = l.begin();
	auto right = advance (it2,-1);
	while(left!=right){
		auto mid = left+right
	}   
}
int main(){
	list<int> l;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i);
	}

	l.sort(cmp);
	print(l);
	auto it = l.begin();
	it++;
	cout<<*it<<endl;
	l.splice(l.begin(),l,it);
	cout<<*it<<endl;
	print(l);
}