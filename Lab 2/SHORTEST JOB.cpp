#include <iostream>
#include <unordered_map>
using namespace std;

class ShortestJob
{
private:
    int size;
    int *BurstT;
    int *WaitngT;
    int *TurnaroundT;
;
    unordered_map<int, int> umap;

public:
    ShortestJob(int s, int *B)
    {
        size = s;
        BurstT = B;
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
            umap[BurstT[i]] = i+1;
        }

        int i = 0;
        int j = 0;
        bool swapped;
        for (i = 0; i < size - 1; i++)
        {
            swapped = false;
            for (j = 0; j < size - i - 1; j++)
            {
                if (BurstT[j] > BurstT[j + 1])
                {
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
        float i=0;float j = 0;
        for (int k = 0; k < size; k++)
        {
            i += WaitngT[k];
            j += TurnaroundT[k];
        }
        cout<<"Processors\t\t\t Burst Time \t\t Waiting Time \t\t Turnaround Time "<<endl;

        for (int l = 0; l < size; l++)
        {

            cout <<"process "<<umap.find(BurstT[l])->second<<"\t\t\t "<<BurstT[l]<<"\t\t\t "<<WaitngT[l]<<"\t\t\t "<<TurnaroundT[l]<<endl;
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
    cout <<"Owner Ayan Hussain" <<endl<< "Number of processors : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Burst time of process " << i + 1 << " : ";
        cin >> BurstT[i];
    }
    ShortestJob sj(size,BurstT);
    sj.calWaitingTime();
    sj.calTurnAroundTime();
    sj.Print();

    return 0;
}

