/**
 ---------------------------HOW IT WORKS-------------------------------------
    written by HITKUL
 1. Sort both the arrays.
 2. Now multiply the smallest element of 1st array with the largest of 2nd,and keep on 
 	multiplying elements in the similar fashion.
 3. In this way the scalar product obtained will be the min.

 This is so because when u multiply smallest and the largest element then the obtained product 
 is min possible, when we apply same method to each term in vectors each term obtained is min 
 so there sum lead to min scalar product.

 **/

 #include "stdio.h"

// scan elements of an array
 void input(float *array,int no_of_element);
 // assign zero to the blank memory spaces of an array
 void assign_zeroes(float *array,int size,int existing_no_of_elements);
// sort array using the bubble sort algorithm
 void bubble_sort(float *array,int no_of_element);
// swap two elements  
 void swap(float *array1,float *array2);
// compute scalar product of two arrays
 float scalar_product(float *array1, float *array2, int no_of_element);

 int main()
 {
 	int i,no_of_element_in_vector1,no_of_element_in_vector2,no_of_element;
 	
 	//asking for the size of vectors
 	printf("Enter number of elements in first vector==>");
 	scanf("%d",&no_of_element_in_vector1);
 	printf("\nEnter number of elements in second vector==>");
 	scanf("%d",&no_of_element_in_vector2);
 	
 	//computing the max size required and then declaring 2 arrays of max size
 	if (no_of_element_in_vector2 >= no_of_element_in_vector1)
 		no_of_element=no_of_element_in_vector2;
 	else
 		no_of_element=no_of_element_in_vector1;
 	
 	float vector_1[no_of_element],vector_2[no_of_element],scalar;
 	
 	//asking for the coefficients of the vectors
	printf("\nEnter the coefficients of first vector \n");
	input(vector_1,no_of_element_in_vector1);
	printf("\nEnter the coefficients of second vector \n");
	input(vector_2,no_of_element_in_vector2); 	
 	
 	//assigning zero's to the blank memory spaces of smaller vector to make it's size 
 	//equal to lager vector 
 	if (no_of_element_in_vector2 > no_of_element_in_vector1)
 		assign_zeroes(vector_1,no_of_element,no_of_element_in_vector1);
 	else
 		assign_zeroes(vector_2,no_of_element,no_of_element_in_vector2);
 	
 	//sorting both of the arrays
 	bubble_sort(vector_1,no_of_element);
 	bubble_sort(vector_2,no_of_element);
 	//computing scalar product
 	scalar=scalar_product(vector_1,vector_2,no_of_element);

 	printf("Minimum Scalar Product is ==> %0.2f\n\n\n",scalar);
 	return 0;
 }

/*
   Variable description
   *array--pointer to the vector you gonna enter
   no_of_element-- size of the array  
 */
 void input(float *array,int no_of_element){
 	int i;
 	for ( i = 0; i < no_of_element; ++i)
 		scanf("%f", &array[i]);
 }

/*
	Variable description
    size-- max size of the array
	existing_no_of_elements-- no of elements already stored in array
 */
 void assign_zeroes(float *array,int size,int existing_no_of_elements){

 	int i;

 	for ( i = existing_no_of_elements; i < size; ++i)
 	{
 		array[i]=0;
 	}
 }

 void bubble_sort(float *array,int no_of_element){
    int i,j,k;
    
 	for(i=0;i<no_of_element;i++)
 	{
 		for ( j = 0; j < no_of_element-i-1; ++j)
 		{
 			if(array[j]>array[j+1])
 				swap(&array[j],&array[j+1]);
 		}
 			
 	}
 }

void swap(float *array1,float *array2){ 
	float temp;
    temp=*array1;
 	*array1=*array2;
 	*array2=temp;   
 }

/*
	Variable description
    scalar--scalar product of the two arrays
 */
 float scalar_product(float *array1, float *array2, int no_of_element){
 	float scalar=0;
 	int i;
 	for (i = 0; i < no_of_element; ++i)
 	{
 		scalar+= (array1[i])*(array2[no_of_element-1-i]);
 	}

 	return scalar;
 }
