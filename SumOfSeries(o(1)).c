//sum of series 1 + x + x^2 + x^3...

#include<stdio.h>
#include<math.h>

int main() {
    int x,n,sum = 0;
    
    printf("For series 1 + x + x^2 + x^3...\n");
    printf("Enter x:");
    scanf("%d",&x);
    printf("Enter n value upto which the sum should be executed:");
    scanf("%d",&n);

    if(n == 1) {
        sum = 1;
        printf("Sum of the series upto %d terms of value %d is:%d",n,x,sum);
    } else if(n > 1) {
        sum = ((pow(x,n))) / (x - 1);
        printf("Sum of the series upto %d terms of value %d is:%d",n,x,sum);
    } else {
        printf("Sum of the series upto %d terms of value %d is:%d",n,x,sum);
    }
}