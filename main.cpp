#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(vector<int> nums);
int greatestCommonDivisor(vector<int> nums);
bool isSorted(vector<int> nums);

int main()
{
    //get the numbers from the user
    vector<int> numbers = getNumbers();

    //process the numbers and print results
    cout<<"Most frequent number: "<<findMostFrequentNumber(numbers)<<endl;
    
    cout<<"There are "<<numberGreaterThanAverage(numbers)<<" numbers greater than the average."<<endl;
    
    cout<<"The greatest common divisor is: "<<greatestCommonDivisor(numbers)<<endl;
    
    if(isSorted(numbers))
    {
        cout<<"The numbers are sorted."<<endl;
    }
    else
    {
        cout<<"The numbers are not sorted."<<endl;
    }

    return 0;
}
//--
vector<int> getNumbers()
{
    vector<int> nums;
    int num;
    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0)
    {
        nums.push_back(num);
    }
    return nums;
}
//--
int findMostFrequentNumber(vector<int> nums)
{
    // TODO: Student 1
    return -1;
}
//--
int numberGreaterThanAverage(vector<int> nums)
{
    // TODO: Student 2
    return 0;
}
//--
int greatestCommonDivisor(vector<int> nums)
{
    // TODO: Student 3

    //to hold unique divisors of each value in nums
    unordered_set<int> divisors;

    //edge case if vector has 1 value or is empty
    if (nums.size() == 1)
    {
        int retVal = 0;
        retVal = nums[0];
    }
    else if (nums.size() == 0)
    {
        cout << "No numbers to work with" << endl;
    }

    //traverse to get and store all possible divisors
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = nums[i]; j > 0; j--)
        {
            if (nums[i] % j == 0)
            {
                divisors.insert(j);
            }
        }
    }
    int retVal = 0;
    //identify largest universal divisor
    for (int num : divisors)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            //break if divisor doesn't go into the number evenly
            if (nums[i] % num != 0)
            {
                count++;
                break;
            }
        }
        if (count == 0 && num > retVal)
        {
            retVal = num;
        }
    }
    return retVal;
}
//--
bool isSorted(vector<int> nums)
{
    // TODO: Student 4
    return false;
}
