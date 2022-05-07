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
            printf("\n총 %d개의 리스트가 있습니다.\n", count-1);
        }
        else if (menu == 2){
            count+=addDrink(&d[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(d, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            getchar();
            updateDrink(&d[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(d, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)" );
            scanf("%d", &delok);
            if(delok == 1){
                if(deleteDrink(&d[no-1])) count--;
                printf("\n=> 삭제됨!\n");
            }
        }
        else if( menu == 5) saveData(d, index);
        else if( menu == 6){
            int num = searchDrink(d, index);
            printf("총 %d개의 주문이 있습니다.\n", num);
        }
        else if( menu == 7) recomendDrink();
        else if( menu == 8) random();
        else if( menu == 9) quiz();                                                                          
    }
    printf("종료됨!\n");
    return 0;
}