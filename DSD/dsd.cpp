/*
	==================================
	Quoc Khanh - 4/4/2023
	HCM City - Go Vap District
	Nice to see you when see my code
	==================================
*/
#include<iostream>
#include<iomanip>
#include "sort.h"
#define MAX 100 //SO PHAN TU TOI DA MANG LUU TRU

using namespace std;

// bien luu tru toan cuc
int a[MAX]; // khoi tao mang toi da MAX phan tu
int n; // so luong phan tu 
int choose; // chon thao tac menu
char tt; // xu ly 
int k;//xoay mang
bool checkInp = false; // kiem tra khoi tao
int vitri;
int val;

//function main
void menuThaoTac();
void nhapMang(int a[] , int &n);
bool isEmpty(int &n);//Co the them vo cac function de clean code tot nhat
void xuatMang(int a[] , int n);
int timPhanTu(int a[] , int n , int val);
int xoaPhanTu(int a[] , int &n , int val);// gia du moi phan tu deu rieng biet(xoa phan tu xuat hien dau tien)
void themPhanTu(int a[] , int &n , int vitri);
void sapXepMang(int a[] , int &n);
void xoayMang(int a[] , int n , int &k);
//Updating...

int main(){
	menuThaoTac();
}
void menuThaoTac(){
	do{
	system("cls");
	cout<<"MENU DANH SACH DAC"<<endl;
	cout<<"1.Khoi tao danh sach"<<endl;
	cout<<"2.Xuat danh sach"<<endl;
	cout<<"3.Tim phan tu"<<endl;
	cout<<"4.Xoa phan tu"<<endl;
	cout<<"5.Them phan tu vao vi tri bat ki"<<endl;
	cout<<"6.Sap xep mang"<<endl;
	cout<<"7.Xoay mang tu trai -> phai K lan"<<endl;
	cout<<"Updating..."<<endl;
	cout<<"Chon thao tac:";
	cin>>choose;
	switch(choose){
	case 1:
		do{
			cout<<"Khoi tao thanh cong danh sach!!!"<<endl;
			cout<<"Moi ban nhap so luong N = ";
			cin>>n;
			if(n <= 0 || n + 1 >= MAX)
				cout<<"Nhap sai gia tri , nhap lai!!!"<<endl;
		}while(n <= 0 || n + 1 >= MAX);
		checkInp = true;
		nhapMang(a,n);
		break;
	case 2:
		if(checkInp)
			xuatMang(a,n);
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;
	case 3:
		if(checkInp){
			cout<<"Nhap gia tri can tim :";
			cin>>val;

			int kq = timPhanTu(a,n,val);
			if(kq!=-1)
				cout<<"Phan tu "<<val<<" tim duoc tai vi tri "<<kq<<endl;
			else
				cout<<"Khong ton tai trong danh sach"<<endl;
		}
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;
	
	case 4:
		if(checkInp){
			cout<<"Nhap gia tri can xoa :";
			cin>>val;
			int kq = xoaPhanTu(a,n,val);
			if(kq!=-1){
				cout<<"Xoa thanh cong!!!"<<endl;
			}else{
				cout<<"Khong ton tai "<<val<<" trong danh sach!!!"<<endl;
			}
		}
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;

	case 5:
		if(checkInp){
			cout<<"Nhap vi tri can them :";
			cin>>vitri;
			themPhanTu(a,n,vitri);
		}
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;

	case 6:
		if(checkInp){
			sapXepMang(a,n);//tu them vao nhe :33
		}
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;

	case 7:
		if(checkInp){
			cout<<"Nhap so lan xoay :";
			cin>>k;
			xoayMang(a,n,k);
		}
		else
			cout<<"Vui long khoi tao truoc!!!"<<endl;
		break;
	}
	cout<<"\nBan co muon tiep tuc(Y/N) ? :";
	cin>>tt;
	}while(tt == 'Y' || tt == 'y');//nguoi dung nhan phim Y or N
}
void nhapMang(int a[] , int &n){
	cout<<"\nNhap "<<n<<" gia tri phan tu cho mang "<<endl;
	for(int i = 0 ; i < n ;++i){
		cout<<"Phan tu a["<<i<<"]:";
		cin>>a[i];
	}
}
void xuatMang(int a[] , int n){
	cout<<"\nMANG HIEN TAI "<<endl;
	for(int i = 0 ;i < n ;i++){
		cout<<a[i]<<" ";
	}
}
bool isEmpty(int &n){
	if(n == 0)
		return false;
	return true;
}
int timPhanTu(int a[] , int n , int val){
	for(int i = 0 ;i < n ; i++){
		if(a[i] == val)
			return i;// tim thay va tra ve vi tri tim duoc
	}
	return -1;
}
int xoaPhanTu(int a[] , int &n , int val){
	int kq = timPhanTu(a,n,val);

	if(kq != -1){
		n--;
		//neu phan tu tim duoc dau tien
		for(int i = kq ; i < n ; i++){
			a[i] = a[i + 1];
		}		
		return 1;
	}return -1;// giong nhu khong tim duoc
}
void themPhanTu(int a[] , int &n , int vitri){
	//1 2 3 4 5
	// vi tri 1 - them 6
	//6 1 2 3 4 5
	if(vitri - 1 >= 0 && vitri - 1 <= n - 1){
		cout<<"Nhap gia tri can chen :";
		cin>>val;
		//ky thuat them phan tu
		//1: Doi tat ca phan tu sang phai 1 buoc (tru vi tri can chen)
		//2: Sau khi doi het , danh dau vi tri can chen va gan gia tri can them vao
		//3: Tang so luong phan tu hien tai len 1 don vi
		for(int i = n; i >= vitri; i--){
			a[i] = a[i - 1];
		}
		a[vitri - 1] = val;
		n++;
		cout<<"Them thanh cong!!!"<<endl;
	}else{
		cout<<"Khong co vi tri nay!!!"<<endl;
	}
}
void sapXepMang(int a[] , int &n){
	cout<<"\tSAP XEP"<<endl;
	cout<<"1.Tang dan"<<endl;
	cout<<"2.Giam dan"<<endl;
	cout<<"3.Le tang trai - chan giam phai"<<endl;
	cout<<"4.Le giam phai - chan tang trai"<<endl;
	cout<<"5.Xen ke le chan tang dan(Updating...)"<<endl;
	
	//switch - if 
	//them cac ham o thu vien sort.h
	//tu them vao nhe :3
}
void xoayMang(int a[] , int n , int &k){
	for(int i = 1 ; i <= k ; i++){
		int t = a[0];
		for(int j = 0 ; j < n - 1; j++){
			a[j] = a[j + 1];
		}
		a[n - 1] = t;
	}
	cout<<"Mang sau khi xoay "<<k<<" lan ";
	xuatMang(a,n);

}