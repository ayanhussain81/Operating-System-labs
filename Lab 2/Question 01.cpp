#include <iostream>
using namespace std;

class FCFS
{
private:
    int size;
    int *BurstT;
    int *ArrivalT;
    int *WaitingT;
    int *TurnaroundT;

public:
    FCFS(int s, int *B,int *A)
    {
        size = s;
        BurstT = B;
        ArrivalT=A;
        WaitingT = new int[s];
        TurnaroundT = new int[s];
    }

    void calWaitingTime()
    {
        WaitingT[0] = ArrivalT[0];
        for (int i = 1; i < size; i++)
        {
            int k = 0;
            for (int j = 0; j < i; j++)
            {
                k += BurstT[j];
            }
            WaitingT[i] = k-ArrivalT[i];
        }
    }

    void calTurnAroundTime()
    {
        for (int i = 0; i < size; i++)
        {
            TurnaroundT[i] = WaitingT[i] + BurstT[i];
        }
    }

    void Print()
    {
        float i=0;float j = 0;
        for (int k = 0; k < size; k++)
        {
            i += WaitingT[k];
            j += TurnaroundT[k];
        }
        cout<<i<<endl;
        cout<<"Processors\t Burst Time \t\t Arrival Time \t\t Waiting Time \t\t Turnaround Time "<<endl;

        for (int l = 0; l < size; l++)
        {
            cout <<"P"<<l+1<<"\t\t\t "<<BurstT[l]<<"\t\t\t "<<ArrivalT[l]<<"\t\t\t"<<WaitingT[l]<<"\t\t\t "<<TurnaroundT[l]<<endl;
        }

        cout<<endl;

        cout<<"Average waiting time is "<<i/size<<endl;
        cout<<"Average turn around time is "<<j/size<<endl;
    }
};

int main()
{
    int size;
    int BurstT[20] = {0};
    int ArrivalT[20] = {0};
    cout <<"Owner Ayan Hussain"<< endl<< "Number of processors : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Burst time of process " << i + 1 << " : ";
        cin >> BurstT[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Arrival time of process " << i + 1 << " : ";
        cin >> ArrivalT[i];
    }
    FCFS fcfs(size, BurstT,ArrivalT);
    fcfs.calWaitingTime();
    fcfs.calTurnAroundTime();
    fcfs.Print();

    return 0;
}

