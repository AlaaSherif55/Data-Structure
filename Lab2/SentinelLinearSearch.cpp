#include<iostream>
using namespace std; 
int sentinelLinearSearch(int arr[],int length,int key){
    int last=key;
    arr[length-1]=key;
    int i=0;
    while (arr[i]!=key)
    {
     i++;
    }
    arr[length-1]=last;
    if(i<length-1||arr[length-1]==key){
         return i;
    }
    return -1;
}


int main()
{
   int arr[5]={1,4,3,46,8};
   int result=sentinelLinearSearch(arr,5,4);
   cout<<result;
	return 0;

}
