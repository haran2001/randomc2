//implementation of circular queue using linked lists
struct Node {
    int data;
    struct Node* link;
};

struct Queue {
    struct Node *front, *rear;
};

// enque() to add element at the rear end
void enQueue(Queue* q, int value)
{
    struct Node* temp = new Node;
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->link = temp;

    q->rear = temp;
    q->rear->link = q->front;
}

// deque() to delete from the front end
int deQueue(Queue* q)
{
    if (q->front == NULL) {
        printf("Queue is empty");
        return INT_MIN;
    }

    // If this is the last node to be deleted
    int value; // Value to be dequeued
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else     {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
    }

    return value;
}

void displayQueue(struct Queue* q)
{
    struct Node* temp = q->front;
    printf("\nElements in Circular Queue are: ");
    while (temp->link != q->front) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
}

int main()
{
    Queue* q = new Queue;
    q->front = q->rear = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    // Display
    displayQueue(q);
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
    displayQueue(q);

    return 0;
}
