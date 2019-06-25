/*
 *
 *     Kod: Oscar Milstein och Ove Ødegård
 *
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>

template <typename T>
class PriorityQueue
{
private:
    size_t arraySize;
    size_t last;
    T *heap;

    void percolateUp(const size_t child);
    void percolateDown(const size_t parent);
    void swap(const size_t node1, const size_t node2);

public:
    PriorityQueue();
    ~PriorityQueue();

    void enqueue(const T &element);
    void dequeue();
    const T &peek() const;
    size_t size() const;
    bool isEmpty() const;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    arraySize = 8;
    last = 0; // The heap will never use position 0
    heap = new T[arraySize];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] heap;
}

template <typename T>
void PriorityQueue<T>::enqueue(const T &element)
{
    last++;
    // Expand array if necessary
    if (last == arraySize)
    {
        size_t oldSize = arraySize;
        arraySize *= 2;
        T *oldHeap = heap;
        heap = new T[arraySize];
        for (size_t i = 1; i < oldSize; i++)
        {
            heap[i] = oldHeap[i];
        }
        delete[] oldHeap;
    }
    heap[last] = element;
    percolateUp(last);
}

template <typename T>
void PriorityQueue<T>::dequeue()
{
    if (last == 0)
        throw std::range_error("The queue is empty!");
    heap[1] = heap[last--];
    percolateDown(1);
}

template <typename T>
void PriorityQueue<T>::percolateUp(const size_t child)
{
    if (child != 1)
    {
        size_t parent = child / 2; // Integer division
        if (heap[child] < heap[parent])
        {
            swap(child, parent);
            percolateUp(parent);
        }
    }
}

template <typename T>
void PriorityQueue<T>::percolateDown(const size_t parent)
{
    size_t child1 = parent * 2;
    size_t child2 = child1 + 1;
    size_t smallestChild = child1;
    if (child1 <= last)
    {
        if (child2 <= last)
        {
            if (heap[child2] < heap[child1])
                smallestChild = child2;
        }
        if (heap[smallestChild] < heap[parent])
        {
            swap(parent, smallestChild);
            percolateDown(smallestChild);
        }
    }
}

template <typename T>
void PriorityQueue<T>::swap(const size_t node1, const size_t node2)
{
    T temp = heap[node1];
    heap[node1] = heap[node2];
    heap[node2] = temp;
}

template <typename T>
const T &PriorityQueue<T>::peek() const
{
    if (last > 0)
        return heap[1];
    throw std::range_error("The queue is empty!");
}

template <typename T>
size_t PriorityQueue<T>::size() const
{
    return last;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return (last == 0);
}

#endif