/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>

int Answer;


void quickSort(int *arr, int left, int right) {
    int pivot, left_temp, right_temp;
    left_temp = left;
    right_temp = right;
    pivot = arr[left];
    while (left < right) {
        while (arr[right] >= pivot && (left < right)) {
            right--;
        }
        if (left != right) {
            arr[left] = arr[right];
        }
        while (arr[left] <= pivot && (left < right)) {
            left++;
        }
        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = left_temp;
    right = right_temp;
    if (left < pivot) quickSort(arr, left, pivot - 1);
    if (right > pivot) quickSort(arr, pivot + 1, right);
}

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	// setbuf(stdout, NULL);

	scanf("%d", &T);
    int num=0;
    int s=0;
    int sum=0;

	for(test_case = 0; test_case < T; test_case++)
	{

		scanf("%d %d", &num,&s);
        num=0; s=0, sum=0 ;
        Answer=0;
        int *numArray=(int*)malloc(sizeof(int)*num);
        for(int i=0;i<num;i++)
        {
            scanf("%d",&numArray[i] );
		}
        quickSort(numArray, 0, num - 1);

        for(int i=0;i<num;i++)
        {
            sum=sum+numArray[num-1-i];
            if(sum>s)
            {
                Answer=i;
                break;
            }


        }



        /////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}