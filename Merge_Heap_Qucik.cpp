#include <bits/stdc++.h>
using namespace std;
template<typename T>
void Merge_Sort(T * a,int L,int R)
{
	if(R-L<=1) return;
	T * b = new T[R-L+1];
	int mid = (L+R)/2;
	Merge_Sort(a,L,mid);
	Merge_Sort(a,mid,R);
	int i = L, j = mid, p = 0;
	while(i<mid||j<R) {
		if(i<mid&&a[i]<=a[j]||j==R) b[p++] = a[i++];
		else b[p++] = a[j++];
	}
	for(i=R-1;i>=L;--i) a[i] = b[--p]; 
	delete []b;	
}
void Quick_Sort(int * a,int L,int R)
{
	if(R-L<=1) return;
	if(R-L==2) {
		if(a[L]>a[L+1]) {
			int t = a[L]; a[L] = a[L+1]; a[L+1] = t; 
		} return;
	}
	int mid = (L+R)/2,p=L,x=a[L];
	if(x<a[mid]&&x<a[R-1]) p = a[mid]>a[R-1]?mid:R-1;
	else if(x>a[mid]&&x>a[R-1]) p = a[mid]>a[R-1]?R-1:mid;
	x = a[p]; //L,mid,R-1三点取中 
	a[p] = a[L]; a[L] = x; //和第一个交换  
	int i = L,j = R;
	while(i<j) {
		while(j>i&&a[--j]>=x); a[i] = a[j];
		while(i<j&&a[++i]<=x); a[j] = a[i];
	} 
	a[i] = x;
	Quick_Sort(a,L,i); //[) 
	Quick_Sort(a,i+1,R); //[)
}

void Heap_Sort(int * p,int L,int R)
{
	int * a = p+L-1;    //4,5,6,7,8,   9
 	int len = R-L,x,v,y;
 	for(int i=len/2;i>=1;--i) {
 		x = i, v = a[i];
		while(x*2<=len) {
			y = x*2;
			if(x*2+1<=len&&a[x*2+1]>a[y]) y = x*2+1;
			if(a[y]<=v) break;
			a[x] = a[y]; x = y;
		} a[x] = v; 
	}
	while(len>1) {
		x = a[1],a[1] = a[len], a[len--] = x;
		v = a[1], x = 1;
		while(x*2<=len) {
			y = x*2;
			if(x*2+1<=len&&a[x*2+1]>a[y]) y = x*2+1;
			if(a[y]<=v) break;
			a[x] = a[y]; x = y;	
		} a[x] = v;
	}
}

template<typename T>
void showArray(T * a,int L,int R)
{
	int cnt = 0;
	for(int i=L;i<R;++i)
	{
		cout<<setw(6)<<a[i]<<" ";
	}
	puts("");
}
int arr[100];
int main()
{
	srand(time(NULL));
	srand(1);
	for(int i=0;i<17;++i)
		arr[i] = rand()%97;
	showArray(arr,0,10);
//	Quick_Sort(arr,0,17);
//	cout<<"快速排序后的数列为：\n";
//	showArray(arr,0,17);	
//	Merge_Sort(arr,0,17);
//	cout<<"归并排序后的数列为：\n";
	Heap_Sort(arr,0,10); 
	showArray(arr,0,10);
	return 0;
} 
