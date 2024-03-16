#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    sleep(5);
    char* a = "hello world\n";
    printf("%s",a);
    FILE* output = fopen("output.txt","w");
    fputs(a,output);
    fclose(output);
    return 0;
}