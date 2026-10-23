#include <iostream>
using namespace std;
int L,R;
int a[10],b[10],c[10];
void merge(int a[],int L,int mid,int R){
	int blen=mid-L+1;
	int clen=R-mid;
	for(int i=1;i<=blen;i++){
		b[i]=a[L+i-1];
	}
	for(int i=1;i<=clen;i++){
		c[i]=a[mid+i];
	}
	int i=1,j=1,k=L;
	while(i<=blen&&j<=clen){
		if(b[i]<c[i]){
			a[k]=b[i];
			i++;
		}
		else{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	if(i>blen){
		for(int t=j;t<=clen;t++){
			a[k]=c[t];
			k++;
		}
	}
		else{
			for(int t=i;t<=blen;t++){
				a[k]=b[t];
				k++;
			}
		}
}
void sort(int a[],int L,int R){
	if(L<R){
		int mid=(L+R)/2;
		sort(a,L,mid);
		sort(a,mid+1,R);
		merge(a,L,mid,R);
	}
}
main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}