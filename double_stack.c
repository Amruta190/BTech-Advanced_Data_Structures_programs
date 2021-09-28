#include <stdio.h>
#define max 10
int top1 = -1, top2 = max, arr[max];
void push1(int ele)
{
    if (top1 == top2 - 1)
        printf("Stack overflow\n");
    else
    {
        top1 += 1;
        arr[top1] = ele;
        printf("Element %d is pushed\n", ele);
    }
}
void push2(int ele)
{
    if (top1 == top2 - 1)
        printf("Stack overflow\n");
    else
    {
        top2 -= 1;
        arr[top2] = ele;
        printf("Element %d is pushed\n", ele);
    }
}
void pop1()
{
    if (top1 == -1)
        printf("Stack underflow\n");
    else
    {
        printf("Element %d is popped\n", arr[top1]);
        top1 -= 1;
    }
}
void pop2()
{
    if (top2 == max)
        printf("Stack underflow\n");
    else
    {
        printf("Element %d is popped\n", arr[top2]);
        top2 += 1;
    }
}
void peek1()
{
    if (top1 == -1 && top2 == max)
        printf("Stack empty\n");
    else
        printf("Peek element is %d", arr[top1]);
}
void peek2()
{
    if (top1 == -1 && top2 == max)
        printf("Stack empty\n");
    else
        printf("Peek element is %d", arr[top2]);
}
void print1()
{
    if (top1 == -1)
        printf("Stack empty\n");
    else
    {
        for (int i = top1; i >= 0; i--)
            printf("%d ", arr[i]);
        printf("\n");
    }
}
void print2()
{
    if (top1 == -1 && top2 == max)
        printf("Stack empty\n");
    else
    {
        for (int i = top2; i<max  ; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}
int main()
{
    int flag = 1;
    while (flag)
    {
        printf("1. Push\t2. Pop\t3. Peek\t4. Print\t5. Exit\n");
        printf("Select one option : ");
        int val, ele, val1;
        scanf("%d", &val1);
        switch (val1)
        {
        case 1:
        {
            printf("1. Stack-1\t2. Stack-2\n");
            printf("Select one option : ");
            scanf("%d", &val);
            printf("Enter the element : ");
            scanf("%d", &ele);
            switch (val)
            {  
            case 1:
                push1(ele);
                break;
            case 2:
                push2(ele);
                break;
            }
            break;
        }
        case 2:
        {
            printf("1. Stack-1\t2. Stack-2\n");
            printf("Select one option : ");
            scanf("%d", &val);
            switch (val)
            {
            case 1:
                pop1();
                break;
            case 2:
                pop2();
                break;
            }
            break;
        }
        case 3:
        {
            printf("1. Stack-1\t2. Stack-2\n");
            printf("Select one option : ");
            scanf("%d", &val);
            switch (val)
            {
            case 1:
                peek1();
                break;
            case 2:
                peek2();
                break;
            }
            break;
        }
        case 4:
        {
            printf("1. Stack-1\t2. Stack-2\n");
            printf("Select one option : ");
            scanf("%d", &val);
            switch (val)
            {
            case 1:
                print1();
                break;
            case 2:
                print2();
                break;
            }
            break;
        }
        case 5:
            flag = 0;
            break;
        }
    }
}