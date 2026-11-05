#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = 0;

int isEmpty(void) {
    return front == rear;
}

int isFull(void) {
    return (rear+1)%SIZE == front;
}

int enqueue(int value) {
    if (isFull()) {
        return 0;
    }

    rear = (rear+1)%SIZE;
    queue[rear] = value;

    return 1;
}

int dequeue(void) {
    front = (front + 1) % SIZE;
    return queue[front];
}

int peek(void) {
    return queue[(front + 1) % SIZE];

}

void printQueue(void) {
    if (isEmpty()) {
        printf("큐가 비어 있습니다\n");
        return;
    }

    int i = (front + 1) % SIZE;

    printf("큐: ");

    while(1) {
        printf("%d ", queue[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % SIZE;
    }

    printf("\n");
}



int main(void) {
    int choice, value;

    while(1) {
        printf("\n--- 원형 큐 메뉴 ---\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 다음 삭제 대상 확인\n");
        printf("4. 전체 출력\n");
        printf("0. 종료\n");
        printf("선택: ");
        
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("삽입할 값 입력: ");
                scanf("%d", &value);
                if (enqueue(value)) {
                    printf("%d 삽입 성공\n", value);
                } else {
                    printf("큐가 가득 찼습니다.\n");
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("큐가 비어 있습니다.\n");
                } else {
                    printf("삭제된 값: %d\n", dequeue());
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("큐가 비어 있습니다.\n");
                } else {
                    printf("다음 삭제 대상: %d\n", peek());
                }
                break;
            case 4:
                printQueue();
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 선택하세요.\n");
                break;
        }
    }

    return 0;
}







