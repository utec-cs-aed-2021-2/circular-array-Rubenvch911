#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}
template<typename T>
T &CircularArray<T>::operator[]( int i)
{
    int count =0;
    auto index=front;
    while( count!=i)
    {
        index= next(index);
        count++;
    }
    return array[index];
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
bool CircularArray<T>::is_full()
{
    if(prev(front)==back)
        return true;
    return false;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if(back && front == -1){
        return true;
    }
    return false;
}

template<class T>
int CircularArray<T>::size()
{
    int size=0;
    int index=front;
    while(index!=back){
        index=next(index);
        size++;
    }
    size++;
    return size;
}


template <class T>
void CircularArray<T>::push_back(T data)
{
    if(is_empty() == true)
        front=0,back=0;
    else
        back=next(back);
    array[back]=data;
    //cout<<"New size is: "<<size()<<endl;
    int index=front;
    for(int i=0;i<size();i++)
    {
        cout<<array[index]<<" ";
        index=next(index);
    }
    cout<<"ga"<<endl;

}

template <class T>
void CircularArray<T>::push_front(T data)
{
    if(is_empty() == true)
        front=0,back=0;
    else
        front=prev(front);
    array[front]=data;
    //cout<<"New size is: "<<size()<<endl;
    int index=front;
    for(int i=0;i<size();i++)
    {
        cout<<array[index]<<" ";
        index=next(index);
    }
    cout<<"ga"<<endl;
}

template <class T>
T CircularArray<T>::pop_front()
{
    T to_pop=array[front];
    front=next(front);
    if(is_empty()==true){
        front=-1;
        back=-1;
    }
    return to_pop;
}

template <class T>
T CircularArray<T>::pop_back()
{
    T to_pop=array[back];
    back=prev(back);
    if(is_empty()==true){
        front=-1;
        back=-1;
    }
    return to_pop;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <typename T>
bool CircularArray<T>::is_sorted()
{
    int i, j; 
    for (i = 0; i < size()-1; i++) 
     {     
         int indexj=front;
    for (j = 0; j < size()-i-1; j++) 
    {
        if (array[indexj] > array[next(indexj)]) 
            return false;
        indexj=next(indexj);
     }

     }
    return true; 
}

template <typename T>
void CircularArray<T>::sort()
{
    int i, j; 
    for (i = 0; i < size()-1; i++) 
     {     
         int indexj=front;
    for (j = 0; j < size()-i-1; j++) 
    {
        if (array[indexj] > array[next(indexj)]) 
            swap(&array[indexj],&array[next(indexj)]);
        indexj=next(indexj);
     }

     }
}
template<typename T>
void CircularArray<T>::reverse()
{
    int indexf= front;
    int indexb= back;
    for(int i =size(); i>1;i-=2)
    {
        swap(&array[indexf],&array[indexb]);
        indexf=next(indexf);
        indexb=prev(indexb);
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string(this->operator[](i)) + sep;
    return result;
}