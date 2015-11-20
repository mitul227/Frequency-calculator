#include<stdio.h>
struct words           //an array of structure is defined to store each word of the file
{
    char a[20];
    int count;
}words[100000];
void main()
{
    FILE *f=NULL,*f2=NULL;
    int i=0,j=0,k,l,max;
    char b[20],filename[20],ch;
    printf("Enter the filename\n");
    scanf("%s",filename);
    f=fopen(filename,"r");
    f2=fopen("output.txt","w");
    if(f==NULL)
    {
        printf("File doesn't exist\n");
        exit(0);
    }
    else
    {
        ch=tolower(fgetc(f));  //tolower is used to convert every character to a lowercase letter
        while(ch!=EOF)
        {
            while(ch!=' '&&ch!='.'&&ch!=','&&ch!='!'&&ch!='('&&ch!=')'&&ch!=';'&&ch!=':'&&ch!='!'&&ch!='?'&&ch!='"'&&ch!=39&&ch!='\n'&&ch!=EOF)
            {
                words[i].a[j++]=ch;
                ch=tolower(fgetc(f));
            }
            words[i].a[j]='\0';
            i++;
            j=0;
            ch=tolower(fgetc(f));
        }
    }
    for(j=0;j<i;j++)
    {
        if(strcmp(words[j].a,"\0")!=0)
        {
            words[j].count=1;
            for(k=j+1;k<i;k++)
            {
                if(strcmp(words[j].a,words[k].a)==0)
                {
                    strcpy(words[k].a,"\0");    //Assigning value of '\0' eleminates the repetition of each word
                    words[j].count++;
                }
            }
        }
    }
    fprintf(f2,"               Word\t-\tFrequency\n");
    fprintf(f2,"               ----\t \t---------\n\n");
    for(k=0;k<i;k++)
    {
        if(strcmp(words[k].a,"\0")!=0)
        {
            for(l=0;l<i;l++)             //This loop finds the first word whose count is not zero
            {                             //and assigns the value of it's index to max
                if(words[l].count!=0)
                {
                    max=l;
                    break;
                }
            }
            for(j=0;j<i;j++)
            {
                if(words[j].count>words[max].count)
                max=j;
            }
            fprintf(f2,"%20s\t-\t%d\n",words[max].a,words[max].count);
            words[max].count=0;
        }
    }
}




