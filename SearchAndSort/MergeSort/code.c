void MergeSort(int a[],int l,int r)//Sorting after dividing
{
    if(l>=r)
    return;
    int mid=(l+r)/2;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);

    int temp [r-l+1];
    int p1=l,p2=mid+1;
    int c=0;
    while(p1<=mid && p2<=r)
    {
        if(a[p1]<=a[p2])
        temp[c++]=a[p1++];
        else if(a[p1]>a[p2])
        temp[c++]=a[p2++];
    }
    while(p1<=mid)
    {
        temp[c++]=a[p1++];
    }
    while(p2<=r)
    {
        temp[c++]=a[p2++];
    }
    for(int i=l;i<=r;i++)
    a[i]=temp[i-l];
}