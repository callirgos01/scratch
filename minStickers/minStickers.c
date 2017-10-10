/*
https://leetcode.com/problems/stickers-to-spell-word/description/

We are given N different types of stickers. 
Each sticker has a lowercase English word on it.
You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.
You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

# What is the minimum number of stickers that you need to spell out the target?  #
# If the task is impossible, return -1. #

Example 1:
Input:
            ["with", "example", "science"], "thehat"
Output:
            3
Explanation:
    We can use 2 "with" stickers, and 1 "example" sticker.
    After cutting and rearrange the letters of those stickers, we can form the target "thehat".
    Also, this is the minimum number of stickers necessary to form the target string.

Example 2:
Input:
    ["notice", "possible"], "basicbasic"
Output:
    -1
Explanation:
    We can't form the target "basicbasic" from cutting letters from the given stickers.

Note:
stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.
*/
#include <assert.h>
#include <stdio.h>

int minStickers(char** stickers, int stickersSize, char* target) {
    int i;
    int target_chars[30];
    int sticker_chars[30];

    printf("target %s[ ",target);
    while( *target )
    {
        printf("%c ",*target);        
        target_chars[((*target)-'a')]++;
        target++;
    }
    printf("]\r\n");

    for(i=0; i< stickersSize; i++)
    {
        printf("sticker %s[ ",stickers[i]);
        while( *stickers[i] )
        {
            printf("%c ",*stickers[i]);            
            sticker_chars[(*(stickers[i]))-'a']++;
            stickers[i]++;
        }
        printf("]\r\n");
    }
    
    //iterate through all strings.
        //per string check if any letter in the current string matches a letter in the target.
        //remove said letter from the target.
        //rerun the same string until there isn't a match.
    /*int j = 0;
    for(i=0; i< stickersSize;)
    {
        printf("checking %s\r\n",stickers[i]);
        char *check = stickers[i];
        char *this_target = target;
        while( check && this_target ) {
            if(*check == *this_target){
                j = 1;
            }
            check++;
            this_target++;
        }
        j = isThereAmatch(stickers[i],target);
        if( j == 0) {
            i++;
        }
    }
    printf("target %s\r\n",target);*/

    return 0;
}

int main( void ) {
    char *input[3] = { "with\0", "example\0", "science\0" };
    int output = 3;
    assert( minStickers(input, 3, "thehat\0") == output);

    printf("All Test Passed\r\n");
}