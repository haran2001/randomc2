//binary search on an array of structures 
struct Random
{
    char a[50];
    int b;
    char c[50][50];
};

struct Random xyz[500];
int BinarySearch()
{
int target, i, l, r, mid;
    l = 0;
    r = 14-1;
    printf("Type the number to e searched");
    scanf("%d", &target);

    while(l <= r)
    {
        mid = (l+r)/2;
        if(xyz[mid].b == target)
        {
            printf("\n%s",xyz[mid].b);
            break;
        }
        else if (xyz[mid].b < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;

        }

        if(l > r)
            printf("The target is not in the array.\n");

    }
