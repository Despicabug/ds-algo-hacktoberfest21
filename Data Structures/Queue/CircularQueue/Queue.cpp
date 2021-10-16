
#include<bits/stdc++.h>
#include<iostream>

#include "Queue.h"

using namespace std;

q1::q1(int length) {
	// TODO Auto-generated constructor stub
	front=-1;							//first patient
	rear=-1;							//end patient
	size=length;						//max size of queue
	queue=new Patient[size];			//creating an array of length 'size'
	counter=0;							//no of patients in queue
}

void q1::addPatient(Patient newPatient)			//method to add to queue
{
	//checking if the queue is empty
	if(this->isEmpty())
	{
		front++;								//incrementing the front
		rear++;									//incrementing the rear
		queue[rear]=newPatient;					//adding the new patient at rear side
	}

	//Not Full
	else if(!this->isFull())
	{
		//no. of patients should be betn 0 to (size-1)
		rear=(rear+1)%size;						//incrementing rear

		queue[rear]=newPatient;			//adding the new patient at the end
	}

	//queue full Condition
	else
		cout<<"\nQueue is Full";

	//making sure that counter does not exceed the max value
}

void q1::removePatient()						//method to remove patient
{
	if(this->isEmpty())							//already empty list
		return;

	else if(!this->isEmpty()){

		if(front==rear)							//checking if only element present in the list
		{
			front=-1;							//empty list condition
			rear=-1;
		}

		else									//more than one element present in the list
			front=(front+1)%size;				//incrementing front value
	}

	else										//zero elements in the list
		cout<<"Queue is Empty";
}

bool q1::isEmpty()
{
//	if(front==rear and rear==-1)
	if(front==-1)					//checking if the list is empty
		return true;
	else											//not empty
		return false;
}

bool q1::isFull()
{
//	if(front==0 and rear==size-1)
	if((rear+1)%size==front)		//queue full condition
		return true;
	else
		return false;
}

void q1::display()
{
	if(front!=-1)
	{
	cout<<endl;

	for(int i=0;(front+i)%size!=rear;i++)					//printing all the elements till rear(rear not included)
	{
		cout<<queue[(front+i)%size].name<<"|";
	}

	cout<<queue[rear].name<<"|";							//printing the rear Value
	cout<<endl<<endl;
	cout<<"front: "<<front<<"| rear: "<<rear<<"| counter: "<<counter<<endl;
	}
}

q1::~q1() {
}
