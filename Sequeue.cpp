#include <iostream>
using namespace std;
typedef int DataType;
class SeqQueue
{
private:
	DataType *base;
	int front ;
	int rear;
	int size;
public:
	SeqQueue(int Queuesize=100)       //����һ���ն��У�Ĭ�ϴ�СΪ100
	{
		base=new DataType[Queuesize];
		front=0;
		rear=0;
		size=Queuesize;
	};
	~SeqQueue()              //����һ���Ѵ��ڵĶ���
	{
		delete []base;
	};
	int Empty_Queue();             //�ж϶����Ƿ�Ϊ��
	int En_Queue(DataType e);        //��ӽ�Ԫ��e�����β
	int De_Queue(DataType &e);       //���ӴӶ�ͷɾ��һ��Ԫ�ص�e�з���
	int Front_Queue(DataType &e);        //ȡ��ͷԪ�أ��Ӷ�ͷȡ��һ��Ԫ�ص�e�з���
};

int SeqQueue::Empty_Queue()          //�ж϶����Ƿ�Ϊ��
{
	return (front==rear);
}

int SeqQueue::En_Queue(DataType e)       //��ӽ�Ԫ��e�����β
{
	if((rear+1)%size==front)
		return 0;
	else 
	{   rear=(rear+1)%size;
		base[rear]=e;
		return 1;
	}

}

int SeqQueue:: De_Queue(DataType &e)         //���ӴӶ�ͷɾ��һ��Ԫ�ص�e�з���
{
	if(Empty_Queue())              //�ж϶����Ƿ��ǿ�
		return 0;
	else
	{
		front=(front+1)%size;
		e=base[front];
		return 1;
	}
}

int SeqQueue::Front_Queue(DataType &e)     //ȡ��ͷԪ�أ��Ӷ�ͷȡ��һ��Ԫ�ص�e�з���
{
	if(rear!=front)
	{
		
		e=base[(front+1)%size];
		return 1;
	}
	else
		return 0;
}

int main()
{
	return 0;
}