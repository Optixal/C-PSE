/* c source file – p3t4util.c */ 
int lcm(int a, int b) { 
/*  utlitity function to return the 'least common multiple'
    value of two given number.     
    program logic: 
    Assume the worst case scenario : LCM of a and b is a * b.     let ans = a * b. 
            if a > b let x = a, y = b else let x = b, y = a. 
            let i = ans – x. 
            loop            
    if  i mod y == 0 let ans = i.     
    let i = i – x.
    until i < x.     
    return ans. 
*/ 
    int ans = a * b;     
    int x=a, y=b, i;     
    if (a < b) {        
        x=b;       
        y=a;     
    } 
    for (i= ans - x ;  i >= x ; i=i- x) {        
        /* look for a possible smaller answer. */        
        if (i % y == 0) {           
            ans = i;       
        }  
    } /* end for */  
    return ans; 
} 

