#include "cafe.h"
char drink_menu[32][30] = {"콜드브루", "콜드브루라떼", "흑당라떼", "아메리카노", "카페라떼", "바닐라라떼", "시나몬라떼", "카라멜라떼", "아몬드라떼", "헤이즐넛라떼", "카페모카", 
                            "청포도쿨러", "망고쿨러", "자몽쿨러", "복숭아쿨러",
                            "청포도에이드", "자몽에이드", "오렌지에이드", "레몬에이드", "망고에이드", "패션후루츠에이드", "깔라만시에이드", "한라봉에이드",
                            "리얼딸기우유","생생자몽주스","한라봉주스","애플망고주스",
                            "팥빙수", "인절미빙수", "흑당빙수", "딸기빙수", "초코빙수" };
int drink_price[32] = {5000, 5800, 5800, 4000, 4800, 5800, 6000, 5800, 6200, 5800, 5200,
                        5800, 5800, 5800, 6000,
                        5800, 5800, 5800, 5800, 5800, 6000, 5800, 5800,
                        6200, 6200, 6800, 6500,
                        7800, 7800, 8900, 9800, 9800};

int total = 0;      // 총합계

int selectMenu(){
    int menu;
    printf("\n*** Caffe the Lord ***\n");
    printf("1. 장바구니\n");
    printf("2. 음료 추가\n");
    printf("3. 음료 사이즈 변경\n");
    printf("4. 음료 삭제\n");
    printf("5. 추가된 음료 저장\n");
    printf("6. 음료 검색\n");
    printf("7. 음료 추천\n");
    printf("8. 랜덤 추천\n");
    printf("9. 퀴즈\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();

    return menu;
}
int addDrink(Drink *d){ 
    for(int i = 0; i<32; i++){
        if(i == 0) printf("\n--- Coffee ---\n");
        else if(i == 11) printf("\n--- Cooler ---\n");
        else if(i == 15) printf("\n--- ade ---\n");
        else if(i == 23) printf("\n--- fruit ----\n");
        else if(i == 27) printf("\n--- bingsoo ---\n");
        printf("%d %s\n", i+1,drink_menu[i]);
    }     
    printf("\n");

    printf("음료의 번호 입력 > ");
    scanf("%d", &d->drink);
    getchar();
    printf("음료(or 빙수)의 사이즈 입력 (T: tall, G: Grande, V: venti)> ");
    scanf("%c", &d->size);

    total+=drink_price[d->drink-1];

    return 1;  
}
void infoDrink(Drink d){
    printf("    %15s     %c\n", drink_menu[d.drink-1], d.size);
}
void listDrink(Drink *d, int cnt){
    printf("\n\n------- ordered list -------\n");

    printf("No       name          sise\n");
    // printf("==========================\n");
    for(int i = 0; i<cnt; i++){
        if(d[i].drink == -1) continue;
        printf("%d ", i+1);
        infoDrink(d[i]);
    }
    printf("\n");
    printf("현재 총 가격은 %d입니다.\n\n" , total);
}                 
int updateDrink(Drink *d){
    printf("음료의 사이즈 변경 (T: tall, G: grande, V: venti) > ");
    scanf("%c", &d->size);

    return 1;
}                           
int deleteDrink(Drink *d){
    d->drink = -1;
    return 1;
}                       
void saveData(Drink *d, int cnt){

}
int loadData(Drink *d){

    return 1;
}             

int searchDrink(Drink *d, int cnt){
    int scnt = 0;
    return scnt;
}                
int selectDataNo(Drink *d, int cnt){
    int no;
    listDrink(d, cnt);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &no);

    return no;
}            
int recomendDrink(){
    int coffee;
    int cooler;
    int ade;
    int fruit;
    int bingsoo;
    int r = 0;          

    return r;
}                               
int random(){
    int r;     
    return r;
}
int quiz(){
    int discount = 0;
    return discount;
}                                        

