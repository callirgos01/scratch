#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static int* TwoSum(int* input, int inputLength, int target)
{
    bool success = false;
    int toReturnLength = sizeof(int)*2;
    int *toReturn = (int *)malloc(toReturnLength);
    memset( toReturn, 0, toReturnLength);
    
    //start index to return at 1 and 0
    //since the question says that the same value cant be used.
    //outer loop 
    //from index 0 to index length -2
    //inner loop
    //from index 1 to index length -1
    for(toReturn[0] = 0; toReturn[0]<inputLength -1; toReturn[0]++ )
    {
        for(toReturn[1] = toReturn[0] + 1; toReturn[1]<inputLength; toReturn[1]++)
        {
            if( (input[toReturn[0]] + input[toReturn[1]]) == target )
            {
                success = true;
                break;
            }
        }
        if( success == true )
        {
            break;
        }
    }

    return toReturn;
}

static void printArray( int* arrayToPrint, int arrayToPrintLength )
{
    int i;
    printf("[ ");
    for( i=0; i<arrayToPrintLength; i++ )
    {
        printf("%u ", arrayToPrint[i]);
    }
    printf("]");
}

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

int main( void )
{
    TwoSumTest();

    return 0;

}