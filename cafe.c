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
    printf("1. shopping basket\n");                    // 장바구니
    printf("2. Add a drink\n");                        // 음료추가
    printf("3. Change a size of drink\n");             // ice/hot or size 변경
    printf("4. Delete a drink\n");                     // 음료삭제
    printf("5. Search for drinks in ordered list\n");  // 주문된 음료 중에서 검색
    printf("6. Search for drinks in menu\n");          // 메뉴판 음료 중에서 검색
    printf("7. Recommend for drinks\n");               // 음료 추천
    printf("8. Random recommendation\n");              // 음료 랜덤 추천
    printf("9. Quiz for discount!!!\n");               // 퀴즈를 통해서 할인해주는 event
    printf("0. Quit\n\n");                             // 주문 완료
    printf("=> What you want? ");
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

    printf("Enter the number of menu > ");
    scanf("%d", &d->drink);
    printf("Ice or Hot (1: ice, 2: hot)> ");
    scanf("%d", &d->ch);
    getchar();
    printf("Enter the size of drink(or bingsoo) (T: tall, G: Grande, V: venti)> ");
    scanf("%c", &d->size);

    total+=drink_price[d->drink-1];

    return 1;  
}
void infoDrink(Drink d){
    printf("    %15s          %d                 %c\n", drink_menu[d.drink-1], d.ch, d.size);
}
void listDrink(Drink *d, int cnt){
    printf("\n\n---------------- ordered list ----------------\n");

    printf("No       name        cold or hot(1 or 2)   size\n");
    // printf("==========================\n");
    for(int i = 0; i<cnt; i++){
        if(d[i].drink == -1) continue;
        printf("%d ", i+1);
        infoDrink(d[i]);
    }
    printf("\n");
    printf("The total price is %dwon.\n\n" , total);
}                 
int updateDrink(Drink *d){
    printf("Ice or Hot(1 or 2) > ");
    scanf("%d", &d->ch);
    printf("drink size (T: tall, G: grande, V: venti) > ");
    scanf(" %c", &d->size);

    return 1;
}                           
int deleteDrink(Drink *d){
    d->drink = -1;
    return 1;
}                       
void saveData(Drink *d, int cnt){
    FILE* fp;

    fp = fopen("drink.txt","wt");
    for(int i = 0; i<cnt; i++){
        if(d[i].drink == -1) continue;
        fprintf(fp, "%15s     %d     %c\n", drink_menu[d[i].drink-1],d[i].ch, d[i].size);
    }


    fclose(fp);
    printf("영수증이 저장되었습니다!\n");
}
int loadData(Drink *d){
    int cnt = 0;
    FILE* fp;
    char t[30];          
    fp = fopen("drink.txt","rt");

    if(fp == NULL)
        printf("No file.\n");
    else{
        for(int i = 0; i<100; i++){
            if(feof(fp)) break;
            fscanf(fp, "%s", t);      
            // printf("%s", t);   
            for(int i = 0; i<32; i++){
                if(strcmp(drink_menu[i], t)){
                    d[i].drink = i;
                    break;
                }
            }
            fscanf(fp, "%d", &d[i].ch);
            fscanf(fp, "%c", &d[i].size);

            cnt++;
        }
    }
    fclose(fp);
    return 1;
}             

int searchDrink(Drink *d, int cnt){
    int scnt = 0;
    char search[20];

    printf("What is the name of the drink > ");
    scanf("%s", search);

    printf("name       size\n");
    printf("=======================\n");
    for(int i = 0; i<cnt; i++){
        if(d[i].drink == -1) continue;
        if(strstr(drink_menu[d[i].drink-1], search)){
            printf("%s     %c\n", drink_menu[d[i].drink-1], d[i].size);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> No data\n");

    return scnt;
} 
int searchDrink_menu(Drink *d, int cnt){
    int order = 0;
    char search[20];
    

    printf("What is the name of the drink > ");
    scanf("%s", search);

    printf("name     price     \n");
    printf("=======================\n");
    for(int i = 0; i<32; i++){
        if(strstr(drink_menu[i], search)){
            printf("%s    %d\n", drink_menu[i], drink_price[i] );
            order++;
        }
    }
    if(order == 0) printf("=> No data!\n");
    else printf("\nThere are %ddata in total.\n", order);

    return order;
}

int selectDataNo(Drink *d, int cnt){
    int no;
    listDrink(d, cnt);
    printf("\nNumber (cancel :0)? ");
    scanf("%d", &no);

    return no;
}

int recomendDrink(){
    char answer;
    printf("날이 더우니 상큼한 과일 음료는 어떠신가요? \n");
    printf("입력(Y/N) : ");
    scanf(" %c", &answer);
    if(answer=='N'){
        printf("그러면 시원한 커피는 어떠세요? \n");
        printf("입력(Y/N) : ");
        scanf(" %c", &answer);
        if(answer=='N'){
            printf("그러면 시원하고 머리까지 시원해지는 빙수는 어떠세요? \n");
            printf("입력(Y/N) : ");
            scanf(" %c", &answer);
            if(answer=='N'){
                printf("저희 추천시스템의 범우 안에 있지 않아서 오늘의 추천 음료를 알려드립니다.");
                return 11; //청포도쿨러
            }
            else{
            printf("오늘은 무더운 더위를 머리 끝까지 시원하게 해주는 인절미 빙수를 추천드려요\n");
            return 28;
        }
        }
        else{
            printf("달달한 커피를 먹으며 하루를 달달하게 시작할 수 있는 카페모카를 추천드려요");
            return 10;
        }
    }
    else{
        printf("머리까지 띵 차가워지는 쿨러는 어떠세요?\n");
        printf("입력(Y/N) : ");
        scanf(" %c", &answer);
        if(answer=='N'){
            printf("얼음이 동동 내 기분도 동동 시원해지는 에이드 종류는 어떠세요?\n");
            printf("입력(Y/N) : ");
            scanf(" %c", &answer);
            if(answer=='N'){
                printf("오늘은 상콤달콜한 애플망고주스를 추천드려요\n");
                return 26; //애플망고 주스
            }
            else{
                printf("얼음과 함께 시원하고 기분도 동동 좋아지는 오렌지 에이드를 추천드려요\n");
                return 17; //오렌지 에이드
            }
        }
        else{
            printf("하루를 달달하고 시원하게 보낼 수 있는 복숭아 쿨러를 추천드려요\n");
            return 23;
        }
    }

}                              
void d_random(){
    int r;
    r = rand()%32;

    printf("\nHow about %s \n", drink_menu[r]);
  
}

void quiz(){
    int num,score=0;
    printf("\n1번     이사야가 활동하던 시기에 당시 남유다의 왕이 아닌 자는? /사1:1\n");
    printf("1) 요담\n");
    printf("2) 아하스\n");
    printf("3) 히스기야\n");
    printf("4) 므낫세\n");
    printf("정답: ");
    scanf("%d",&num);
    if(num==4){
        printf("\n정답입니다.\n");
        score+=1;
    }
    else printf("\n오답입니다.\n");
    printf(" \n");
    printf("2번     범죄로 인해 유다 백성에게 임한 하나님의 심판이 아닌 것은? /렘 14:12\n");
    printf("1) 지진\n");
    printf("2) 칼\n");
    printf("3) 기근\n");
    printf("4) 염병\n");
    printf("정답: ");
    scanf("%d",&num);
    if(num==1){
        printf("\n정답입니다.\n");
        score+=1;
    }
    else printf("오답입니다.\n");
    printf(" \n");
    printf("3번     에스겔이 본 끓는 가마는 무엇을 상징하는 비유인가? /겔 24;1-14\n");
    printf("1) 유다 백성들이 배불리 먹게 됨\n");
    printf("2) 화산 폭발\n");
    printf("3) 유다의 회복\n");
    printf("4) 바벨론의 침입과 유다의 멸망\n");
    printf("정답: ");
    scanf("%d",&num);
    if(num==4){
        printf("\n정답입니다.\n");
        score+=1;
    }
    else printf("오답입니다.\n");
    if(score==3) total-=500;
}                                       

