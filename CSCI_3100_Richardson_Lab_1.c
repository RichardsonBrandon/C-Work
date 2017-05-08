//++++++++++++++++++++++++++++++++++++++++++++++++++
// This program outputs the users' input to the screen
// one word per line.
// Author: Brandon Richardson
// Date: 1/29/15
// CSCI 3100 A - Spring 2015 - LA 1
//++++++++++++++++++++++++++++++++++++++++++++++++++
#include<stdio.h>

int main()
{
   int x;
   x = getchar();

   while (x != EOF)
   {
      if (x == ' ')
      {
         putchar('\n');
      }
      else
      {
         putchar(x);
      }
      x = getchar();
   }
   return 0;
}
