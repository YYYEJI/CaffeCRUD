#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int drink;         // 음료 index 
    int ch;            // cold or hot
    char size;         // 음료 size
} Drink;

int selectMenu();
int addDrink(Drink *d);                             // 이름, 가격 size 추가
void infoDrink(Drink d);                            // 한 상품 정보 출력 
void listDrink(Drink *d, int cnt);                  // 전체 상품 정보 출력 
int updateDrink(Drink *d);                          // 제품 정보 변경   
int deleteDrink(Drink *d);                          // 추가된 상품 삭제 
void saveData(Drink *d, int cnt);                   // 영수증 느낌 
int loadData(Drink *d);                             // 바로 직전에 구매된 상품 조회                           
int searchDrink(Drink *d, int cnt);                 // 추가된 제품 중에서 이름 검색  
int searchDrink_menu(Drink *d, int cnt);            // 메뉴 리스트 중에서 이름 검색
int selectDataNo(Drink *d, int cnt);                // 리스트에 담긴 제품 중 한 제품 선택 
int recomendDrink();                                // 음료 추천    
int d_random();                                     // 랜덤추천     
int quiz();                                         // 성경 관련 퀴즈 맞추면 할인   

    // printf("1. shopping basket\n");                    // 1.장바구니
    // printf("2. Add a drink\n");                        // 음료추가
    // printf("3. Change a size of drink\n");             // ice/hot or size 변경
    // printf("4. Delete a drink\n");                     // 음료삭제
    // printf("5. Search for drinks in ordered list\n");  // 주문된 음료 중에서 검색
    // printf("6. Search for drinks in menu\n");          // 메뉴판 음료 중에서 검색
    // printf("7. Recommend for drinks\n");               // 음료 추천
    // printf("8. Random recommendation\n");              // 음료 랜덤 추천
    // printf("9. Quiz for discount!!!\n");               // 퀴즈를 통해서 할인해주는 event
    // printf("10. Save the info of drink\n");            // 추가된 음료 정보 저장
    // printf("0. Quit\n\n");                             // 주문 완료