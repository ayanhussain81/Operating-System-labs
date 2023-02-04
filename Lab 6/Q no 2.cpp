#include <iostream>
using namespace std;

class Best_Fit
{
    int blocksNo;
    int filesNo;
    int blockArr[100];
    int fileArr[100];
    int block = 0;

public:
    Best_Fit()
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

    void calculate()
    {
        bool isPrinted = false;

        for (int i = 0; i < this->filesNo; i++)
        {
            for (int j = 0; j < this->blocksNo; j++)
            {
                if (this->fileArr[i] == this->blockArr[j])
                {
                    this->block = j;
                    break;
                }

                if (this->fileArr[i] < this->blockArr[j] && this->blockArr[j] < this->blockArr[this->block] || this->blockArr[this->block] - this->fileArr[i] < 0)
                {
                    this->block = j;
                }
            }
            if (!isPrinted)
            {
                cout << "File No. : \t\t File Size : \t\t Block No. : \t\t Block Size : \t\t Fragment : \t\t";
                cout << endl;
            }
            isPrinted = true;
            cout << i + 1 << "\t\t\t" << this->fileArr[i] << "\t\t\t" << this->block + 1 << "\t\t\t" << this->blockArr[this->block] << "\t\t\t" << this->blockArr[this->block] - this->fileArr[i] << endl;
            this->blockArr[this->block] -= this->fileArr[i];
        }
    }
};

int main()
{
    Best_Fit bf;
    bf.calculate();

    return 0;
}
