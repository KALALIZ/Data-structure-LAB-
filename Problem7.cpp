//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
using namespace std;

void merge(int array[], int temp[], int left, int mid, int right)
{
    int i, left_end, num_elements, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    num_elements = right - left + 1;
    while((left <= left_end) and (mid <= right))
    {
        if(array[left] <= array[mid])
        {
            temp[temp_pos] = array[left];
            temp_pos = temp_pos + 1;
            left = left + 1;
        }
        else
        {
            temp[temp_pos] = array[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    while(left <= left_end)
    {
        temp[temp_pos] = array[left];
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    while(mid <= right)
    {
        temp[temp_pos] = array[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for(i = 0; i < num_elements; i++)
    {
        array[right] = temp[right];
        right = right - 1;
    }
}

void merge_sort(int array[], int temp[], int left, int right)
{
    int mid;
    if(right > left)
    {
        mid = (right + left)/2;
        merge_sort(array, temp, left, mid);
        merge_sort(array, temp, mid+1, right);
        merge(array, temp, left, mid+1, right);
    }
}

void Sort_by_desc(int array[], int n)
{
    int keep, run = n-1;
    if(n%2!=0) n+=1;
    {
        for(int i=0;i<((n/2));i++)
        {
            keep = array[i];
            array[i] = array[run];
            array[run] = keep;
            run--;
        }
    }
}

int binary_search(int array[], int size, int key)
{
    int low = 0;
    int hi = size - 1;
    int mid;

    while(low <= hi)
    {
        mid = (low + hi)/2;
        if(key == array[mid])
        {
            return (mid + 1);
        }
        else
        {
            if(key < array[mid])
            {
                hi = mid -1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return 0;
}

int binary_search1(int array[], int size, int key){
    int low = 0;
    int hi = size - 1;
    int mid;

    while(low <= hi)
    {
        mid = (low + hi)/2;
        if(key == array[mid])
        {
            return (mid + 1);
        }
        else
        {
            if(key < array[mid])
            {
                low = mid + 1;
            }
            else
            {
                hi = mid -1;
            }
        }
    }
    return 0;
}

int Sequential(int array[], int size, int key)
{
    int i = 0;
    while(i < size)
    {
      if(key == array[i])
      {
        return i+1;
      }
      else
      {
        i = i + 1;
      }
    }
    return 0;
}

int main()
{
   int i, j, n, data, input, bin, key;
   cin >> n;
   int array[(n+1)], temp[n+1], left = 0, right = n-1;
   array[(n+1)] = 0; 
   for(int i = 0; i < n; i++)
   {
       cin >> data;
       array[i] = data;
   }

   while(input != 4)
   {
       cin >> input;
       if(input == 1)
       {
           cin >> key;

           if(array[n+1] == 0)
           {
              bin = Sequential(array, n, key);
           }
           if(array[n+1] == 1)
           {
              bin = binary_search(array, n, key);
           }
           if(array[n+1] == 2)
           {
              bin = binary_search1(array, n, key);
           }
           if(bin == 0)
           {
              cout << "no" << endl;
           }
           else
           {
                cout << bin << endl;
           }
       }

       if(input == 2)
       {
           if(array[n+1] == 0 or array[n+1] == 2)
           {
               merge_sort(array, temp, left, right);
               array[n+1] = 1; 
           }
           for(i = 0; i < n; i++)
           {
               cout << array[i] << " ";
           }
           cout << endl;
       }
       if(input == 3)
       {
           if(array[n+1] == 0)
           {
               merge_sort(array, temp, left, right);
           }
           Sort_by_desc(array, n);
           array[n+1] = 2; 
           for(j = 0; j < n; j++)
           {
               cout << array[j] << " ";
           }
           cout << endl;
       }
   }
}
