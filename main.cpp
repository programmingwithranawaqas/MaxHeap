#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;
    int curr;
public:
    MaxHeap()
    {
        arr = NULL;
        size=0;
        curr=0;
    }
    MaxHeap(int size)
    {
        this->size = size;
        arr = new int[size];
        curr = 0;
    }
    int getTotal()
    {
        return curr;
    }
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    void insert(int data)
    {
        if(curr<size)
        {
            arr[curr] = data;
            int temp = curr;
            while(curr>0 && arr[temp]>arr[(temp-1)/2])
            {
                swap(arr[temp], arr[(temp-1)/2]);
                temp = (temp-1)/2;
            }
            curr++;
        }
    }
    void inorder(int i)
    {

        //cout<<arr[2]<<endl;
        if(i<curr)
        {
            inorder(i*2+1);
            cout<<arr[i]<<" , ";
            inorder(i*2+2);
        }
    }
    int leftChild(int i)
    {
        if((i*2+1)<curr)
        {
            return i*2+1;
        }
        return -1;
    }
    int rightChild(int i)
    {
        if(i*2+2<curr)
            return i*2+2;
        return -1;
    }
    int max(int x, int y)
    {
        if(arr[x]>arr[y])
            return x;
        return y;
    }
    int deleteData()
    {
        int temp = arr[0];
        arr[0] = arr[curr-1];
        curr--;

        int i = 0;

        while(i<curr)
        {
            int leftIndex = leftChild(i);
            int rightIndex = rightChild(i);
            if(leftIndex!=-1 && rightIndex!=-1)
            {
                int largest = max(leftIndex, rightIndex);
                if(arr[largest]>arr[i])
                {
                    swap(arr[largest], arr[i]);
                    i = largest;
                }
            }
            else if(leftIndex!=-1 && rightIndex==-1)
            {
                if(arr[i*2+1]>arr[i])
                {
                    swap(arr[i*2+1], arr[i]);
                    i = i*2+1;
                }
            }
            else
            {
                break;
            }
        }
        return temp;

    }
};

int main()
{
    MaxHeap mxH(10);
    mxH.insert(30);
    mxH.insert(45);
    mxH.insert(25);
    mxH.insert(90);
    //mxH.inorder(0);

    cout<<"Deleted number is : "<<mxH.deleteData()<<endl;
    mxH.inorder(0);
    //cout<<mxH.getTotal();
    return 0;
}
