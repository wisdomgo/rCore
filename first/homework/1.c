#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
void List() 
{
    DIR* d;
    d = opendir("/home/wisdomgo/rCore/first/homework/");
    struct dirent* dir;
    if(d)
    {
        while((dir = readdir(d)) != NULL)
            printf("%s\n",dir->d_name);
    }
    closedir(d);
    return;
}
int main()
{
    List();
    return 0;
}