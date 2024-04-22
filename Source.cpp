/*
* Will Hooker
* 10/20/2023
* CS221-02
* This program creates a stack using an array. The elements inserted into the stack are pre-determined.
* The program calls functions to push and pop the elements into the stack, and has a function to check if the stack is full or empty.
*/
#include <iostream>

using namespace std;

struct stack { //using a struct to create the stack variable, which contains the top index, the array, and the functions performed on the stack

	int top = -1; //top starts on the value -1 to indicate an empty stack, since the 1st index of the array will be 0
	int array[5] = {};

	void push(int data) { //the push function
		top++; //increments top before adding a value

		if (isFull() == 1) { //checks if the stack is full, and if it is, top decreases back to the last index of the array
			cout << "Stack is full. Cannot push more elements." << endl;
			top--;
			return;
		}
		array[top] = data; //adds the data value to the top of the stack 
		cout << "Pushed element: " << array[top] << endl;
	}

	void pop() { //the pop function
		if (isEmpty() == 1) { //checks if the stack is empty
			cout << "Stack is empty. Cannot pop elements." << endl;
			return;
		}
		cout << "Popped element: " << array[top] << endl;
		array[top] = 0; //setting the value to 0 to "remove" the element
		top--; //decreases the top index after the value is popped. Now points to the new top of the stack
	}

	int isEmpty() { //this function checks if the stack is empty by checking if top is equal to -1. returns 1 if true, 0 otherwise
		if (top == -1) return 1;
		else return 0;
	}

	int isFull() { //function checks if the stack is full by seeing if the top index is one number larger than the last index of the array. returns 1 if true, 0 otherwise
		if (top == 5) return 1;
		else return 0;
	}
};



int main() {

	stack myStack; //initializes the stack

	myStack.push(10); //calls the push function and passes a data value to add to the stack
	myStack.push(20);
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);
	myStack.push(60); //attempting to add more values than the stack can hold

	myStack.pop(); //calls the pop function to remove the top elements of the stack
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop(); //attempting to remove a value when the stack is empty

	return 0;
}
