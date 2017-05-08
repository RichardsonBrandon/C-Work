//++++++++++++++++++++++++++++++++++++++++++++++++++
// This program will ask the user what operation they wish to perform
// using vectors and/or matrices, and then perform the operation chosen by
// the user. - Matrix Algebra
// Author: Brandon Richardson
// Date: 2/10/15
// CSCI 3100 A - Spring 2015 - LA 2
//++++++++++++++++++++++++++++++++++++++++++++++++++
#include <stdio.h>

char menu();
// This function will prompt the user with a menu giving the
// user the option to do a) Vector addition, b) Vector product,
// c) Vector inner product, d) Product Matrix Vector,
// e) Product Matrix Matrix, f) Transpose Matrix, and g) exit

char menu_cases();
//Runs the separate cases of the main menu (a, b, c, d, e, f, g)

double vector_addition();
// This function will perform vector addition using the users' input

double vector_product();
// This function will give the product of vectors entered by the user

double vector_inner_product();
// This function will give the product of the inner vectors entered by the
// user

double product_matrix_vector();
// This function will give the product of the vector and matrix entered by the
// user

double product_matrix_matrix();
// This function will give the product of the two matrices entered by the
// user

double transpose_matrix();
// This function will transpose the users' matrix

void exit();
// Exits the program

int main()
{
   menu_cases();

   return 0;
}

char menu_cases()
{
   char choice;

   do
   {
      choice = menu();

      switch(choice)
      {
        case 'a':
            vector_addition();
            break;

        case 'b':
            vector_product();
            break;

        case 'c':
            vector_inner_product();
            break;

        case 'd':
            product_matrix_vector();
            break;

        case 'e':
            product_matrix_matrix();
            break;

        case 'f':
            transpose_matrix();
            break;

        case 'g':
            printf("Goodbye.\n\n");
            break;

        default:
            printf("You have entered an invalid input. Valid inputs are \n a, b, c, d, e, f, or g\n");
            break;
      }
   } while (choice != 'g');
}

char menu()
{
   char choice;

   printf("\t\tMATRIX ALGEBRA PACKAGE\n\n\t\ta) VECTOR ADDITION\n\t\tb) VECTOR PRODUCT\n\t\t"
   "c) VECTOR INNER PRODUCT\n\t\td) PRODUCT MATRIX VECTOR\n\t\te) PRODUCT MATRIX MATRIX\n\t\t"
   "f) TRANSPOSE MATRIX\n\t\tg) EXIT\n\n\t\t Enter the index for the task you want to perform.\n\n");

   choice = getchar();

   while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd'
          && choice != 'e' && choice != 'f' && choice != 'g')
   {
      printf("Invalid input. Valid inputs are a, b, c, d, e, f, or g.\n\n");
      choice = getchar();
   }

   return choice;
}

double vector_addition()
{
   int e, x[100], y[100], z[100], a;

   printf("Enter the number of elements for your vectors (up to 100).\n");
   scanf("%d", &e);
   printf("Enter the elements of the first vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the x%d element: ", a + 1);
      scanf("%d", &x[a]);
   }

   printf("You entered: \n\n");

   for (a = 0; a < e; ++a)
   {
      printf("%d   ", x[a]);
      if (a == e - 1)
         printf("\n\n");
   }

   printf("Enter the elements of the second vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the y%d element: ", a + 1);
      scanf("%d", &y[a]);
   }

   for (a = 0; a < e; ++a)
   {
      z[a] = x[a] + y[a];
   }

   printf("The sum of the two vectors is: \n\n");

   for (a = 0; a < e; ++a)
   {
      printf("%d   ", z[a]);
      if (a == e - 1)
         printf("\n\n");
   }
}

double vector_product()
{
   int e, x[100], y[100], z[100], a;

   printf("Enter the number of elements for your vectors (up to 100).\n");
   scanf("%d", &e);
   printf("Enter the elements of the first vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the x%d element: ", a + 1);
      scanf("%d", &x[a]);
   }

   printf("Enter the elements of the second vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the y%d element: ", a + 1);
      scanf("%d", &y[a]);
   }

   for (a = 0; a < e; ++a)
   {
      z[a] = x[a] * y[a];
   }


   printf("The product of the two vectors is: \n\n");

   for (a = 0; a < e; ++a)
   {
      printf("%d   ", z[a]);
      if (a == e - 1)
         printf("\n\n");
   }
}

double vector_inner_product()
{
   int a, e, x[100], y[100];
   int inner_product = 0;

   printf("Enter the number of elements for your vectors (up to 100).\n");
   scanf("%d", &e);
   printf("Enter the elements of the first vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the x%d element: ", a + 1);
      scanf("%d", &x[a]);
   }

   printf("Enter the elements of the second vector.\n");

   for (a = 0; a < e; ++a)
   {
      printf("Enter the y%d element: ", a + 1);
      scanf("%d", &y[a]);
   }

   for (a = 0; a < e; a++)
   {
      inner_product += x[a] * y[a];
   }

   printf("Inner product = %d", inner_product);
}

double product_matrix_vector()
{
   int r, c, x[100][100], y[100], z[100][100], a, b;

   printf("Enter the number of rows up to 100.\n");
   scanf("%d", &r);
   printf("Enter the number of columns up to 100.\n");
   scanf("%d", &c);
   printf("Enter the elements of the matrix.\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("Enter the element x%d%d: ", a + 1, b + 1);
      scanf("%d", &x[a][b]);
   }

   printf("Enter the elements of the vector.\n");

   for (a = 0; a < c; ++a)
   {
      printf("Enter the %dnd element of y: ", a + 1);
      scanf("%d", &y[a]);
   }

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      z[a][b] = x[a][b] * y[a];
   }

   printf("The product of the matrix and vector is: \n\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("%d   ", z[a][b]);
      if (b == c - 1)
         printf("\n\n");
   }
}

double product_matrix_matrix()
{
   int r, c, x[100][100], y[100][100], z[100][100], a, b;

   printf("Enter the number of rows up to 100.\n");
   scanf("%d", &r);
   printf("Enter the number of columns up to 100.\n");
   scanf("%d", &c);
   printf("Enter the elements of the first matrix.\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("Enter the element x%d_%d: ", a + 1, b + 1);
      scanf("%d", &x[a][b]);
   }

   printf("Enter the elements of the second matrix.\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("Enter the element y%d_%d: ", a + 1, b + 1);
      scanf("%d", &y[a][b]);
   }

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      z[a][b] = x[a][b] * y[a][b];
   }

   printf("The product of the two matrices is: \n\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("%d   ", z[a][b]);
      if (b == c - 1)
         printf("\n\n");
   }
}

double transpose_matrix()
{
   int r, c, x[100][100], y[100][100], a, b;

   printf("Enter the number of rows up to 100.\n");
   scanf("%d", &r);
   printf("Enter the number of columns up to 100.\n");
   scanf("%d", &c);
   printf("Enter the elements of the first matrix.\n");

   for (a = 0; a < r; ++a)
      for (b = 0; b < c; ++b)
   {
      printf("Enter the element x%d_%d: ", a + 1, b + 1);
      scanf("%d", &x[a][b]);
   }

   for(a = 0; a < r; ++a)
      for(b = 0; b < c; ++b)
      {
         y[b][a] = x[a][b];
      }

   printf("Transpose of entered matrix :\n");

   for(a = 0; a < r; ++a)
   {
      for(b = 0; b < c; ++b)
      {
         printf("%d\t", y[a][b]);
      }
      printf("\n");
   }
}



