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
class LinkedList
{
private:
    Node<T>* pHead;
    Node<T>* pTail;
    int count;
public:
    LinkedList()
    {
        pHead = pTail = nullptr;
        count = 0;
    }
    LinkedList(const LinkedList& copyLinkedList)
    {
        pHead = pTail = nullptr;
        count = 0;
        Node<T>* curr = copyLinkedList.pHead;
        while (curr != nullptr)
        {
            this->insertLast(curr->Data);
            curr = curr->pNext;
        }
    }
    void insertLast(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (IsEmpty())
        {
            pHead = pTail = newNode;
        }
        else
        {
            newNode->pPrev = pTail;
            pTail->pNext = newNode;
            pTail = newNode;
        }
        count += 1;
    }
    void insertFirst(T data)
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

        count += 1;
    }
    void insertAt(T data, int pos)
    {
        if (pos == 0)
        {
            insertFirst(data);
        }
        else if (pos == count)
        {
            insertLast(data);
        }
        else
        {
            Node<T>* curr = pHead;
            Node<T>* newNode = new Node<T>(data);
            for (int i = 1; i < pos; i++)
            {
                curr = curr->pNext;
            }

            newNode->pNext = curr->pNext;
            newNode->pPrev = curr;
            curr->pNext->pPrev = newNode;
            curr->pNext = newNode;
            count += 1;
        }
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
    void reverse_Display()
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
        return count == 0;
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
        count = 0;
    }
    Node<T>* Search(T data)
    {
        Node<T>* curr = pHead;
        while (curr != nullptr)
        {
            if (curr->Data == data)
            {
                return curr;
            }
            else
            {
                curr = curr->pNext;
            }
        }
        return nullptr;
    }
    void Delete(T data){
         Node<T>* newNode=Search(data);
        if(newNode!=nullptr){
           if(count==1){
              pHead=pTail=nullptr;
              delete newNode;
           }else if(pHead->Data==data){
                DeleteFirst();
           }else if(pTail->Data==data){
                DeleteLast();
           }else{
            Node<T>* curr = pHead;
            while(curr->Data!=newNode->Data){
                curr=curr->pNext;
            }
            curr->pPrev->pNext=curr->pNext;
            curr->pNext->pPrev=curr->pPrev;
            delete curr;
            count-=1;
           }
        }else{
            cout<<"Not Exist";
        }
    }
    void DeleteFirst(){
    
        if (count == 0)
			cout << "Empty List" << endl;
		else if (count == 1)
		{
			delete pHead;
			pHead = pTail = nullptr;
		}
		else
		{ 
            Node<T>* temp=pHead;
            pHead=pHead->pNext;
            pHead->pPrev=nullptr;
			delete temp;
		
		}
		count--; 
    }
    void DeleteLast(){
        if (count == 0)
			cout << "Empty List" << endl;
		else if (count == 1)
		{
			delete pHead;
			pHead = pTail = nullptr;
		}
		else
		{ 
            Node<T>* temp=pTail;
            pTail->pPrev->pNext=nullptr;
            pTail=pTail->pPrev;
			delete temp;
		
		}
		count--; 
    }
    void BubbleSort() {
    bool flag;
    Node<T>* last = nullptr;

    do {
        flag = false;
        Node<T>* curr = pHead;

        while (curr != last && curr->pNext != nullptr) {
            if (curr->Data > curr->pNext->Data) {
                T temp = curr->Data;
                curr->Data = curr->pNext->Data;
                curr->pNext->Data = temp;
                flag = true;
            }
            curr = curr->pNext;
        }
        last = curr;

    } while (flag);
}
};

int main()
{
    LinkedList<int> myList;

     
    // Test insertLast
    myList.insertLast(50);
    myList.insertLast(40);
    myList.insertLast(30);
    
    /*cout << "before insert first: ";
    myList.Display();
    //test insertFirst
    myList.insertFirst(5);
    cout << "after insert first: ";
    myList.Display();

    //test insertAt
    myList.insertAt(15, 2);
    cout << "after insert at pos 2: ";
    myList.Display();

    //test display from first to end
    cout << "display list: ";
    myList.Display();

    //test revese display from end to first
    cout << "reverse daiplay list ";
    myList.reverse_Display();
    LinkedList<int> copyList(myList);

    //test copy constructor
    cout << "The new linked list that i created: ";
    copyList.Display();

    int dataToDelete = 20;
    cout << "deleting " << dataToDelete << " from the list: ";
    myList.Delete(dataToDelete);
    myList.Display();

    //test DeleteFirst
    cout << "deleting the first element: ";
    myList.DeleteFirst();
    myList.Display();

    //test DeleteLast
    cout << "deleting the last element: ";
    myList.DeleteLast();
    myList.Display();
    */

    //test bubble sort
    cout << "before apply bubbleSort: ";
    myList.Display();
    myList.BubbleSort();
    cout << "after apply BubbleSort: ";
    myList.Display();
    return 0;
}
