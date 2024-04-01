#include "queue.h"
#include "searchAndSort.h"

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

    insertionSort(vec);
    cout << "\n\nSorted List: " << endl;
   for(int x = 0; x < vec.size();x++){
       cout << vec[x] << " ";
   }
    return 0;
}
