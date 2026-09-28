// Stack using array

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack
{
    int s[SIZE];
    int top;
} st;

int isFull()
{
    if (st.top >= SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int pop()
{
    int item;

    item = st.s[st.top];
    st.top--;

    return item;
}

void push(int item)
{
    st.top++;
    st.s[st.top] = item;
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("\nStack is empty!!!");
    }
    else
    {
        printf("\nStack elements are:");

        for (i = st.top; i >= 0; i--)
        {
            printf("\n%d", st.s[i]);
        }
    }
}

int main(void)
{
    int item, choice;
    char ans;

    st.top = -1;

    printf("\nImplementation of Stack");

    do
    {
        printf("\n\nMain menu");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the item to be pushed: ");
                scanf("%d", &item);

                if (isFull())
                    printf("\nStack is full");
                else
                    push(item);

                break;

            case 2:
                if (isEmpty())
                {
                    printf("\nEmpty stack (Underflow)");
                }
                else
                {
                    item = pop();
                    printf("\nThe popped element is: %d", item);
                }

                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}





// QUEUE using array

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Queue
{
    int arr[SIZE];
    int front, rear;
} q;

int isfull()
{
    if (q.rear >= SIZE - 1)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if (isfull())
    {
        printf("\nQueue is full");
    }
    else
    {
        q.rear = q.rear + 1;
        q.arr[q.rear] = item;
    }
}

int isempty()
{
    if (q.front > q.rear)
        return 1;
    else
        return 0;
}

// Changed delete() to deleteElement()
int deleteElement()
{
    int item;

    if (isempty())
    {
        printf("\nQueue is Empty");
        return -1;
    }
    else
    {
        item = q.arr[q.front];
        q.front = q.front + 1;

        return item;
    }
}

void display()
{
    int i;

    if (isempty())
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nQueue elements are: ");

        for (i = q.front; i <= q.rear; i++)
        {
            printf("%d\t", q.arr[i]);
        }
    }
}

int main()
{
    int choice, item;

    q.front = 0;
    q.rear = -1;

    while (1)
    {
        printf("\n\nImplementation of Queue");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter item to insert: ");
                scanf("%d", &item);

                insert(item);
                break;

            case 2:
                if (isempty())
                {
                    printf("\nQueue is Empty");
                }
                else
                {
                    item = deleteElement();
                    printf("\nDeleted item is: %d", item);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting the program...");
                exit(0);

            default:
                printf("\nInvalid Choice!!");
        }
    }

    return 0;
}