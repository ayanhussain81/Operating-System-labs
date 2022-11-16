#include <iostream>
using namespace std;
 
int main()
{
    int ArrivalT[10], BurstT[10], RemainingT[10], endTime, n, i, smallest, endtime, remain = 0, time;
    float avwt = 0, avat = 0;
 
    cout << "Total number of processes: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\nArrival time for process " << i + 1 << ": ";
        cin >> ArrivalT[i];
        cout << "Burst time for Process " << i + 1 << ": ";
        cin >> BurstT[i];
        RemainingT[i] = BurstT[i];
    }
    cout << "\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time";
    RemainingT[9] = 9999;
 
    for (time = 0; remain != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (ArrivalT[i] <= time && RemainingT[i] < RemainingT[smallest] && RemainingT[i] > 0) {
                smallest = i;
            }
        }
        RemainingT[smallest]--;
 
        if (RemainingT[smallest] == 0) {
            remain++;
            endtime = time + 1;
 
            cout << "\np[" << smallest + 1 << "]"
                 << "\t\t" << ArrivalT[smallest] << "\t\t" << BurstT[smallest] << "\t\t" << endtime - BurstT[smallest] - ArrivalT[smallest] << "\t\t" << endtime - ArrivalT[smallest];
 
            avwt += endtime - BurstT[smallest] - ArrivalT[smallest];
            avat += endtime - ArrivalT[smallest];
        }
    }
    avwt /= n;
    avat /= n;
    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avat;
 
    return 0;
}
