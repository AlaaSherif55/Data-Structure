#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T>* pNext;
    Node<T>* pPrev;
    Node<T>()
    {
        Data = T();
        pNext = pPrev = nullptr;
    }
    Node<T>(T d)
    {
        Data = d;
        pNext = pPrev = nullptr;
    }
    ~Node<T>()
    {
    }
};

template<class T>
class Queue
{
private:
    Node<T>* pHead;
    Node<T>* pTail;
    int size;
public:
    Queue()
    {
        pHead = pTail = nullptr;
        size = 0;
    }
    Queue(const Queue& copyQueue)
    {
        pHead = pTail = nullptr;
        size = 0;
        Node<T>* curr = copyQueue.pTail;
        while (curr != nullptr)
        {
            this->Enqueue(curr->Data);
            curr = curr->pPrev;
        }
    }
    void Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (IsEmpty())
        {
            pHead = pTail = newNode;
        }
        else
        {
            newNode->pNext = pHead;
            pHead->pPrev = newNode;
            pHead = newNode;
        }

        size += 1;
    }
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Empty";
        }
        else
        {
            Node<T>* curr = pTail;
            while (curr != nullptr)
            {
                cout << curr->Data << " ";
                curr = curr->pPrev;
            }
        }

        cout << endl;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    void ClearList()
    {
        Node<T>* temp;
        while (pHead != nullptr)
        {
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        pTail = nullptr;
        size = 0;
    }
    T Dequeue(){
        if (size == 0)
			return T();
		else if (size == 1)
		{
            T data=pTail->Data;
			delete pTail;
			pHead = pTail = nullptr;
            size--; 
            return data;
		}
		else
		{ 
            Node<T>* temp=pTail;
            T data=pTail->Data;
            pTail=pTail->pPrev;
            pTail->pNext=nullptr;
			delete temp;
            size--; 
            return data;
		
		}
		
    }
};

int main()
{
    Queue<int> myQueue;

    // Enqueue some elements
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    Queue<int> newQueue(myQueue);
    newQueue.Display();
    myQueue.Display();
    // cout << "display element in queue: ";
    // myQueue.Display();

    // cout << "the element return after dequeue: " << myQueue.Dequeue() << endl;
    // cout << "the element return after dequeue: " << myQueue.Dequeue() << endl;
    // //cout << "the element return after dequeue: " << myQueue.Dequeue() << endl;

    // cout << "display after dequeue: ";
    // myQueue.Display();

    // myQueue.ClearList();

    // cout << "display after clear: ";
    // myQueue.Display();

    return 0;
}