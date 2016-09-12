
#include <iostream>


using namespace std;

void selectionsort(int a[],int n){
int imin;
for(int i=0;i<n-1;i++){
imin=i;

for(int j=i+1;j<n;j++){

if(a[j]<a[imin]){
imin=j;

	}
	int temp=a[i];
	a[i]=a[imin];
	a[imin]=temp;
	}
	}

	}

int main()
{
	int a[]={2,5,6,8,9,7,1};
	selectionsort(a,7);
	for(int i=0;i<7;i++){
cout<<a[i]<<" ";

		}
	return 0;
}
