#include <iostream>

using namespace std;

int mutex = 1;
int full = 0;
int empty = 50, item = 0;

void INSERT(){
    --mutex;
    ++full;
    --empty;
    item++;
    cout << " Page inserted, total pages are " << item << " item" << endl;
    ++mutex;
}

void PRINT(){
    --mutex;
    --full;
    ++empty;
    item--;
    cout << " Printer prints the page : " << item << " item" << endl;
    ++mutex;
}

int main()
{
    int n,i;
    cout << "\n Press 1 for Inserting new Page" << "\n Press 2 for Inserting Page"<< "\n Press 3 for Exit" << endl;
    
#pragma omp critical
    
    for(i = 1; i>0; i++) {
        cout << " Enter your choice " ;
        cin >> n;
        
        switch(n){
            case 1:
            if((mutex == 1) && (empty != 0 )){
                INSERT();
            }
            else {
                cout << " Printer tray is full!" << endl;
            }
            break;
            
            case 2:
            if((mutex == 1) && (full != 0 )){
                PRINT();
            }
            else {
                cout << "Printer tray is empty" << endl;
            }
            break;
            
            case 3: 
            cout <<" Printer process end";
            exit(0);
            break;
        }
    }

    return 0;
}