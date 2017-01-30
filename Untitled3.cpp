#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fact(int z)
{
	int flag=1;
	while(z>0)
	{
		flag=flag*z;
		z--;
	}
	return flag;
}

float** allocate(int m,int n) 
{
  int i;
  float** ptr;
  ptr=(float**)malloc(sizeof(float*)*m);
  for(i=0;i<m;i++)
    {  
      ptr[i]=(float*)malloc(sizeof(float)*n);
    }
  if(ptr==NULL)
    {
      printf("Cannot allocate the memory.\n");
      exit(0);
    }
  return ptr;
}

void read(float** temp,int m,int n)
{
  int i,j;
  printf("Enter the list of numbers?\n");
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
          scanf("%f",&temp[i][j]);
	}
    } 
  printf("\n");
}

void print(float** temp,int m,int n)
{
  int i,j;
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	printf("%f\t",temp[i][j]);
      printf("\n");
    }
}
 
void free2D(float** temp,int m)
{
  int i;
  for(i=0;i<m;i++)
    {
      free(temp[i]);
    }
  free(temp);
}

void trace(float** temp,int m,int n)
{
  float sum=0.0;
  int i,j;
  if(m==n)
  {
    for(i=0;i<m;i++)
      {
        for(j=0;j<n;j++)
	  {
	    if(i==j)
	      {
		sum=sum+temp[i][j];
              }
          }
      }
    printf("The trace of the matrix is:%f\n",sum);
  }
  else
  {
    printf("The trace can't be calculated.\n");
  }
}

float** multiplication(float** temp,float** flag,int p,int q,int r,int s)
{
  int i,j,k;
  float sum=0.0;
  float** a=allocate(p,s);
  if(q==r)
  {
    for(i=0;i<p;i++)
      {
	for(j=0;j<s;j++)
	  {
              sum=0.0;
	    for(k=0;k<r;k++)
	      sum=sum+temp[i][k]*flag[k][j];
	      a[i][j]=sum;
          }
      }
    return a;
  }
  else
  {
    return NULL;
  }
}

float** addition(float** temp,float** flag,int p,int q,int r,int s)
{
  int i,j;
  float sum=0.0;
  float** a=allocate(p,s);
  if(p==q && r==s)
  {
    for(i=0;i<p;i++)
    {
	 for(j=0;j<s;j++)
	  {
          sum=0.0;
	      sum=sum+temp[i][j]+flag[i][j];
	      a[i][j]=sum;
      }
    }
    return a;
  }
  else
  {
    return NULL;
  }
}

float** subtraction(float** temp,float** flag,int p,int q,int r,int s)
{
  int i,j;
  float sum=0.0;
  float** a=allocate(p,s);
  if(p==q && r==s)
  {
    for(i=0;i<p;i++)
      {
	    for(j=0;j<s;j++)
	    {
           sum=0.0;
	       sum=sum+temp[i][j]-flag[i][j];
	       a[i][j]=sum;
        }
      }
    return a;
  }
  else
  {
    return NULL;
  }
}
int main()
{
	float a,b;
	int temp,i,k,l,m;
	float result,j;
	double x,y;
	char ch;
  do
  {	
	printf("Enter two real numbers on which you want operations?\n");
	scanf("%f %f",&a,&b);
	printf("Enter the number corresponding to operation of your choice?\n");
	printf("Enter 1 for addition.\n");
	printf("Enter 2 for subtraction.\n");
	printf("Enter 3 for multiplication.\n");
	printf("Enter 4 for division.\n");
	printf("Enter 5 for logarithm.\n");
	printf("Enter 6 for exponent.\n");
	printf("Enter 7 for sine.\n");
	printf("Enter 8 for cosine.\n");
	printf("Enter 9 for tangent.\n");
	printf("Enter 10 for square root calculation.\n");
	printf("Enter 11 to calculate x to the power y.\n");
	printf("Enter 12 to calculate factorial of a number?\n");
	printf("Enter 13 to calculate nPr?\n");
	printf("Enter 14 to calculate nCr?\n");
	printf("Enter 15 to calculate modulas?\n");
	printf("Enter 16 for matrix calculation.\n");
	printf("Enter 17 to end the program.\n");
	scanf("%d",&temp);
	switch(temp)
	{
		case 1:{
			      result=a+b;
		          printf("The answer is %f\n",result);
		          break;
		       }
	    case 2:{
			      result=a-b;
	    	      printf("The answer is %f\n",result);
			      break;
               }
	    case 3:{
			      result=a*b;
	    	      printf("The answer is %f\n",result);
			      break;
               }	
	    case 4:{
	    	      if(b==0)
	    	      printf("Number can not be divided by 0\n");
	    	      else
	    	      {
			        result=a/b;
	    	        printf("The answer is %f\n",result);
			        break;
			      }
               }
	    case 5:{
	    	      printf("The logarithm of one number is %f\n",log(a));
	    	      printf("The logarithm of second number is %f\n",log(b));
			      break;
               }               
	    case 6:{
			      x=(double)a;
			      y=(double)b;
	    	      printf("The exponential of one number is %lf\n",exp(x));
	    	      printf("The exponential of second number is %lf\n",exp(y));
			      break;
               }               
 	    case 7:{
			      x=(double)a;
			      y=(double)b;
	    	      printf("The sine of one number is %lf\n",sin(x));
	    	      printf("The sine of second number is %lf\n",sin(y));
	    	      break;
               }              
 	    case 8:{
			      x=(double)a;
			      y=(double)b;
	    	      printf("The cosine of one number is %lf\n",cos(x));
	    	      printf("The cosine of second number is %lf\n",cos(y));
			      break;
               }              
  	    case 9:{
			      x=(double)a;
			      y=(double)b;
	    	      printf("The tangent of one number is %lf\n",tan(x));
	    	      printf("The tangent of second number is %lf\n",tan(y));
			      break;
               }             
 	    case 10:{
		          printf("The square root of one number is %f\n",sqrt(a));
	    	      printf("The square root of second number is %f\n",sqrt(b));
			      break;
	    	    }              
  	    case 11:{
  	    	      j=a;
			      for(i=0;i<b-1;i++)
			      {
			      	j=j*a;
			      }
	    	      printf("The answer is %f\n",j);
			      break;
               }             
    	case 12:{
			      printf("To calculate factorial , the given number is coverted into integer.\n");
			      k=(int)a;
			      l=(int)b;
			      printf("The factorial of one number is %d\n",fact(k));
	    	      printf("The factorial of second number is %d\n",fact(l));
			      break;
               }           
  	    case 13:{
			      if(a>b)
                  {  
                     printf("To calculate nPr , the given numbers are coverted into integer.\n");
                     k=(int)a;
			         l=(int)b;
					 result=fact(a)/fact(a-b);
					 printf("The answer is %f\n",result);
			         break; 
			      }
				  else
				  {
				  	printf("Cannot be calculated\n");
				  	break;
				  }
			              
                }
        case 14:{
			      if(a>b)
                  {
				     printf("To calculate nCr , the given numbers are coverted into integer.\n");
                     k=(int)a;
			         l=(int)b;
					 result=fact(a)/(fact(a-b)*fact(b));
					 printf("The answer is %f\n",result);
			         break; 
			      }
				  else
				  {
				  	printf("Cannot be calculated\n");
				  	break;
				  }
			              
                }      
        case 15:{
        	      if(b==0)
	    	         printf("Number can not be divided by 0\n");
	    	      else
	    	      {
				     printf("To calculate modulas , the given numbers are coverted into integer.\n");
                     k=(int)a;
			         l=(int)b;
			        int f=k%l;
	    	        printf("The answer is %d\n",f);
			        break;
			      }
		        }
        case 16:{
        	      int r1,r2,c1,c2;
                  printf("Enter row of first matrix?\n");
                  scanf("%d",&r1);
                  printf("Enter row of second matrix?\n");
                  scanf("%d",&r2);
                  printf("Enter column of first matrix?\n");
                  scanf("%d",&c1);
                  printf("Enter column of second matrix?\n");
                  scanf("%d",&c2);
                  if(r1<0 || r2<0 || c1<0 || c2<0)
                  {  
                     printf("Enter valid value.....\n");
                     return 0;
                  }
                  float** b=allocate(r1,c1); 
                  float** c=allocate(r2,c2);
                  read(b,r1,c1);
                  read(c,r2,c2);
                  printf("Matrix 1\n");
                  print(b,r1,c1);
                  printf("\n");
                  printf("Matrix 2\n");
                  print(c,r2,c2);
				  int dec; 
                  printf("Enter 1 for addition of matrix.\n");
	              printf("Enter 2 for subtraction of matrix.\n");
	              printf("Enter 3 for multiplication.\n");
		          printf("Enter 4 for computation of trace.\n");
	              printf("Enter 5 to free the allocated space.\n");
	              scanf("%d",&dec);
	              switch(dec)
	              {
	              	case 1:{
	              		       float** d=addition(b,c,r1,r2,c1,c2);
                               if(d==NULL)
                               {
                                  printf("Addition can't be performed.\n");
                               }
                               else
                               {
                                  printf("The matrix after addition is\n");
                                  print(d,r1,c2);
                                }
						      break;
					       } 
					case 2:{
						       float** d=subtraction(b,c,r1,r2,c1,c2);
                               if(d==NULL)
                               {
                                  printf("Subtractioncan't be performed.\n");
                               }
                               else
                               {
                                  printf("The matrix after subtraction is\n");
                                  print(d,r1,c2);
                                }
						        break;
					       }  
					case 3:{
						        float** d=multiplication(b,c,r1,r2,c1,c2);
                                if(d==NULL)
                                {
                                   printf("Multiplication can't be performed.\n");
                                }
                                else
                                {
                                   printf("The matrix after multiplication is\n");
                                   print(d,r1,c2);
                                }
						        break;
					       }
					case 4:{
						        printf("Matrix 1\n");
                                trace(b,r1,c1);
                                printf("Matrix 2\n");
                                trace(c,r2,c2);
						        break;
					       }
					case 5:{
						        free2D(b,r1);
                                free2D(c,r2);
						        break;
					       }
					default:{
						        printf("Please enter valid value...\n");
						        break;
					        }
				  }
				  break;
			    }
		case 17:{
			        printf("Thank you for using this calculator app...\n");
			        exit(0);
			        break;
		        }
		default:{
			        printf("Please Enter valid value......\n");
			        break;
		        }
		        
	}
    printf("Want to enter more...(Press y for yes and n for no)\n");
    scanf("%c",&ch);
  }while(ch=='y');
  return 0;
}
               
               
               
               
               
               
               
               
               
               
               
               
