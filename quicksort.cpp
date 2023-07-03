#include <iostream>
#include <stack>

int main()
{
    int n;
    std::cin >> n;
    int *mass = (int*) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        std::cin >> mass[i];
    }

    int i, j;
    int left = 0, right = n - 1;
    int pivot;

    std::stack <int> mystack;

    mystack.push(left);
    mystack.push(right);

    do
    {
        
        right = mystack.top();
        mystack.pop();
        left = mystack.top();
        mystack.pop();

        i = left;
        j = right;

        pivot = (i + j) / 2;

        do
        {
            while(mass[i] < mass[pivot])
            {
                i++;
            }
            while(mass[j] > mass[pivot])
            {
                j--;
            }

            if(i <= j)
            {
                int t;
                t = mass[i];
                mass[i] = mass[j];
                mass[j] = t;
                i++;
                j--;
            }
        } while (i <= j);

        if(left < j)
        {
            mystack.push(left);
            mystack.push(j);
            
        }

        if(i < right)
        {
            mystack.push(i);
            mystack.push(right);
            
        }


    } while (!mystack.empty());
    
    for(int i = 0; i < n; i++)
    {
        std::cout << mass[i] << " ";
    }

    free(mass);

    return 0;
}