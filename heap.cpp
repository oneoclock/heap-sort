#include <iostream>
#include <cstdlib>
using namespace std;

class heap
{
	int a[100], n, flag;
public:
	heap()
{
		flag=0;
		a[0]=0;
		n=0;
}
	void makeheap(int, int);
	void accept(int);
	void upadjust(int);
	void minheap(int);
	void disp();
	void sortheap();
	void downadjust_1(int);
	void downadjust_2(int);
};

void heap :: accept(int choice)
{
	cout<<"Enter size: ";
	cin>>n;
	cout<<"Enter array";
	int x;
	for(int j=0; j<n; j++)
	{
		cout<<endl<<"Enter element: ";
		cin>>x;
		makeheap(x, choice);
	}
}

void heap :: makeheap(int x, int choice)
{
	a[++a[0]]=x;
	if(choice==1)
	upadjust(a[0]);
	else if(choice==2)
	minheap(a[0]);
	else
	cout<<"Invalid choice";
}

void heap :: upadjust(int i)
{
	flag++;
	int temp;
	while(i>1 && a[i]>a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}
}

void heap :: minheap(int i)  // for creating minimum heap
{
	flag--;
	int temp;
	while(i>1 && a[i]<a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}
}

void heap :: disp()
{
	int i;
	cout<<endl;
	for(i=1; i<=n; i++)
	{
		cout<<a[i]<<endl;
	}
}

void heap :: sortheap()
{
	int temp;
	for(int i=1; i<n; i++)
	{
		temp=a[a[0]];
		a[a[0]]=a[1];
		a[1]=temp;
		a[0]--;
		if(flag>0)
		downadjust_1(1);
		else if(flag<0)
		downadjust_2(1);
	}
}

void heap :: downadjust_1(int i)
{
	int x=a[0];
	if(2*i<=x)		//checking if child present
	{
		int j=2*i;
		if(j+1<=x && a[j+1]>a[j])
		{
			j++;
		}
		if(a[i]<a[j])
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			downadjust_1(j);
		}
	}
}

void heap :: downadjust_2(int i)
{
	int x=a[0];
	if(2*i<=x)
	{
		int j=2*i;
		if(j+1<=x && a[j+1]<a[j])
		{
			j++;
		}
		if(a[i]>a[j])
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			downadjust_2(j);
		}
	}
}

int main() {
	int ch, choice;
	heap obj;
	while(true){
	cout<<"1. Enter Elements.\n2. Display\n3. Sort\n4. Exit\nEnter choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\n1. Max Heap\n2. Min Heap\nEnter choice: ";
		cin>>choice;
		obj.accept(choice);
		break;
	case 2:
		obj.disp();
		break;
	case 3: obj.sortheap();
		break;
	case 4: exit(0);
		break;
	default: cout<<"Invalid selection";
		break;
	}}
	return 0;
}
