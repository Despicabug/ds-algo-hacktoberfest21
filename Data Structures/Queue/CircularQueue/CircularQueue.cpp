#include "Queue.h"
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	q1 obj(3);
	int choice=0;

	while(choice<6)
	{
		cout<<"\n<----Menu---->"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Full"<<endl;
		cout<<"4. Empty"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;

		if(choice==1)
		{
			string name;
			Patient newPatient;
			cout<<"Name: ";
			getline(cin,name);
			getline(cin,name);
			newPatient.name=name;
			cout<<"Age: ";
			cin>>newPatient.age;
			cout<<"Height: ";
			cin>>newPatient.height;
			cout<<"Weight: ";
			cin>>newPatient.weight;

			obj.addPatient(newPatient);
		}
		else if(choice==2)
			obj.removePatient();
		else if(choice==3)
			if(obj.isFull())
				cout<<endl<<"Queue is Full";
			else
				cout<<endl<<"Not Full";
		else if(choice==4)
			if(obj.isEmpty())
				cout<<endl<<"Queue is Empty";
			else
				cout<<endl<<"Not Empty";
		else
			break;

		obj.display();

	}
}
