#include<iostream>
#include<stdlib.h>
using namespace std;

struct heap{
	int *arr;
	int count;
	int capacity;
}*h;

int leftChild(heap *h,int i)
{
	int left = (2*i)+1;
	if (left>=h->count)
		return 0;
	return left;
}

int rightChild(heap *h,int i)
{
	int right = (2*i)+2;
	if (right>=h->count)
		return 0;
	return right;
}

void percolateDown(heap *h,int n)
{
	int l,r,max;
	l = leftChild(h,n);
	r = rightChild(h,n);
	if (l!=0 && h->arr[l]>h->arr[n])
		max = l;
	else 
		max = n;
	if (r!=0 && h->arr[r]>h->arr[max])
		max = r;
	int temp;
	if (max !=n)
	{
	temp = h->arr[n];
	h->arr[n] = h->arr[max];
	h->arr[max] = temp;
	percolateDown(h,max);
	}
}

int deleteMax(heap *h)
{
	int data;
	if (h->count == 0)
		return 0;
	data = h->arr[0];
	h->arr[0] = h->arr[h->count-1];
	h->arr[h->count-1] = data;
	h->count--;
	percolateDown(h,0);
	return data;
}

void reSize(heap *h)
{
	int *array_old = h->arr;
	cout<<array_old[1];
	h->arr = new int[h->capacity*2];
	
	if (!h->arr)
		return;
	
	for (int i=0;i<h->capacity;i++)
		h->arr[i] = array_old[i];
	h->capacity *= 2;
	free(array_old);
	
}

void insert(heap *h,int data)
{
	int i;
	if (h->count == h->capacity)
		reSize(h);
	h->count++;
	i = h->count-1;
	while (i>=0 && data > h->arr[(i-1)/2])
	{
//	cout<<"h[i]  "<<h[i]<<" and h[i-1 /2]"<<h
	h->arr[i] = h->arr[(i-1)/2];
	i = (i-1)/2;	
	}
	h->arr[i] = data;
}

void buildHeap(heap *h, int A[], int n)
{
	while (n>h->capacity)
		reSize(h);
	for (int i =0;i<n; i++)
	{
		h->arr[i] = A[i];
	}
	h->count = n;
	for (int i = (n-1)/2; i>=0; i--)
		percolateDown(h,i);
	
	
	for (int i = 0;i<h->count;i++)
		cout<<"-->"<<h->arr[i];
	cout<<"-----"<<endl;
	 
	
}

void heapSort(int A[], int n)
{
//	h = (struct heap *) malloc(sizeof(struct heap));
	buildHeap(h,A,n);
	int temp;
	for (int i = n-1;i>=0;i--)
	{
	//	cout<<"i is "<<i<<endl;
		cout<<"->"<<h->arr[0]<<endl;
		temp = h->arr[0];
		h->arr[0] = h->arr[h->count-1];
		h->arr[h->count-1] = temp;
		h->count--;
		percolateDown(h,0);
	//	cout<<"A"<<endl;
	}
	
	 
	
		
}

main()
{
h = (struct heap *) malloc(sizeof(struct heap));
h->capacity = 10;
h->count = 0;
h->arr =new int[h->capacity];
/*h->arr[0] = 10;
h->arr[1] = 6;
h->arr[2] = 5;
h->arr[3] = 4;
h->arr[4] = 2;
h->arr[5] = 1;
h->arr[6] = 0;	
h->count= 7;*/
int A[] = {4,1,6,3,7,2,5};

heapSort(A,7);
	
//for (int i = 0;i<h->count;i++)
//	cout<<"-->"<<h->arr[i];
//	cout<<endl;
/*		
deleteMax(h);
for (int i = 0;i<h->count;i++)
	cout<<"-->"<<h->arr[i];
cout<<endl;

deleteMax(h);
for (int i = 0;i<h->count;i++)
	cout<<"-->"<<h->arr[i];
	cout<<endl;
*/	

//insert(h,7);
//for (int i = 0;i<h->count;i++)
//	cout<<"-->"<<h->arr[i];
//	cout<<endl;


}
