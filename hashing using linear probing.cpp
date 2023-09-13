#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1; // Initialize all slots as empty (-1)
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hash_table[index] = key;
    printf("Inserted %d at index %d.\n", key, index);
}

bool search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hash_table[index] != -1) {
        if (hash_table[index] == key) {
            printf("%d found at index %d.\n", key, index);
            return true;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            break; // Checked all slots
        }
    }

    printf("%d not found in the hash table.\n", key);
    return false;
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> %d\n", i, hash_table[i]);
    }
}

int main() {
    initializeHashTable();

    insert(5);
    insert(15);
    insert(25);
    insert(7);
    insert(12);

    displayHashTable();

    search(15);
    search(7);
    search(50);

    return 0;
}

