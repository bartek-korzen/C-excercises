#include <stdio.h>

int main()
{
    
    int sum_mat,sum_phy;
    float avg_mat,avg_phy;
    
    int grades [2][5] = {
        {2,3,1,5,6},
        {4,4,6,2,5}
        };
    
    
    for(int i = 0; i < 5; i++)
    {
        sum_mat += grades[0][i]; 
        sum_phy += grades[1][i]; 
    }
    
    avg_mat = (float)sum_mat/(float)5;
    avg_phy = (float)sum_phy/(float)5;
    
    printf("Średnia ocen z matematyki wynosi: %f, Średnia ocen z fizyki wynosi: %f", avg_mat, avg_phy);

    return 0;
}
