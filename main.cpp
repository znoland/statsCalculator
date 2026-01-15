#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumbers();
int findMostFrequentNumber(vector<int> nums);
int numberGreaterThanAverage(vector<int> nums);
int greatestCommonDivisor(vector<int> nums);
bool isSorted(vector<int> nums);
bool isSortedLuke(const vector<int>& nums);

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

    if(isSortedLuke(numbers))
    {
        cout<<"The numbers are sorted. [Luke]"<<endl;
    }
    else
    {
        cout<<"The numbers are not sorted. [Luke]"<<endl;
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
    //make sure there are no issues if the vector is empty
    if(nums.empty()){
        return -1;
    }

    int mostFrequent = nums[0];
    size_t maxCount = 0;

    //Loop through each element in the vector
    for (size_t i = 0; i < nums.size(); i++) {
        size_t count = 0;

        //compare nums[i] with every element
        for (size_t j = 0; j < nums.size(); j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }

        //update mostFrequent value if a higher count is found
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = nums[i];
        }
    }

    return mostFrequent;
}
//--
int numberGreaterThanAverage(vector<int> nums)
{
    // TODO: Student
    //Check if the vector is empty
    if (nums.empty())
    {
        cout << "Error: The list of numbers is empty." << endl;
        return 0;
    }
    //calculate avg
    double average = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        average = average + nums[i];
    }
    average = average / nums.size();

    //count nums greater than the avg
    int countGreaterThanAvg = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > average)
        {
            countGreaterThanAvg++;
        }
    }

    //return total numbers greater than the avg
    return countGreaterThanAvg;
}
//--
int greatestCommonDivisor(vector<int> nums)
{
    // TODO: Student 3
    return 1;
}
//--
bool isSorted(vector<int> nums)
{
    // TODO: Student 4
    bool numsIsSorted = true;

    if(nums.size() <= 1)//handles if vector is empty or only has one item
    {
        return false;
    } 
    
    for(int i = 0; i < nums.size() - 1; i++) //checks if vector is sorted least to most
    {
        if(nums[i] >= nums[i + 1]) 
        {
            numsIsSorted = false;
            break;
        }
    }

    if(numsIsSorted == false)
    {
        for(int i = 0; i < nums.size() - 1; i++) //checks if vector is sorted most to least
        {
            if(nums[i] <= nums[i + 1])
            {
                numsIsSorted = false;
                break;
            }
        }
    }
    
    return numsIsSorted;
}
//--
bool isSortedLuke(const vector<int>& nums)
{
    bool ascending = true;
    bool descending = true;

    // handle edge case
    if (nums.size() <= 1)
    {
        return true;
    }
    
    // loop to check both conditions
    // unsigned size_t to avoid comparison between signed and unsigned
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            ascending = false;  // is not ascending if previous > current
        }
        if (nums[i - 1] < nums[i])
        {
            descending = false; // is not descending if previous < current
        }
    }
    return ascending || descending;
}