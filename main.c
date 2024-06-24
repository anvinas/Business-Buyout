#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
typedef struct stack stack;

struct node
{
    int price;
    node * next;
};

struct stack
{
    node * head;
};

node * createNode(int value)
{
    //allocate
    node * res = (node *) malloc(sizeof(node));
    
    //set values
    res->price = value;
    res->next = NULL;

    //return
    return res;
}

node * insertHead(node * head, int price)
{
    //allocate
    node * newHead = createNode(price);

    if(head == NULL)//if empty
    {
        return newHead;
    }

    //return newHead
    newHead->next = head;
    return newHead;
}

node * removeHead(node *head)
{
    if (head == NULL)//check if emtpy
    {
        return NULL;
    }

    //return newHead
    node * newHead = head->next;
    return newHead;
}

stack * initStack()
{
    //allocate
    stack * res = (stack *) malloc(sizeof(stack));
    res->head = NULL;

    //return
    return res;
}

//insert val into stk
void push(stack * stk, int price)
{
    stk->head = insertHead(stk->head, price);
}

//remove from stk
void pop(stack * stk)
{
    if(stk->head != NULL)
    {
        stk->head = removeHead(stk->head);
    }
}

//look at top of stk
int top(stack * stk)
{
    if(stk && stk->head)
    {
        return stk->head->price;
    }
}

//sort an array
void mergeSort(int * arr, int len)
{
    //base case
    if(len <= 1)
    {
        return;
    }

    //split arr
    mergeSort(arr, len/2);
    mergeSort(arr + (len /2), len - (len / 2));

    //sort into temp arr
    int * tmp = (int *) malloc(sizeof(int) * len);
    int fptr = 0;
    int bptr = len / 2;
    for(int i = 0; i < len; i++)
    {
        if(fptr == len / 2 || (bptr != len && arr[bptr] < arr[fptr]))
        {
            tmp[i] = arr[bptr];
            bptr++;
        }
        else
        {
            tmp[i] = arr[fptr];
            fptr++;
        }
    }

    //put into og arr
    for(int i = 0; i < len; i++)
    {
        arr[i] = tmp[i];
    }
}

//update stk with values btw can afford
int updateStk(stack * stk, int arr[], int index, int shops, int wealth)
{
    int curIndex = index;
    while(shops > curIndex)
    {
        if(arr[curIndex] < wealth)
        {
            push(stk, arr[curIndex]);
            curIndex++;
        }
        else
        {
            break;
        }
    }


    return curIndex;
}

//simulates bts buying stores
int buyStore(stack * stk, int max, int wealth, int * count)
{
    if(stk->head == NULL)
    {
        (*count) = -1;
        return wealth;
    }

    wealth += top(stk);
    (*count)++;
    pop(stk);

    return wealth;
}

int main()
{
    //vars
    int shops, wealth, max;
    int curIndex = 0;
    int count = 0;
    stack * stk = initStack();

    //get vals
    scanf("%d %d", &shops, &wealth);

    int * arr = (int *) malloc(sizeof(int) * shops);

    for(int i = 0; i < shops; i++)
    {
        scanf("%d", &arr[i]);
    }

    //sort
    mergeSort(arr, shops);

    //shop to beat
    max = arr[shops - 1];


    while(wealth <= max)
    {
        //update stk and index that bts can afford
        curIndex = updateStk(stk, arr, curIndex, shops, wealth);

        //update wealth of bts
        
        wealth = buyStore(stk, max, wealth, &count);

        //if bts can't be richest
        if(count == -1)
        {
            break;
        }
    }

    //print results
    printf("%d\n", count);
    



    return 0;
}
