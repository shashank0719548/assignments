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

    for(int i = 0;i < n;i++) {
        sum += pow(x,i);
    }

    printf("Sum of the series upto %d terms of value %d is:%d",n,x,sum);
}