#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
  
  
  int Password()
{
//declare local variables//
char cPassCode[] = "String";
int iFlag=0, iComparison = 0;

//Run the code to check the password//
while (iFlag == 0)
{
    printf("Please enter the password: ");
    scanf("%s", cPassCode);
    iComparison = strcmp(cPassCode,"A23bc5");
    if (iComparison == 0)
    {
        printf("\n Accepted\n");
        iFlag = 1;
    }
    else
    {
        printf("Wrong password\n");
        iFlag = 0;
    }
    return(iFlag);
}
}

int main()
{


 Password();

 return 0;
}
