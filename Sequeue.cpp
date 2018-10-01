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
	SeqQueue(int Queuesize=100)       //构造一个空队列，默认大小为100
	{
		base=new DataType[Queuesize];
		front=0;
		rear=0;
		size=Queuesize;
	};
	~SeqQueue()              //销毁一个已存在的队列
	{
		delete []base;
	};
	int Empty_Queue();             //判断队列是否为空
	int En_Queue(DataType e);        //入队将元素e插入队尾
	int De_Queue(DataType &e);       //出队从队头删除一个元素到e中返回
	int Front_Queue(DataType &e);        //取队头元素，从队头取出一个元素到e中返回
};

int SeqQueue::Empty_Queue()          //判断队列是否为空
{
	return (front==rear);
}

int SeqQueue::En_Queue(DataType e)       //入队将元素e插入队尾
{
	if((rear+1)%size==front)
		return 0;
	else 
	{   rear=(rear+1)%size;
		base[rear]=e;
		return 1;
	}

}

int SeqQueue:: De_Queue(DataType &e)         //出队从队头删除一个元素到e中返回
{
	if(Empty_Queue())              //判断队列是否是空
		return 0;
	else
	{
		front=(front+1)%size;
		e=base[front];
		return 1;
	}
}

int SeqQueue::Front_Queue(DataType &e)     //取队头元素，从队头取出一个元素到e中返回
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