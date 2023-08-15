/*
六、何謂環狀佇列(Circular Queue)（4分）？請使用 C、Java等程式語言或虛擬碼(Pseudo Code)
以陣列(Array)方式實作環狀佇列，其中須包含新增與刪除佇列元素之方法（20 分）。
*/

#include<iostream>
#include<climits>
class Circular_Queue {
    public:
    Circular_Queue(int s)
        : front(-1), rear(-1), size(s)
        {
            q = new int[s];
        }
    ~Circular_Queue()
    {
        delete [] q;
    }
    void    en_queue(int v);
    int     de_queue();
    void    print();

    private:
    int front;
    int rear;
    int size;
    int *q;
};

void Circular_Queue::en_queue(int v)
{
    if ((front==0 && rear==size-1) || ((rear+1)%size)==front)
    {
        std::cout << "Queue is full!\n";
        return;
    }
    else if (front == -1) /* first element */
    {
        front = rear = 0;
        q[rear] = v;
    }
    else if (rear == size-1 && front != 0) 
    {
        rear = 0;
        q[rear] = v;
    }
    else
    {
        rear++;
        q[rear] = v;
    }
}
int Circular_Queue::de_queue()
{
    if (front == -1)
    {
        std::cout << "Queue is empty!\n";
        return INT_MIN;
    }
    int data = q[front];
    if (front == rear) /* the last one in queue */
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}
void Circular_Queue::print()
{
    if (front == -1)
    {
        std::cout << "Queue is empty!\n";
        return;
    }
    if (rear >= front)
    {
        for (int i=front; i<=rear; i++)
        {
            std::cout << q[i] << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        for (int i=front; i<size; i++)
        {
            std::cout << q[i] << ' ';
        }
        for (int i=0; i<=rear; i++)
        {
            std::cout << q[i] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    Circular_Queue cq(5);
    cq.en_queue(14);
    cq.print();
    cq.en_queue(22);
    cq.print();
    cq.en_queue(13);
    cq.print();
    cq.en_queue(-6);
    cq.print();
    std::cout << "deque " << cq.de_queue() << "\n";
    cq.print();
    std::cout << "deque " << cq.de_queue() << "\n";
    cq.print();
    cq.en_queue(9);
    cq.print();
    cq.en_queue(20);
    cq.print();
    cq.en_queue(5);
    cq.print();
    /* full */
    cq.en_queue(2);
    cq.print();
    /* dequeue empty */
    for (int i=0; i<7; i++)
    {
        std::cout << "deque " << cq.de_queue() << "\n";
        cq.print(); 
    }
    return 0;
}