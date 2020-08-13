#include <bits/stdc++.h>
using namespace std;


class DoubleHash {
    int* hashTable;
    int curr_size;
public:

    bool isFull()
    {
        return (curr_size == 13);
    }

    int hash1(int value)
    {
        return (value % 13);
    }

    int hash2(int value)
    {
        return (7 - (value % 13));
    }

    DoubleHash()
    {
        hashTable = new int[13];
        curr_size = 0;
        for (int i = 0; i < 13; i++)
            hashTable[i] = 0;
    }
    void insertHash(int value)
    {
        if (isFull())
            return;


        if (hashTable[hash1(value)] != 0) {
            int index2 = hash2(value);
            int i = 1;
            for(int i=1;i<13;i++)
                {int newIndex = (hash1(value) + i * index2) % 13;
                if (hashTable[newIndex] == 0) {
                    hashTable[newIndex] = value;
                    break;
                }
                }
        }
        else
            hashTable[hash1(value)] = value;
        curr_size++;
    }

    void search(int value)
    {
        int index1 = hash1(value);
        int index2 = hash2(value);
        int i = 0;
        while (hashTable[(index1 + i * index2) % 13] != value) {
            if (hashTable[(index1 + i * index2) % 13] == 0) {
                cout << value << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << value << " found" << endl;
    }

    // function to display the hash table
    void displayHash()
    {
        for (int i = 0; i < 13; i++) {

                cout << i << " --> "
                     << hashTable[i] << endl;

        }
    }
};

// Driver's code
int main()
{
    int a[] = { 18,41,22,44};
    int n = sizeof(a) / sizeof(int);
    DoubleHash h;
    for (int i = 0; i < n; i++) {
        h.insertHash(a[i]);
    }
    h.search(44);

    h.displayHash();
    return 0;
}
