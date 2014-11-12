/*
title:
**********************************************************
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
**********************************************************	

ideas: use bitmap to solve the issue can be O(n) time and constant space. use bitmap[MAX] (MAX is the max number we can test) to hold the 
existence info of the integer array, use one pass to set the bitmap, and another one to test and return the value. function return -1 when no smallest one exist

bitmap in fact is an integer array, starting at 1.
use i / (INT_BITS*NUM_PER_BYTE) to get the index of the integer array
use 1 << (i % (INT_BITS*NUM_PER_BYTE)-1) to get the bit of integer set to 1
*/

#define INT_BITS sizeof(int)
#define NUM_PER_BYTE 8
#define MAX 1024 //max number

class Solution {

int bitmap[MAX / (NUM_PER_BYTE*INT_BITS)];

void setBitmap(int i) 
{
	bitmap[i / (INT_BITS*NUM_PER_BYTE)] |= 1 << ((i % (INT_BITS*NUM_PER_BYTE))-1);
}

int testBitMap(int i) 
{
	return bitmap[i / (INT_BITS*NUM_PER_BYTE)] & (1 << (i % (INT_BITS*NUM_PER_BYTE))-1);
}
public:
    int firstMissingPositive(int A[], int n) {
        
        for(int i=0; i < n; i++)
        {
            if(A[i] > 0)
            {
                setBitmap(A[i]);
            }
        }
        
        for(int i=0; i < MAX; i++)
        {
            if(testBitMap(i+1) == 0)
            {
                return i+1;
            }
        }
        
        return -1;
    }
};