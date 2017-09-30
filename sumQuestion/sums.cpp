#include <iostream>
#include <map>
#include <stdio.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};

static void TwoSumTest( void )
{   
    int testInputLength = 10; 
    int testInput[10] = { 2, 7, 11, 15, 17, 18, 19, 55, 65, 85 };    
    int testTarget = 9;
    int *result;

    printArray( testInput, testInputLength );
    printf( " target: %i => ", testTarget);
    result = TwoSum( testInput, testInputLength, testTarget );
    printArray( result, 2 );
    printf( "\r\n");
}

int main()
{
    printf("Hello World!");
    
    TwoSumTest();

}