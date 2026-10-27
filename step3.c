#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7
#define EMPTY -1
#define DELETED -2

int table[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }
}

void printTable() {
    printf("\n=== Hash Table Status ===\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY) {
            printf("[%d]: EMPTY\n", i);
        } else if (table[i] == DELETED) {
            printf("[%d]: DELETED\n", i);
        } else {
            printf("[%d]: %d\n", i, table[i]);
        }
    }
}

void insert(int key) {
    int index = hash(key);
    int count = 0;

    while(count < TABLE_SIZE) {
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        count++;
    }
}

int search(int key) {
    int index = hash(key);
    int count = 0;

    while(count < TABLE_SIZE) {
        if (table[index] == key) {
            return index;
        }
        if (table[index] == EMPTY) {
            return -1;
        }
        index = (index + 1) % TABLE_SIZE;
        count++;
    }
    return -1;
}

void delete_key(int key) { 
    int index = hash(key);
    int count = 0;
    while (count < TABLE_SIZE) {
        if (table[index] == key) {
            table[index] = DELETED;
            return;
        }
        if (table[index] == EMPTY) {
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        count++;
    }
    return;
}

int main() {
    init_table();

    insert(12); 
    insert(23); 
    insert(34); 

    printTable();

    delete_key(12);
    printTable();

    return 0;
}















#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7
#define EMPTY -1
#define DELETED -2

int table[TABLE_SIZE];

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 5 - (key % 5);
}

void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }
}

void printTable() {
    printf("\n=== Hash Table Status ===\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY) {
            printf("[%d]: EMPTY\n", i);
        } else if (table[i] == DELETED) {
            printf("[%d]: DELETED\n", i);
        } else {
            printf("[%d]: %d\n", i, table[i]);
        }
    }
    printf("=========================\n");
}

void insert(int key) {
    int index = hash1(key);
    int step = hash2(key); 
    int count = 0;

    while (count < TABLE_SIZE) {
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            return;
        }
        index = (index + step) % TABLE_SIZE; 
        count++;
    }
    printf("테이블이 가득 차서 %d를 삽입할 수 없습니다.\n", key);
}

int search(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int count = 0;

    while (count < TABLE_SIZE) {
        if (table[index] == key) {
            return index;
        }
        if (table[index] == EMPTY) {
            return -1;
        }
        index = (index + step) % TABLE_SIZE; 
        count++;
    }
    return -1;
}

void delete_key(int key) { 
    int index = hash1(key);
    int step = hash2(key);
    int count = 0;

    while (count < TABLE_SIZE) {
        if (table[index] == key) {
            table[index] = DELETED;
            return;
        }
        if (table[index] == EMPTY) {
            return;
        }
        index = (index + step) % TABLE_SIZE; 
        count++;
    }
}

int main() {
    init_table();

    insert(12); 
    insert(23); 
    insert(19); 

    printTable();

    delete_key(12);
    printTable();

    int search_idx = search(19);
    if (search_idx != -1) {
        printf("\n값 19는 인덱스 %d에 있습니다.\n", search_idx);
    } else {
        printf("\n값을 찾을 수 없습니다.\n");
    }

    return 0;
}