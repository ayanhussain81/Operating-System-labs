#include <iostream>
using namespace std;

void CSCAN(int seq[], int size, int head, string direction)
{
    int seq1[size] = {0};
    int seq1_ptr = 0;
    int seq2[size] = {0};
    int seq2_ptr = 0;
    int seek_time = 0;
    int prev_head = head;

    for (int i = 0; i < size; i++)
    {
        if (seq[i] < head)
        {
            seq1[seq1_ptr] = seq[i];
            seq1_ptr++;
        }
        else
        {
            seq2[seq2_ptr] = seq[i];
            seq2_ptr++;
        }
    }

    if (direction == "r" || direction == "R")
    {
        cout << "The sequence is " << endl;
        for (int j = 0; j < seq2_ptr; j++)
        {
            int ind = 0;
            bool go = false;

            cout << head << endl;

            prev_head = head;
            for (int k = 0; k < seq2_ptr; k++)
            {
                if (seq2[k] == -1)
                {
                    continue;
                }
                else if (seq2[k] < head || go == false)
                {
                    head = seq2[k];
                    ind = k;
                    go = true;
                }
            }
            seek_time += head - prev_head;
            seq2[ind] = -1;
        }
        seek_time += 199 - head + 199;
        cout << head << endl;
        prev_head = 0;
        head = 0;
        for (int j = 0; j < seq1_ptr; j++)
        {
            int ind = 0;
            bool go = false;
            cout << head << endl;
            prev_head = head;
            for (int k = 0; k < seq1_ptr; k++)
            {
                if (seq1[k] == -1)
                {
                    continue;
                }
                else if (seq1[k] < head || go == false)
                {
                    head = seq1[k];
                    ind = k;
                    go = true;
                }
            }
            seek_time += head - prev_head;
            seq1[ind] = -1;
        }
        cout << head << endl;
    }
    else if(direction == "l" || direction == "L")
    {
        int comp;
        int ind = 0;
        
        cout << "The sequence is " << endl;
        for (int j = 0; j < seq1_ptr; j++)
        {
            for(int i=0; i<seq1_ptr ;i++){
                if(seq1[i]!=-1){
                    comp=seq1[i];
                    ind=i;
                    break;
                }
            }
            cout << head << endl;

            prev_head = head;
            for (int k = 0; k < seq1_ptr; k++)
            {
                if (seq1[k] == -1)
                {
                    continue;
                }
                else if (seq1[k] < head && seq1[k] >comp)
                {
                    comp=seq1[k];
                    ind = k;
                }
            }
            head=comp;
            seek_time +=prev_head- head;
            seq1[ind] = -1;
        }
        seek_time += head + 199;
        cout << head << endl;
        cout<<0<<endl;
        prev_head = 199;
        head = 199;
        for (int j = 0; j < seq2_ptr; j++)
        {
            for(int i=0; i<seq2_ptr ;i++){
                if(seq2[i]!=-1){
                    comp=seq2[i];
                    ind=i;
                    break;
                }
            }
            cout << head << endl;

            prev_head = head;
            for (int k = 0; k < seq2_ptr; k++)
            {
                if (seq2[k] == -1)
                {
                    continue;
                }
                else if (seq2[k] < head && seq2[k] >comp)
                {
                    comp=seq2[k];
                    ind = k;
                }
            }
            head=comp;
            seek_time += prev_head- head;
            seq2[ind] = -1;
        }
        
        cout << head << endl;
    }
    cout <<"The seek time is "<< seek_time;
}

int main()
{
    int size;
    int sequence[size];
    int head;
    string direction;
    cout << "Enter size of sequence : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " element : ";
        cin >> sequence[i];
    }
    cout << "Enter Head : ";
    cin >> head;
    cout << "Press l for left and r fpr right direction : ";
    cin >> direction;
    CSCAN(sequence, size, head, direction);
    return 0;
}
