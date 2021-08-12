#include <iostream>
using namespace std;
#define SIZE 10


class Queue {
private:
    int* arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    Queue(int size=SIZE)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    Queue() {
        delete[] arr;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << arr[front] << endl;

        front = (front + 1) % capacity;
        count--;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << value << endl;

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "queue is empty \n";
        }
        else {
            for (int i = front; i < rear+1; i++) {
                cout << arr[i]<<"\t\t";
            }
            cout << "\n\n";
        }
    }


    int size() {
        return count;
    }

    bool isEmpty() {
        return (size() == 0);
    }

    bool isFull() {
        return (size() == capacity);
    }


};
int main()
{
    int choice=0,Size=SIZE,value;
    cout << "Please enter the size of the queue \n";
    cin >> Size;
    Queue q(Size);
    while (choice != 4)
    {
        cout<<"\n*************************Main Menu*****************************\n";
        cout<<"\n=================================================================\n";
 
        cout<<"\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n";
        cout<<"\nEnter your choice ?\t\t";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout << "enter the value: \t\t";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            system("Cls");
            cout << "Exitiing...\n ";
            break;
        default:
            cout<<"\nEnter valid choice??\n";
        }
    }
    system("pause>0");
}

