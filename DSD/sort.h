#ifndef sort_h
#define sort_h

#include <iostream>
#include<cmath>
#include <algorithm>

using namespace std;

void hoanDoi(int &a , int &b){
	int t = a;
	a = b;
	b = t;
}

void sort1(int a[] , int &n){
	for(int i= 0 ; i < n - 1; i++){
		for(int j = i + 1 ;j < n ; j++){
			if(a[i] > a[j])
				hoanDoi(a[i],a[j]);
		}
	}
}
void sort2(int a[] , int &n){
		for(int i= 0 ; i < n - 1; i++){
		for(int j = i + 1 ;j < n ; j++){
			if(a[i] < a[j])
				hoanDoi(a[i],a[j]);
		}
	}
}
void sort3(int a[] , int &n){
	int l = 0 , r = n - 1;
	int fl = 0;
	while(l < r ){
		while(a[l] % 2 != 0){
			l++;
			fl++;
		}
		while(a[r] % 2 == 0 && l < r){
			r--;
		}

		if(l < r){
			hoanDoi(a[l],a[r]);
		}
	}

	//Cach nhanh hon - kho hieu hon :))
	// sort(a,a + fl); // le tang
	// sort(a + fl ,a + n,greater<int>());// chan giam


	// Cach nay de hieu ne
	//duyet tu 0 - fl . Cac phan tu trai le tang dan
	for(int i = 0 ; i < fl ; i++){
		for(int j = i + 1 ; j < fl ; j++){
			if(a[i] > a[j])
				hoanDoi(a[i],a[j]);
		}
	}

	//duyet tu fl - n . Cac phan tu chan phai giam dan
	for(int i = fl + 1 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(a[i] < a[j])
				hoanDoi(a[i],a[j]);
		}
	}

}
void sort4(int a[] , int &n){
	//Thay doi 1 ti o sort 3 nhen 
}
void sort5(int a[] , int &n){

	//DANG UPDATING

	//1 3 5 6 4 2 
	//1 2 3 5 6 4
	//1 2 3 4 5 6
	//1 2 3 4 5 6

}

#endif