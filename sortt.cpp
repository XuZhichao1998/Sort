#include <bits/stdc++.h>
using namespace std;
/*
ð������ 

*/
void heapAdjust(int * a,int st,int ed); //���϶��µ��� ��st��ed֮��Ķ�����Ϊ�� ;
void toHeap(int * a,int n);
void heapSort(int* a,int n,int m) ;
template<typename T>
void print(T * a,int n)
{
	for(int i=0;i<n;i++)
		cout<<setw(3)<<a[i]<<"  ";cout<<endl; 
}
template<typename T>
void Print(T* st,T*ed)
{
	for(T*p=st;p!=ed;p++)
		cout<<setw(3)<<*p<<"   "; cout<<endl;
}
template<typename T>
void BubbleSort(T* start,T* end,int tag=0)
{
 	T * a = start;
 	int n = end-start;
 	bool flag = true;
 	if(tag)
 	{
 		cout<<"ð������"<<endl;
 		cout<<"���п�ʼΪ��";
		print(a,n);	
	}
 	for(int i=1;flag&&i<n;i++)
 	{
 		flag = false;
 		for(int j=0;j<n-i;j++)
 		{
 			if(a[j]>a[j+1]) swap(a[j],a[j+1]),flag = true;	
		}
		if(tag)
		{
			cout<<"��"<<i<<"�ˣ�";
			print(a,n); 
		}
	}
} 
/*

8
49 38 65 97 96 13 27 49

*/
template<typename T>
void SelectSort(T * st,T * ed,int tag)
{
	if(tag)
	{
		cout<<"ѡ������"<<endl;
		cout<<"���п�ʼΪ��";
		Print(st,ed);
	}
	int n = ed-st;
	T * a = st;
	for(int i=0;i<n-1;i++)
	{
		int k = i;
 		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k = j;
		}
		if(i!=k)
			swap(a[i],a[k]);
		cout<<"��"<<i+1<<"�ˣ�";
		Print(st,ed);
	}
}
template<typename T>
int Partition(T * a,int low,int high,int n) //��[low,high]�������򣬷�����Ŧ��λ�� 
{
	//cout<<"����֮ǰ��";
	print(a,n); 
	T key = a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=key)
			--high;
		if(low<high) a[low++] = a[high];
		while(low<high&&a[low]<=key)
			++low;
		if(low<high) a[high--] = a[low];
	}
	a[low] = key;
	//cout<<"����֮��";
	//print(a,n); 
	//cout<<"piv = "<<low<<endl; 
	return low;
}

/*


10
256 301 751 129 937 863 742 694 76 438


8
49 38 65 97 76 13 27 49


*/
template<typename T>
void QSort(T *a,int s,int t,int & cnt,int n,int tag=0)
{
	if(s<t)
	{
		int piv = Partition(a,s,t,n);
		//if(tag)
	//	{
		//	cout<<"��"<<++cnt<<"�λ��ֺ�piv = "<<piv<<endl;
		//	print(a,n);
	//	}
		
		QSort(a,s,piv-1,cnt,n,1);
		QSort(a,piv+1,t,cnt,n,1);
	}
}
template<typename T>
void QuickSort(T * st,T*ed,int tag=0)
{
	int cnt = 0;
	QSort(st,0,ed-st-1,cnt,ed-st,0);
}

int a[100];
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
//	BubbleSort(a,a+n,1);
	SelectSort(a,a+n,1);
	//Print(a,a+n);
	//QuickSort(a,a+n,1);
//	heapSort(a-1,n,n);
//	print(a+1,n+);
	
	
	return 0;
} 
///======================================================================================== 

void heapAdjust(int * a,int st,int ed) //���϶��µ��� ��st��ed֮��Ķ�����Ϊ�� 
{
	for(int i=st,j=i*2;j<=ed;i=j,j*=2)
	{
		if(j<ed&&a[j+1]>a[j])  j++;
		if(a[j]>a[i]) swap(a[j],a[i]);
		else break;
	}
}
void toHeap(int * a,int n)  //��ԭ��������������Ϊ�� 
{
	for(int i=n/2;i>=1;i--)
	{
		heapAdjust(a,i,n);
	}
}
void heapSort(int* a,int n,int m) //������ 
{
	toHeap(a,n);
	cout<<"�� "<<1<<"�ˣ�";
	Print(a+1,a+n+1);
	swap(a[1],a[n]); //printf("%d",a[n]);
	int cnt = 1;
	for(int i=n-1;i>1/*&&cnt<m*/;i--)
	{
		heapAdjust(a,1,i);//printf(" %d",a[1]);cnt++;
		cout<<"�� "<<++cnt<<"�ˣ�";
		Print(a+1,a+n+1); 
		swap(a[1],a[i]);
	}
	cout<<"��"<<++cnt<<"�ˣ�";
	Print(a+1,a+n+1); 
	//if(cnt<m) printf(" %d",a[1]);
	//printf("\n");
	system("pause"); 
}
