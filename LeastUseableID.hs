{-- least useable ID:  
 -
 - Problem Definition:
 -   Given An non-negative integer Array A[1..n], find the least number that hasn't appeared in the array.
 -
 -   --}

import Data.List

minFree xs = bsearch xs 0 (length xs - 1)

bsearch xs l u | xs == [] = l
			   | length as == m-l+1 = bsearch bs (m+1) u
			   | otherwise = bsearch as l m
			   where m = (l+u) `div` 2
			         (as,bs) = partition (<=m) xs
