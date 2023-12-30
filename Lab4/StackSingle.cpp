#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    T Data;
    Node<T>* pNext;
    Node<T>()
    {
        Data = T();
        pNext = nullptr;
    }
    Node<T>(T d)
    {
        Data = d;
        pNext= nullptr;
    }
    ~Node<T>()
    {
    }
};
template<class T>
class StackSingle
{
private:
    Node<T>* pHead;
    int size;
public:
    StackSingle()
    {
        pHead = nullptr;
        size = 0;
    }
    StackSingle(const StackSingle& copyStack)
    {
        pHead = nullptr;
        size = 0;
        Node<T>* curr = copyStack.pHead;
        while (curr != nullptr)
        {
            this->Append(curr->Data);
            curr = curr->pNext;
        }
    }
    void Append(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (IsEmpty())
        {
            pHead = newNode;
        }
        else
        {
           Node<T>*curr=pHead;
           while(curr->pNext!=nullptr){
            curr=curr->pNext;
           }
           curr->pNext=newNode;
        }

        size += 1;
    }
    void Push(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (IsEmpty())
        {
            pHead = newNode;
        }
        else
        {
            newNode->pNext = pHead;
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
            Node<T>* curr = pHead;
            while (curr != nullptr)
            {
                cout << curr->Data << " ";
                curr = curr->pNext;
            }
        }

        cout << endl;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    void ClearStack()
    {
        Node<T>* temp;
        while (pHead != nullptr)
        {
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        size = 0;
    }
    T Pop(){
        if (size == 0){
          return T();
        }
		else if (size == 1)
		{
            T data=pHead->Data;
			delete pHead;
			pHead = nullptr;
            return data;
		}
		else
		{ 
            Node<T>* temp=pHead;
            T data=temp->Data;
            pHead=pHead->pNext;
			delete temp;
            return data;
		
		}
		size--; 
    }
    
    ~StackSingle(){
         Node<T>* temp;
        while (pHead != nullptr)
        {
            temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        size = 0;
    }
   
};
int main()
{
    StackSingle<int> myStack;

    // Push some elements onto the stack
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);
    StackSingle<int> newStack(myStack);
    cout << "stack contents: ";
    newStack.Display();
    myStack.Display();

    // // Display the contents of the stack
    // cout << "stack contents: ";
    // myStack.Display();

    // //pop elements from the stack
    // cout << "the element that pop: " << myStack.Pop() << endl;
    // cout << "the element that pop: " << myStack.Pop() << endl;

    // //display the element after pop
    // cout << "stack after popping: ";
    // myStack.Display();

    // //clear the stack
    // myStack.ClearStack();

    // //display after clear fun
    // cout << "stack after clearing: ";
    // myStack.Display();
    return 0;
}
