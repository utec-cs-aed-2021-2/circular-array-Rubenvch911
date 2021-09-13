#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {

public:
    QueueArray();
    QueueArray( int capa);
    void enqueue(T data);
    T dequeue();
    void display();

};
template<typename T>
QueueArray<T>::QueueArray()
{
    CircularArray<T>(0);
}
template <class T>
QueueArray<T>::QueueArray(int capa) : CircularArray<T>(capa)
{

}
template<typename T>
void QueueArray<T>::enqueue(T data)
{
    this->push_back(data);
}

template <class T>
T QueueArray<T>::dequeue()
{
    auto to_pop=this->pop_front();
    return to_pop;
}

template <class T>
void QueueArray<T>::display()
{
    auto index = this->back;
    do{
        cout<<this->array[index]<<" ";
        index=this->prev(index);

    }while(index!=this->prev(this->front));
    cout<<endl;
}