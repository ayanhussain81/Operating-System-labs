#include <iostream>
#include <unordered_map>
using namespace std;

class PriorityScheduling
{
private:
    int size;
    int *BurstT;
    int *Priority;
    int *WaitngT;
    int *TurnaroundT;
    unordered_map<int, int> umap;

public:
    PriorityScheduling(int s, int *B, int *P)
    {
        size = s;
        BurstT = B;
        Priority = P;
        WaitngT = new int[s];
        TurnaroundT = new int[s];
    }

    void swap(int *ab, int *cd)
    {
        int temp = *ab;
        *ab = *cd;
        *cd = temp;
    }

    void calWaitingTime()
    {
        for (int i = 0; i < size; i++)
        {
            umap[Priority[i]] = i;
        }

        int i = 0;
        int j = 0;
        bool swapped;
        for (i = 0; i < size - 1; i++)
        {
            swapped = false;
            for (j = 0; j < size - i - 1; j++)
            {
                if (Priority[j] > Priority[j + 1])
                {
                    swap(&Priority[j], &Priority[j + 1]);
                    swap(&BurstT[j], &BurstT[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }

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
            float i = 0;
            float j = 0;
            for (int k = 0; k < size; k++)
            {
                i += WaitngT[k];
                j += TurnaroundT[k];
            }
            cout << i << endl;
            cout << "Processors\t\t\t Burst Time \t\t Priority \t\t Waiting Time \t\t Turnaround Time " << endl;

            for (int l = 0; l < size; l++)
            {

                cout << "process" << umap.find(Priority[l])->second << "\t\t\t " << BurstT[l] << "\t\t\t "<<Priority[l]<<"\t\t\t" << WaitngT[l] << "\t\t\t " << TurnaroundT[l] << endl;
            }

            cout << endl;

            cout << "Average waiting time is " << i / size << endl;
            cout << "Average turn around time is " << j / size << endl;
    }
};

int main()
{
    int size;
    int BT[20] = {0};
    int Priority[20] = {0};
    cout << "Enter the number of processors : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> BT[i];
        cout << "Enter priority of process " << i + 1 << " : ";
        cin >> Priority[i];
    }
    PriorityScheduling ps(size, BT, Priority);
    ps.calWaitingTime();
    ps.calTurnAroundTime();
    ps.Print();
    return 0;
}
