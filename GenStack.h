#include <iostream>

using namespace std;

template <class T>
class GenStack {
	public:
		GenStack(int maxSize);
		~GenStack();

		//replacing char data with T data
		void push(T data); //T to make it a template data type. This T will be replaced with the type you pass when you instantiat a stack.
		T pop();
		T peek();
		int isFull();
		int isEmpty();

		int top; //index top to keep track of the top element in stack
		int max;

		T *myArray; //pointer that will act as a back in array, stack of chars. not initiallized, can be changed dynamically
		
};

template <class T>
GenStack<T>::GenStack(int maxSize){
	myArray = new T[maxSize];
	fill_n(myArray, maxSize, 0);
	max = maxSize;
	top = -1;
}

template <class T>
GenStack<T>::~GenStack() {
	cout << "object deleted" << endl;
	delete myArray; 
}

template <class T>
void GenStack<T>::push(T data) {
	if (!isFull()) {
		myArray[++top] = data;
	}
}

template <class T>
T GenStack<T>::pop(){
	if(!isEmpty()){
		return myArray[top--];
	}
}

template <class T>
T GenStack<T>::peek(){
	if (!isEmpty()) {
		return myArray[top];
	}
}

template <class T>
int GenStack<T>::isFull(){
	return (top == max - 1);
}

template <class T>
int GenStack<T>::isEmpty(){
	return (top == -1);
}
















