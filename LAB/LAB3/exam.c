#include <stdio.h>
#include <ctype.h>

int main() {
    int num, i;
    scanf("%d", &num);
    double overall_score_list[num];
    double data_list_one[num] , data_list_two[num] , data_list_three[num];
    double aver_1 = 0, aver_2 = 0 , aver_3 = 0 , aver_overall = 0, data_one , data_two, data_three;
    for (i = 0 ; i < num ; i++) {
        scanf("%lf %lf %lf", &data_one, &data_two, &data_three);
        data_list_one[i] = data_one;
        data_list_two[i] = data_two;
        data_list_three[i] = data_three;
        overall_score_list[i] = (data_one + data_two + data_three);
        aver_overall += overall_score_list[i];

        aver_1+= data_one;
        aver_2+= data_two;
        aver_3+= data_three;

    }
    aver_overall = aver_overall/ num;
    aver_1 /= (double)num;
    aver_2 /= (double)num;
    aver_3 /= (double)num;

    // printf("%lf %lf %lf %lf\n" , aver_1, aver_2, aver_3, aver_overall);

    

    
    for (i = 0 ; i < num ; i++) {

        if (overall_score_list[i] >= aver_overall && data_list_one[i] > 0 && data_list_two[i] > 0 && data_list_three[i] > 0  ) {
            
            if (data_list_one[i] >= aver_1 && data_list_two[i] >= aver_2) {
                printf("%d", i+1);
                if (i != num -1) {
                printf(" ");
            }

            } else if (data_list_one[i] >= aver_1 &&  data_list_three[i] >= aver_3) {
                printf("%d", i+1);
                if (i != num -1) {
                printf(" ");
            }


            } else if (data_list_two[i] >= aver_2 && data_list_three[i] >= aver_3) {
                printf("%d", i+1);
                if (i != num -1) {
                printf(" ");
            }


            }

            
            

        }

    }
    


    
}



