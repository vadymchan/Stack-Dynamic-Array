#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:
    Stack(int value = 0);
    ~Stack();

    T push(T value); 
    T pop();
    bool isEmpty();
    bool isFull();
    int count();
    void displayAll();
    void display();

    T operator[](int index);//overload an operator[] to access an element
    //(but not change it because it'll crash the logic of the stack)
private:
    T* arr;
    int SIZE;
    int top;
};



int main()
{
    //Stack<type> name(SIZE of stack)
    Stack<int> stack(10);
    return 0;
}

template<typename T>
Stack<T>::Stack(int SIZE)
{
    arr = new T[SIZE]();
    this->SIZE = SIZE;
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] arr;
    SIZE = 0;
    top = -1;
}

/// <summary>
/// add an element to the top of stack
/// </summary>
/// <returns>added value</returns>
template<typename T>
T Stack<T>::push(T value)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
        return T();
    }
    else
    {
        arr[++top] = value;
        return value;
    }
}

/// <summary>
/// remove an element from the top
/// </summary>
/// <returns>removed element</returns>
template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow " << endl;
    }
    else
    {
        T returnValue = arr[top];
        arr[top--] = T();
        return returnValue;
    }
}

/// <summary>
/// check if a stack is Empty or not(to avoid stack underflow)
/// </summary>
template<typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

/// <summary>
/// check if a stack is Full or not(to avoid stack overflow)
/// </summary>
template<typename T>
bool Stack<T>::isFull()
{
    return top + 1 == SIZE;
}

/// <summary>
/// return number of elements in stack
/// </summary>
template<typename T>
int Stack<T>::count()
{
    return top + 1;
}

/// <summary>
/// prints all elements in stack(including an empty slots)
/// </summary>
template<typename T>
void Stack<T>::displayAll()
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        cout << i << "->" << arr[i] << endl;
    }
}

/// <summary>
/// prints elements in stack
/// </summary>
template<typename T>
void Stack<T>::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << i << "->" << arr[i] << endl;
    }
}

/// <summary>
/// overload operator[] to easily acces to an element in stack(but it doesn't change it)
/// </summary>
template<typename T>
T Stack<T>::operator[](int index)
{
    if (index >= 0 && index < SIZE)
    {
        return arr[index];
    }
    cout << "Error: index is bigger than the length of stack OR index is a negative number" << endl;
    return T();
}
