#include "circulararray.h"


template <typename T>
class StackArray : public CircularArray<T>
{
public:
    StackArray();
    StackArray(int capa);
    void push(int data);
    T pop();
    void display();
};
template <class T>
StackArray<T>::StackArray()
{
    CircularArray<T>(0);
}
template <class T>
StackArray<T>::StackArray(int capa) : CircularArray<T>(capa)
{

}
template <class T>
void StackArray<T>::push(int data)
{
    this->push_back(data);
}

template <class T>
T StackArray<T>::pop()
{
    auto to_pop=this->pop_back();
    return to_pop;
}

template <class T>
void StackArray<T>::display()
{
    auto index = this->back;
    do{
        cout<<this->array[index]<<" ";
        index=this->prev(index);

    }while(index!=this->prev(this->front));
}