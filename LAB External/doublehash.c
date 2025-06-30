#include <stdio.h>
#define s 10
#define p 7  // Should be a p smaller than s

int hashTable[s];

// Initialize hash table with -1 (representing empty)
void initHashTable() {
    for (int i = 0; i < s; i++) {
        hashTable[i] = -1;
    }
}

// First hash function
int h1(int key) {
    return key % s;
}

// Second hash function (must be non-zero, different from h1)
int h2(int key) {
    return p - (key % p);
}

// Insert using double hashing
void insert(int key) {
    int index = h1(key);

    if (hashTable[index] != -1) {
        int i = 1;
        while (1) {
            int newIndex = (index + i * h2(key)) % s;
            if (hashTable[newIndex] == -1) {
                hashTable[newIndex] = key;
                return;
            }
            i++;
            if (i == s) {
                printf("Hash table is full!\n");
                return;
            }
        }
    } else {
        hashTable[index] = key;
    }
}
int search(int key)
{
    int index = h1(key);
    if (hashTable[index] != key) {
        int i = 1;
        while (1) {
            int newIndex = (index + i * h2(key)) % s;
            if (hashTable[newIndex] == key) {
                return newIndex;
            }
            i++;
            if (i == s) {
                printf("\nElement not found\n");
                return -1;
            }
        }
    } else {
        return index;
    }
}
void delete(int val){
    int pos = search(val);
    if(hashTable[pos] == val)
    {
        printf("\n%d is deleted",hashTable[pos]);
        hashTable[pos]=-1;
        return;
    }
}
// Display hash table
void display() {
    for (int i = 0; i < s; i++) {
        if (hashTable[i] != -1)
            printf("%d --> %d\n", i, hashTable[i]);
        else
            printf("%d --> EMPTY\n", i);
    }
}

// Main function to test
int main() {
    initHashTable();

    int keys[] = {23, 43, 13, 27, 33, 39, 88, 91};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    printf("Hash Table after inserting keys:\n");
    display();
    printf("%d ",search(27));
    delete(45);
    delete(91);
    display();
    return 0;
}