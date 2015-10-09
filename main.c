//
//  main.c
//  longestIncreasingSubsequence
//
//  Created by Randy Ram on 9/19/15.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef int bool;
enum { false, true };

int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}


int countDigits(int num)
{
    int count;
    while(num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int * onPositions (int binaryNum, int wordSize)
{
    printf("BinaryNum: %d\n", binaryNum);
    printf("Wordsize: %d\n", wordSize);
    int splitArray[wordSize];
    int i = 0, splitNum = binaryNum, lastDigit;
    while (splitNum != 0)
    {
        lastDigit = splitNum % 10;
        splitNum /= 10;
        splitArray[i] = lastDigit;
        i++;
    }
    int j;
    int numBitsOn = 0;
    printf("Split Array: ");
    for(j = 0; j < wordSize; j++)
    {
        printf("%d ", splitArray[j]);
        if (splitArray[j] == 1)
        {
            numBitsOn++;
        }
    }
    printf("\n");
    int onPos[numBitsOn];
    printf("NumBitsOn: %d\n", numBitsOn);
    int itr, k = 0;
    for(itr = 0; itr < wordSize; itr++)
    {
        if (splitArray[itr] == 1)
        {
            //printf("Iterator with 1: %d\n", itr);
            onPos[k] = itr;
            k++;
        }
    }
    int p;
    printf("onPosArray: ");
    for(p = 0; p < numBitsOn; p++)
    {
        printf("%d", onPos[p]);
    }
    printf("\n");
    printf("Size of onPos: %lu\n", sizeof(onPos)/ sizeof(onPos[0]));
    return onPos;
}

void longestIncreasing2N(int arr[], double size)
{
    double totalIterations = pow(2, size);
    double itr;
    int longestSubsequence = 0;
    int * numsInSubsequence;
    bool goodSubsequence = true;
    int binNum;
    for(itr = 1; itr < totalIterations; itr++)
    {
        binNum = decimal_binary(itr);
        int * placesToCheck = onPositions(binNum, countDigits(binNum));
        int i, k=1, test;
        int sizeOfPlacesToCheck = (sizeof(placesToCheck)/ sizeof(placesToCheck[0])) - 1;
        int numsAtIndex[sizeOfPlacesToCheck];
        numsAtIndex[0] = arr[placesToCheck[0]];
        if (itr == 4) {
            for(test = 0; test < sizeOfPlacesToCheck;test++)
            {
                printf("%d\n", placesToCheck[test]);
            }
        }
        
        for (i = 1; i < sizeOfPlacesToCheck; i++)
        {
            if (placesToCheck[i-1] > placesToCheck[i])
            {
                goodSubsequence = false;
                break;
            }
            else
            {
                numsAtIndex[k] = arr[placesToCheck[i]];
            }
        }
        
        if (goodSubsequence == true && sizeof(numsAtIndex) > longestSubsequence)
        {
            numsInSubsequence = numsAtIndex;
        }

    }
    //int m;
    /*for(m = 0; m < sizeof(numsInSubsequence)/sizeof(numsInSubsequence[0]); m++)
    {
        printf("%d\n", numsInSubsequence[m]);
    }*/
}

int main(int argc, const char * argv[]) {
    /*int arr[] = {-3, 5, 7, -8, -1, -2, 4, 9, -3, 2};
    double size = sizeof(arr)/ sizeof(arr[0]);
    longestIncreasing2N(arr, size);
    int dec = decimal_binary(4);
    printf("Binary: %d\n", dec);
    int * onPos = onPositions(dec, countDigits(dec));
    int onPosSize = sizeof(onPos)/sizeof(onPos[0]) - 1;
    printf("onPosSize: %d\n", onPosSize);
    int l;
    for(l = 0 ; l < onPosSize; l++)
    {
        printf("%d ", onPos[l]);
    }*/
    printf("DecBin: %d\n", decimal_binary(1));
    printf("Countdigits: %d\n", countDigits(decimal_binary(1)));

}
