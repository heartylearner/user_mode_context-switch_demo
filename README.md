# user_mode_context-switch_demo
use set/longjmp to do 3 different tasks 
type "./main a b c d e"
a for input size of Reduce Integer(If a is odd -> a=a+1 else a=a/2, end when a=1)
b for input size of Mountain Climbing(Calculate how many ways to climb up a mountain for the height of b, with 1 or 2 step each time)
c for input size of OperationCount(Given an array arr of length c where arr[idx] = (2*idx)+323 for all valid indices, 0 <= idx < n.
                                 In each operation, you are allowed to choose two indices p and q where `0 <= p, q < n` and subtract 1 
                                 from arr[p] and add 1 to arr[q] (i.e. arr[p] -= 1 & arr[q] += 1). The goal is to make all the elements of the array equal.)
d for time interval between context switches 
e for switch mode(0:only by time;1:you can force it to switch by sending SIGTSTP to the process
