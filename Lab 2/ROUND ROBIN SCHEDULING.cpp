#include <iostream>
using namespace std;

class RoundRobin
{
private:
    int size;
    int timeSlice;
    int *BursTurnaroundT;
    int *WaitingT;
    int *TurnaroundT;
    int *remainingBursTurnaroundT;

public:
    RoundRobin(int s, int *B, int ts)
    {
        size = s;
        BursTurnaroundT = B;
        remainingBursTurnaroundT = new int[s];
        timeSlice = ts;
        WaitingT = new int[s];
        TurnaroundT = new int[s];
    }

    void calWaitingTime()
    {

        for (int j = 0; j < size; j++)
        {
            remainingBursTurnaroundT[j] = BursTurnaroundT[j];
        }

        int t = 0;
        while (true)
        {
            bool isDone = false;

            for (int i = 0; i < size; i++)
            {
                if (remainingBursTurnaroundT[i] > 0)
                {
                    isDone = true;
                    if (remainingBursTurnaroundT[i] > timeSlice)
                    {
                        t += timeSlice;
                        remainingBursTurnaroundT[i] -= timeSlice;
                    }
                    else
                    {
                        t += remainingBursTurnaroundT[i];
                        remainingBursTurnaroundT[i] = 0;
                        WaitingT[i] = t - BursTurnaroundT[i];
                        // cout << t << "-" << BursTurnaroundT[i] << " = " << t - BursTurnaroundT[i] << endl;
                    }
                }
            }

            if (isDone == false)
            {
                break;
            }
        }
    }

    void calTurnAroundTime()
    {
        for (int i = 0; i < size; i++)
        {
            TurnaroundT[i] = WaitingT[i] + BursTurnaroundT[i];
        }
    }

    void Print()
    {
        float i = 0;
        float j = 0;
        for (int k = 0; k < size; k++)
        {
            i += WaitingT[k];
            j += TurnaroundT[k];
        }
        cout << "Processors\t\t\t Burst Time \t\t Waiting Time \t\t Turnaround Time " << endl;

        for (int l = 0; l < size; l++)
        {

            cout << "process" << l+1 << "\t\t\t " << BursTurnaroundT[l] << "\t\t\t " << WaitingT[l] << "\t\t\t " << TurnaroundT[l] << endl;
        }

        cout << endl;

        cout << "Average waiting time is " << i / size << endl;
        cout << "Average turn around time is " << j / size << endl;
    }
};


int main()
{
    int size;
    int timeSlice;
    cout << "Enter the time slice : ";
    cin >> timeSlice;
    int BursTurnaroundT[20] = {0};
    int Priority[20] = {0};
    cout << "Enter the number of processors : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> BursTurnaroundT[i];
    }

    RoundRobin rr(size, BursTurnaroundT, timeSlice);
    rr.calWaitingTime();
    rr.calTurnAroundTime();
    rr.Print();
    return 0;
}
