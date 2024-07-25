#include <iostream>

using namespace std;

// Function to calculate the sum of elements in a subset
int calculateSubsetSum(const int subset[], int subsetSize)
{
    int sum = 0;
    for (int i = 0; i < subsetSize; ++i)
    {
        sum += subset[i];
    }
    return sum;
}

// Function to print a subset
void printSubset(const int subset[], int subsetSize)
{
    cout << "{ ";
    for (int i = 0; i < subsetSize; ++i)
    {
        cout << subset[i] << " ";
    }
    cout << "}";
}

// Recursive function to generate all subsets
void generateSubsets(const int set[], int setSize, int currentIndex, int targetSum, int subset[], int subsetSize)
{
    if (currentIndex == setSize)
    {
        // Calculate the sum of the current subset
        int subsetSum = calculateSubsetSum(subset, subsetSize);
        // Check if the sum matches the target sum
        if (subsetSum == targetSum)
        {
            cout << "Subset with sum " << targetSum << " found: ";
            printSubset(subset, subsetSize);
            cout << endl;
        }
        return;
    }

    // Include the current element
    subset[subsetSize] = set[currentIndex];
    generateSubsets(set, setSize, currentIndex + 1, targetSum, subset, subsetSize + 1);

    // Exclude the current element
    generateSubsets(set, setSize, currentIndex + 1, targetSum, subset, subsetSize);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> set[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Define a maximum possible subset size (n is the maximum subset size)
    int subset[n];

    cout << "Finding subsets with sum " << targetSum << "..." << endl;
    generateSubsets(set, n, 0, targetSum, subset, 0);

    return 0;
}
