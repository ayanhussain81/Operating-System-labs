#include <iostream>
using namespace std;

class First_Fit
{
    int blocksNo;
    int filesNo;
    int blockArr[100];
    int fileArr[100];

public:
    First_Fit()
    {
        cout << "Enter the number of blocks : ";
        cin >> this->blocksNo;
        cout << "Enter the number of files : ";
        cin >> this->filesNo;
        cout << "Enter the size of blocks :" << endl;
        for (int i = 0; i < this->blocksNo; i++)
        {
            cout << "Block " << i + 1 << " : ";
            cin >> this->blockArr[i];
        }
        cout << "Enter the size of files :" << endl;
        for (int j = 0; j < this->filesNo; j++)
        {
            cout << "File " << j + 1 << " : ";
            cin >> this->fileArr[j];
        }
    }

    void calculate(){
        bool isPrinted = false;
        for(int i = 0; i < this->filesNo;i++){
            for (int j = 0; j < this->blocksNo; j++)
            {

                if(this->fileArr[i]<=this->blockArr[j]){
                    if(!isPrinted){
                    cout<<"File No. : \t\t File Size : \t\t Block No. : \t\t Block Size : \t\t Fragment : \t\t";
                    cout<<endl;
                    }
                    isPrinted = true;
                    cout<<i+1<<"\t\t\t"<<this->fileArr[i]<<"\t\t\t"<<j+1<<"\t\t\t"<<this->blockArr[j]<<"\t\t\t"<<this->blockArr[j]-this->fileArr[i]<<endl;
                    this->blockArr[j] -= this->fileArr[i];
                    break;
                }
            }
            
        }
    }
};

int main()
{
    First_Fit ff;
    ff.calculate();

    return 0;
}
