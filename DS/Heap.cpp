#include <iostream>
#include <algorithm>
#include <vector>

class Heap
{
public:
    std::vector<int> data;

    Heap(void)
    {
        // Initialize, to push a 0 in, let the index starts with 1
        data.push_back(0);
    }

    // print out all data in heap
    void all(void)
    {
        for (int i = 0; i < data.size(); i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    // add element into heap
    void add(int num)
    {
        // push data in        
        data.push_back(num);
        int index = data.size() - 1;

        // and "challenge" their parents until fail or become the first index
        while (index > 1)
        {

            // find parent index
            int parent = (int)index / 2;

            // "challenging"
            if (data[index] > data[parent])
            {
                std::swap(data[index], data[parent]);
                index = parent;
                continue;
            }

            // if fail, break
            break;
        }
    }

    // delete maximum in heap
    void deleteMax(void)
    {
        // replace maximum with the last element, and, remove the last
        data[1] = data.back();
        data.pop_back();

        // set index for iterative comparing, adjust to a Maximum-Heap structure
        int current = 1, compare, size = data.size();
        while (current < size)
        {
            // index of child is 2*current and 2*current+1
            compare = 2 * current;
            if (compare < size && compare + 1 < size)
            {
                // the condition of two children and parent
                if (data[compare] > data[compare + 1] && data[compare] > data[current])
                {
                    std::swap(data[compare], data[current]);
                    current = compare;
                    continue;
                }
                else if (data[compare] < data[compare + 1] && data[compare + 1] > data[current])
                {
                    std::swap(data[compare + 1], data[current]);
                    current = compare + 1;
                    continue;
                }
            }
            else if (compare < data.size())
            {
                // the condition of there is only left child.
                /*
                 Note that this is a Heap, as a Complete Binary Tree, the condition of 
                 having right child without having left child must not exist.
                */
                if (data[compare] > data[current])
                {
                    std::swap(data[compare], data[current]);
                    current = compare;
                    continue;
                }
            }
            break;
        }
    }

    int findMax(void)
    {
        // return maximum
        return data[1];
    }
};

int main(void)
{
    Heap heap = Heap();
    heap.add(10);
    heap.add(2);
    heap.add(7);
    heap.add(5);
    heap.add(3);

    heap.add(8);
    heap.add(12);
    heap.add(15);
    heap.add(30);

    heap.all();

    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.deleteMax();
    heap.all();

    return 0;
}