#include "queue.h"
#include "linearSearch.h"

using namespace std;

int main() {

    //Loading the queue
    queue<int> Q;
    Q.push(5);
    Q.push(3);
    Q.push(17);
    Q.push(45);
    Q.push(30);
    Q.push(27);
    Q.push(81);
    Q.push(25);
    Q.push(66);
    Q.push(33);

    cout << "\nPrinted Queue: " << endl;
    while(!Q.empty()){
        cout << Q.front() << endl;
        Q.pop();
    }

    vector<int> vec = {1,2,3,4,5,2,5,6}; // Initializing an example array
    cout << "\nLast occurrence of 2 in [1,2,3,4,5,2,5,6]: index ";
    cout << linear_search(vec,2,vec.size()-1);

    cout << "\n\nUnsorted List:" << endl;
    linkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(2);
    list.push_back(5);
    list.push_back(6);
    list.print();

    cout << "\n\nSorted List: " << endl;
    list.insertionSort();
    list.print();
    return 0;
}
