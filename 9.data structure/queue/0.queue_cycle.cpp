class MyCircularQueue
{
private:
    int queue[10001] = {0};
    int maxsize = 0;
    int head = 0;  //队首指针
    int end = -1;  //队尾指针
    int count = 0; //记录队列中的元素的个数

public:
    MyCircularQueue(int maxsize)
    {
        if (maxsize <= 1000)
            this->maxsize = maxsize;
    }

    bool enQueue(int value)
    {
        if (count < maxsize)
        {
            count++;
            end = (end + 1) % maxsize;
            queue[end] = value;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (count == 0)
        {
            return false;
        }
        count--;
        head = (head + 1) % maxsize;
        return true;
    }

    int Front()
    {
        if (count == 0)
        {
            return -1;
        }
        return queue[head];
    }

    int Rear()
    {
        if (count == 0)
        {
            return -1;
        }
        return queue[end];
    }

    bool isEmpty()
    {
        if (count == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (count == maxsize)
        {
            return true;
        }
        return false;
    }

    int number_count()
    {
        return count;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
