//Best case is O(nlogn)  but average case is O(n^2)
void QuickSort(int a[],int l,int r)//Sorting before dividing
{
    if(l>=r)
    return;

/* NO USE as it is not reducing space complexity
    int pivot =a[r];
    int s=0,lc=0;
    int small[1000],large[1000],temp[10000];
    for(int i=l;i<r;i++)
    {
        if(a[i]<pivot)
        {
            small[s++]=a[i];
        }
        if(a[i]>pivot)
        {
            large[lc++]=a[i];
        }
    }
    for(int i=0;i<s;i++)
    temp[i]=small[i];

    temp[s]=pivot;

    for(int i=0;i<lc;i++)
    temp[i+s+1]=large[i];

    for(int i=l;i<=r;i++)
    a[i]=temp[i-l];

    */

    int pivot = a[r];
    int part=l;//Consider lth position to be the desired position such that no elements behind it
    for(int j=l;j<r;j++)
    {
        if(a[j]<pivot)//we encountered an element  that should be  behind the part
        {
            
            int temp=a[part];// move that element to the left section of part
            a[part]=a[j];
            a[j]=temp;
            part++;// new position of part
        }
        int temp=a[r];
        a[r]=a[part];
        a[part]=temp;

    }


    /*int p1=l,p2=r;
    while(p1<p2)
    {
        while(a[p1]<a[l])
        {
            p1++;
        }
        
        while(a[p2]>a[l])
        {
            p2--;
        }
        int temp=a[p1];
        a[p1]=a[p2];
        a[p2]=temp;

    }
    int temp=a[l];
    a[l]=a[p2];
    a[p2]=a[l];*/

    QuickSort(a,l,part-1);
    QuickSort(a,part+1,r);
}
