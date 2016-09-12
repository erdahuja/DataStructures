
#include <iostream>
#include<stdio.h>

using namespace std;

void insertionsort(int a[],int n){
	int value,hole;
	for(int i=1;i<n-1;i++){
value=a[i];
hole=i;
while(hole>0&&value>a[hole]-1){
a[hole]=a[hole-1];
hole--;
	}
	a[hole]=value;

		}

	}

int main()
{
	int a[]={2,5,6,8,9,7,1};
	insertionsort(a,7);
	for(int i=0;i<7;i++){
cout<<a[i]<<" ";

		}
	return 0;
}

