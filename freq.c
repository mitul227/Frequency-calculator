#include<stdio.h>
struct s           //an array of structure is defined to store each word of the file
{
    char a[20];
    int count;
}s[100000];
void main()
{
    FILE *f=NULL;
    int i=0,j=0,k,l,max;
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
            l=strlen(b);
            for(j=0;j<l;j++)
            b[j]=tolower(b[j]);
            strcpy(s[i].a,b);
            i++;
        }
    }
    for(j=0;j<i;j++)
    {
        if(strcmp(s[j].a,"\0")!=0)
        {
            s[j].count=1;
            for(k=j+1;k<i;k++)
            {
                if(strcmp(s[j].a,s[k].a)==0)
                {
                    strcpy(s[k].a,"\0");
                    s[j].count++;
                }
            }
        }
    }
    for(k=0;k<i;k++)
    {
        if(strcmp(s[k].a,"\0")!=0)
        {
            for(l=0;l<i;l++)
            {
                if(s[l].count!=0)
                {
                    max=l;
                    break;
                }
            }
            for(j=0;j<i;j++)
            {
                if(s[j].count>s[max].count)
                max=j;
            }
            printf("%20s\t-\t%d\n",s[max].a,s[max].count);
            s[max].count=0;
        }
    }
}



