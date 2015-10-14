#include<stdio.h>
struct s
{
    char a[20];
}s[100000];
void main()
{
    FILE *f=NULL;
    int c=0,i=0,j=0,d[100000]={0},max,k,l;
    char ch,b[20];
    f=fopen("xyz.txt","r");
    if(f==NULL)
    {
        printf("File doesn't exist\n");
        exit(0);
    }
    else
    {
        while(fscanf(f,"%s",b)!=EOF)
        {
            strcpy(s[i].a,b);
            i++;
        }
    }
    for(j=0;j<i;j++)
    {
        c=1;
        if(strcmp(s[j].a,"\0")!=0)
        {
            for(k=j+1;k<i;k++)
            {
                if(strcmp(s[j].a,s[k].a)==0)
                {
                    strcpy(s[k].a,"\0");
                    c++;
                }
            }
            d[j]=c;
        }
    }
    c=0;
    for(k=0;k<j;k++)
    {
        if(d[k]>0)
        c++;
    }
    for(k=0;k<c;k++)
    {
        for(l=0;l<j;l++)
        {
            if(d[l]!=0)
            {
                max=l;
                break;
            }
        }
        for(l=0;l<j;l++)
        {
            if(d[l]>d[max])
            max=l;
        }
        printf("%s\t-\t%d\n",s[max].a,d[max]);
        d[max]=0;
    }
}

