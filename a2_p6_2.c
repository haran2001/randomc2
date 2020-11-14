//linear search on Array of structures
struct Random
{
    char a[50];
    int b;
    char c[50][50];
};

struct Random xyz[500];
int LinearSearch()
{
int target, i, l, r, mid;
    l = 0;
    r = 14-1;
    printf("Type the number to e searched");
    scanf("%d", &target);


    for (i = 0; i < 500; i++)
        {
          if (xyz[i].b == target)
            return i;
          else
            printf("The target is not in the array.\n");
          }
    }
