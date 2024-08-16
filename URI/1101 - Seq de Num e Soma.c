#include <stdio.h>
#include <stdlib.h>

#define THROWS(condicao,msg)    if(!(condicao)){\
                                fprintf(stderr,"\n%s\n",msg);\
                                exit(1);}

int main()
{
	int val1 = 1, val2 = 1;

	while(val1 != 0 && val2 != 0)
	{
	 	int sum = 0, count = 0, j = 0, *pMemAlloc = NULL;
	    
		scanf("%d %d",&val1,&val2);
		
		if(val1 == 0 || val2 == 0)
		    break;
		    
		if (val2 > val1)
        {
            int temp = val2;
            val1 = val2;
            val2 = temp;
        }
		
		for(int i = val2 ; i <= val1 ; i++){
		    sum += i;
		    count++;
		}
	
	    THROWS(pMemAlloc = (int *) malloc((count + 1) * sizeof(int)), "Deu ruim!");
	
		for(int i = val2 ; i <= val1 ; i++)
		{
		    pMemAlloc[j] = i;
		    j++;
		}
        
        //printf("\n\nj:%d \t count:%d\n\n",j,count);
        
		pMemAlloc[j] = sum;
		
		for (int z = 0; z < count; z++) {
            printf("%d ",pMemAlloc[z]);
            if(z == count-1)
                printf("Sum=%d\n",pMemAlloc[j]);
        }
        
		free(pMemAlloc);
	}

	return 0;
}

/*

#include <stdio.h>

int main()
{
    int M, N;

    while (scanf("%d %d", &M, &N) != EOF)
    {
        if (M <= 0 || N <= 0)
        {
            break;
        }

        if (M > N)
        {
            int temp = M;
            M = N;
            N = temp;
        }

        int soma = 0;
        for (int i = M; i <= N; ++i)
        {
            printf("%d ", i);
            soma += i;
        }
        printf("Sum=%d\n", soma);
    }

    return 0;
}

*/