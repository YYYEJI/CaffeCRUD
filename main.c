#include "cafe.h"

int main(void){
    Drink d[20];
    int count = 0, menu, index = 0;
    count = loadData(d);

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0) listDrink(d, index);
            printf("\nThere are %d data in total.\n", count-1);
        }
        else if (menu == 2){
            count+=addDrink(&d[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(d, index);
            if(no == 0){
                printf("=> Cancel!\n");
                continue;
            }
            getchar();
            updateDrink(&d[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(d, index);
            if(no == 0){
                printf("=> Cancel!\n");
                continue;
            }
            int delok;
            printf("Are you sure you want to delete it? (cancel : 1)" );
            scanf("%d", &delok);
            if(delok == 1){
                if(deleteDrink(&d[no-1])) count--;
                printf("\n=> Deleted!\n");
            }
        }
        else if( menu == 5){
            int num = searchDrink(d, index);
            printf("\nThere are %ddata in total.\n\n", num);
        }
        else if( menu == 6) searchDrink_menu(d, index);
        else if( menu == 7) recomendDrink();
        else if( menu == 8) random();
        else if( menu == 9) quiz();   
        else if( menu == 10) saveData(d, index);                                                                      
    }
    printf("종료됨!\n");
    return 0;
}