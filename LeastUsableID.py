'''
    Problem Definition:
        Given An non-negative integer Array A[1..n], find the least number that hasn't appeared in the array.
'''

def partition (A, l, u, v):
    '''
    split the array a into 2 groups, first is all elements less equal to v, the others are greater than v
    A: the integer array
    l, u: the low and high index of the array, inclusive
    v: the value to split the array
    return: -1 when has error otherwise the index of the split point
    '''
    if l > u or l < 0 or u < 0:
    	raise Exception("partition: l and u should be greater than 0 and u >= l") 

    while True:
        while (A[l] <= v):
            if l == u:
                if A[l] <= v:
                    return l
                else:
                    return l-1
            l = l + 1

        while (A[u] > v):
            if l == u:
                if A[u] > v:
                    return u-1
                else:
                    return u
            u = u - 1

        tmp = A[l]
        A[l] = A[u]
        A[u] = tmp

def recursiveFindMinID(A, l, u):
    '''
    A: the non-negative integrate array
    l, u: low and high index of the array to look for least id, inclusive
    '''
    m = int((l+u)/2)

    if l > u:
        return l

    i = partition(A, l, u, m)

    if i - l + 1 <= 0:
        return l

    if (i-l+1 < (m-l+1)):
        return recursiveFindMinID(A, l, m)
    else:
        return recursiveFindMinID(A, m+1, u)

def findMinID(A):
    return recursiveFindMinID(A, 0, len(A)-1)


if __name__ == "__main__":
    print(findMinID([0, 10 ,3]))
