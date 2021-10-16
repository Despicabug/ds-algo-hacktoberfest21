
#ifndef QUEUE_H_
#define QUEUE_H_
#include<string>

struct Patient{
	std::string name;
	int age,weight,height;

};

class q1 {
	Patient* queue;
	int size;			//size of queues
	int front;			//first patient
	int rear;			//last patient
	int counter;		//no of patients in the queue
public:
	void addPatient(Patient);
	bool isEmpty();
	bool isFull();
	void removePatient();
	void display();
	q1(int);
	virtual ~q1();
};

#endif /* QUEUE_H_ */
