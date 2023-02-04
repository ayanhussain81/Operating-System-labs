#include <iostream>
#include <cstdlib>

using namespace std;

int size;

void LOOK(int arr[], int head, char direction)
{
    int seek_time = 0;
    int left[size] = {0};
    int right[size] = {0};
    int lindex = 0;
    int rindex = 0;
    for (int i = 0; i < size; i++)
    {
        if (head < arr[i])
        {
            right[rindex] = arr[i];
            rindex++;
        }
        else
        {
            left[lindex] = arr[i];
            lindex++;
        }
    }

    if (direction == 'r' || direction == 'R')
    {

        for (int i = 0; i < rindex; i++)
        {
            int current_element = -1;
            int index = -1;
            std::cout << head << std::endl;
            for (int j = 0; j < rindex; j++)
            {
                if (right[j] == -1)
                {
                    continue;
                }
                else
                {
                    if (current_element == -1 || current_element > right[j])
                    {
                        current_element = right[j];
                        index = j;
                    }
                }
            }
            seek_time += abs(current_element - head);
            head = current_element;
            right[index] = -1;
        }

        // Traversing left
        for (int i = 0; i < lindex; i++)
        {
            int current_element = -1;
            int index = -1;
            std::cout << head << std::endl;
            for (int j = 0; j < lindex; j++)
            {
                if (left[j] == -1)
                {
                    continue;
                }
                else
                {
                    if (current_element == -1 || current_element < left[j])
                    {
                        current_element = left[j];
                        index = j;
                    }
                }
            }
            seek_time += abs(current_element - head);
            head = current_element;
            left[index] = -1;
        }
        cout << head << endl;
    }

    else
    {
        // Traversing left
        for (int i = 0; i < lindex; i++)
        {
            int current_element = -1;
            int index = -1;
            std::cout << head << std::endl;
            for (int j = 0; j < lindex; j++)
            {
                if (left[j] == -1)
                {
                    continue;
                }
                else
                {
                    if (current_element == -1 || current_element < left[j])
                    {
                        current_element = left[j];
                        index = j;
                    }
                }
            }
            seek_time += abs(current_element - head);
            head = current_element;
            left[index] = -1;
        }

        for (int i = 0; i < rindex; i++)
        {
            int current_element = -1;
            int index = -1;
            std::cout << head << std::endl;
            for (int j = 0; j < rindex; j++)
            {
                if (right[j] == -1)
                {
                    continue;
                }
                else
                {
                    if (current_element == -1 || current_element > right[j])
                    {
                        current_element = right[j];
                        index = j;
                    }
                }
            }
            seek_time += abs(current_element - head);
            head = current_element;
            right[index] = -1;
        }

        cout << head << endl;
    }

    cout << "Seek time is: " << seek_time;
}

int main()
{
    cout << "Enter size: ";
    cin >> size;

    int arr[size];
    int head;
    char direction;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Sequence " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter head: ";
    cin >> head;

    cout << "Press l for left direction and r for right direction: ";
    cin >> direction;

    LOOK(arr, head, direction);

    return 0;
}
