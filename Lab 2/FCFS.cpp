#include <iostream>
using namespace std;

class FCFS
{
private:
    int size;
    int *BurstT;
    int *WaitngT;
    int *TurnaroundT;

public:
    FCFS(int s, int *B)
    {
        size = s;
        BurstT = B;
        WaitngT = new int[s];
        TurnaroundT = new int[s];
    }

    void calWaitingTime()
    {
        WaitngT[0] = 0;
        for (int i = 1; i < size; i++)
        {
            int k = 0;
            for (int j = 0; j < i; j++)
            {
                k += BurstT[j];
            }
            WaitngT[i] = k;
        }
    }

    void calTurnAroundTime()
    {
        for (int i = 0; i < size; i++)
        {
            TurnaroundT[i] = WaitngT[i] + BurstT[i];
        }
    }

    void Print()
    {
        int i=0;int j = 0;
        for (int k = 0; k < size; k++)
        {
            i += WaitngT[k];
            j += TurnaroundT[k];
        }
        cout<<i<<endl;
        cout<<"Processors\t Burst Time \t\t Waiting Time \t\t Turnaround Time "<<endl;

        for (int l = 0; l < size; l++)
        {
            cout <<"P"<<l+1<<"\t\t\t "<<BurstT[l]<<"\t\t\t "<<WaitngT[l]<<"\t\t\t "<<TurnaroundT[l]<<endl;
        }

        cout<<endl;

        cout<<"Average waiting time is "<<i/size<<endl;
        cout<<"Average turn around time is "<<j/size<<endl;
    }
};

int main()
{
    int size;
    int BT[20] = {0};
    cout << "Owner Ayan Hussain"<<endl;
    cout << "Enter the number of processors : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> BT[i];
    }

    FCFS fcfs(size, BT);
    fcfs.calWaitingTime();
    fcfs.calTurnAroundTime();
    fcfs.Print();

    return 0;
}
