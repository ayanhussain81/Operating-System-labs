#include <iostream>

using namespace std;

int mutex = 1;
int full = 0;
int empty = 10, item = 0;

void producer(){
    --mutex;
    ++full;
    --empty;
    item++;
    cout << "Producer produces " << item << " item" << endl;
    ++mutex;
}

void consumer(){
    --mutex;
    --full;
    ++empty;
    item--;
    cout << "Consumer consumes " << item << " item" << endl;
    ++mutex;
}

int main()
{
    int n,i;
    cout << "\n Press 1 for Producer" << "\n Press 2 for Consumer"<< "\n Press 3 for Exit" << endl;
    
#pragma omp critical
    
    for(i = 1; i>0; i++) {
        cout << " Enter your choice " ;
        cin >> n;
        
        switch(n){
            case 1:
            if((mutex == 1) && (empty != 0 )){
                producer();
            }
            else {
                cout << "Buffer is full" << endl;
            }
            break;
            
            case 2:
            if((mutex == 1) && (full != 0 )){
                consumer();
            }
            else {
                cout << "Buffer is empty" << endl;
            }
            break;
            
            case 3: 
            exit(0);
            break;
        }
    }

    return 0;
}